library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


--RUTA DE DATOS
entity cd is
  port (
    rst       : in std_logic;
    clk       : in std_logic;
    ctrl      : in std_logic_vector(3 downto 0);   -- Sennales de control
    status    : out std_logic_vector(1 downto 0);  -- Sennales de estado
    digito_1  : out std_logic_vector(3 downto 0);  -- Salida de la ruta de datos que ataca a la entrada al digito 1 del conversor de 7 seg
    digito_2  : out std_logic_vector(3 downto 0);  -- Salida de la ruta de datos que ataca a la entrada al digito 1 del conversor de 7 seg
    leds      : out std_logic_vector(9 downto 0)); -- Salida de leds
end entity cd;

architecture rtl of cd is
-------------------------------------------------------------
-- COMPONENETES
-------------------------------------------------------------
COMPONENT memoria1
  PORT (
    clka : IN STD_LOGIC;
    wea : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    addra : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    dina : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    douta : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
  );
END COMPONENT;

COMPONENT memoria2
  PORT (
    clka : IN STD_LOGIC;
    wea : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    addra : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    dina : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    douta : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
  );
END COMPONENT;

component divisor is
  port (
    rst         : in  std_logic;         -- asynch reset
    clk_100mhz  : in  std_logic;         -- 100 MHz input clock
    clk_frec0   : out std_logic;         --Algo m·s de un hercio
    clk_frec1   : out std_logic;         --Frecuencia del contador 1
    clk_frec2   : out std_logic          --Frecuencia del contador 2
    );
end component;
-------------------------------------------------------------
-- SENNALES
-------------------------------------------------------------
  subtype contador_t is integer range 0 to 9;
  signal count1, count2: contador_t;
  
  -- SENNALES DE CONTROL
  signal ctr_dig        : std_logic;--Sennal de control de los mux asociados a los digito: si 
  --esta sennal esta a uno la salida de los digitos es lo que hay en la salida de las memorias .
  -- Si esta a 0 la salida es 0
  signal ctr_count_en   : std_logic;--Sennal de control del enable do los contadores: si 
  --esta sennal esta a uno ambos reciben en su chipo enable frec1 y frec2. Si esta a 0 no cuenta ninguno
  signal ctr_leds1      : std_logic;
  signal ctr_leds2      : std_logic; --Controlan la salida de los leds
  
  -- SENNALES DE RELOJ
  
  signal clk_frec_0  : std_logic; --Sennal de reloj a algo m·s de 1 Hz
  signal clk_frec_1: std_logic; --Sennal de reloj que ataca al chip enable del contador 1 (Hz)
  signal clk_frec_2: std_logic; --Sennal de reloj que ataca al chip enable del contador 2 (Hz)
  
  -- SALIDAS COMPONENTES
  signal dig1     : std_logic_vector(3 downto 0);--salida del mux que ataca al display del digito 1
  signal dig2     : std_logic_vector(3 downto 0);--salida del mux que ataca al display del digito 2
  signal counter1 : std_logic_vector(3 downto 0);--Salida del contador 1
  signal counter2 : std_logic_vector(3 downto 0);--Salida del contador 2
  signal mem1     : std_logic_vector(3 downto 0);--Salida de la memoria 1
  signal mem2     : std_logic_vector(3 downto 0);--Salida de la memoria 2
  signal count1_enable: std_logic; --Salida del mux que elige entre clk_frec1 y 0 que ataca al chip enable del contador 1
  signal count2_enable: std_logic; --Salida del mux que elige entre clk_frec2 y 0 que ataca al chip enable del contador 2
  signal leds_int : std_logic_vector(9 downto 0);--Sennal interna de los leds (salida del generador de secuencias)
  
  signal num_ciclos: integer; 
  signal cero      : std_logic_vector(0 downto 0); --Constante 0 utilizada para leer siempre de las memorias
  signal cero_write: std_logic_vector(3 downto 0); --Constante 0 utilizada para escribir siempre 0 en las memorias
   
  -- SENNALES DE ESTADO
  signal iguales        : std_logic;--Indica si mux1=mux2
  signal sec_terminada  : std_logic;--Indica si la secuencia de victoria/derrota ha terminado
begin
 -----------------------------------------------------------------------------
  -- Internamente no trabajo con las componentes del vector ctrl y status sino que
  -- damos nombre a cada una de las componentes y trabajamos con ellas por
  -- separado. De esta forma es mucho m√°s legible el codigo obtenido. Luego
  --  a status la asigno a la senal iguales y sec_terminada.
  -- Y lo mismo para el vector ctrl. La componente ctrl(0) se la asigno a a_ld,
  -- ctrl(1) a a_muz, ctrl(2) a b_ld y asi sucesivamente.
  --Y lo mismo para el vector ctrl. La componente ctrl(0) se la asigno a d1_mux,
  -- ctrl(1) a d2_mux.
  -----------------------------------------------------------------------------
  
-------------------------------------------------------------
-- SENTENCIAS CONCURRENTES
-------------------------------------------------------------
  (ctr_dig, ctr_count_en,ctr_leds1,ctr_leds2) <= ctrl;
  status <= (iguales,sec_terminada);
  digito_1 <= dig1;
  digito_2 <= dig2;
  cero <= (others=>'0');
  cero_write <= (others=>'0');
  leds<=leds_int;
  
-------------------------------------------------------------
-- DIVISOR
-------------------------------------------------------------
divisor_frec : divisor
  PORT MAP (
    rst=>rst,
    clk_100mhz =>clk,
    clk_frec0=> clk_frec_0,
    clk_frec1 => clk_frec_1,
    clk_frec2=> clk_frec_2
  );

-------------------------------------------------------------
-- CONTADORES MOD 10
-------------------------------------------------------------

p_count1: process(clk, rst)
begin
  if rst = '1' then
    count1 <= 0;
  elsif rising_edge(clk) then
    if count1_enable = '1' then
      count1 <= count1 +1;
    end if;
  end if;
end process p_count1;
counter1 <= std_logic_vector(to_unsigned(count1, 4));

p_count2: process(clk, rst)
begin
  if rst = '1' then
    count2 <= 0;
  elsif rising_edge(clk) then
    if count2_enable = '1' then
      count2 <= count2 +1;
    end if;
  end if;
end process p_count2;
counter2 <= std_logic_vector(to_unsigned(count2, 4));


-------------------------------------------------------------
-- COMPARADORES
-------------------------------------------------------------
comp1: process (dig1,dig2) is
begin
    if dig1=dig2 then
        iguales<='1';
    else   
        iguales<='0';
    end if;
end process comp1;

comp2: process (num_ciclos) is
begin
    if num_ciclos=10 then
        sec_terminada<='1';
    else   
        sec_terminada<='0';
    end if;
end process comp2;
-------------------------------------------------------------
-- MUXES
-------------------------------------------------------------
  dig: process (mem1,mem2,ctr_dig) is
begin
    if ctr_dig='1' then
        dig1 <= mem1;
        dig2 <= mem2;
    else   
        dig1 <= (others=>'0');
        dig2 <= (others=>'0');
    end if;
end process dig;

  count_en: process (clk_frec_1,clk_frec_2, ctr_count_en) is
begin
    if ctr_count_en='1' then
        count1_enable <= clk_frec_1;
        count2_enable <= clk_frec_2;
    else   
        count1_enable <= '0';
        count2_enable <= '0';
    end if;
end process count_en;
-------------------------------------------------------------
-- MEMORIAS
-------------------------------------------------------------
mi_memoria_1 : memoria1
  PORT MAP (
    clka => clk,
    wea => cero,
    addra => counter1,
    dina => cero_write,
    douta => mem1
  );
  mi_memoria_2 : memoria2
  PORT MAP (
    clka => clk,
    wea => cero,
    addra => counter2,
    dina => cero_write,
    douta => mem2
  );
-------------------------------------------------------------
-- GENERADOR DE SECUENCIAS
-------------------------------------------------------------

gen_sec: process (clk_frec_0,rst) is
begin
    if rst = '1' then
        leds_int <= (others=>'0');
        num_ciclos <= 0;
    elsif rising_edge(clk_frec_0) then
        if ctr_leds1='0' then
           if ctr_leds2='0' then --00 ->Salida leds =00...00
                leds_int <= (others=>'0');
                num_ciclos <= 0;
           else --01  ->Salida leds = atraer
                if num_ciclos=10 then
                    num_ciclos <= 0;
                    leds_int <= (others=>'0');
                else
                    leds_int<=not(leds_int(0))&leds_int(9 downto 1);
                end if;
           end if;
        else   
           if ctr_leds2='0' then --10 ->Salida leds = derrota
                if num_ciclos=0 then
                    leds_int<="0101010101";
                    num_ciclos <= 1;
                else
                    leds_int<=not(leds_int);
                    num_ciclos <= num_ciclos+1;
                end if;   
           else --11 ->Salida leds = victoria
                if num_ciclos=0 then
                    leds_int<=(others=>'0');
                    num_ciclos <= 1;
                else
                    leds_int<=not(leds_int);
                    num_ciclos <= num_ciclos+1;
                end if;   
           end if;
        end if;
    end if;
end process gen_sec;


end architecture rtl;
