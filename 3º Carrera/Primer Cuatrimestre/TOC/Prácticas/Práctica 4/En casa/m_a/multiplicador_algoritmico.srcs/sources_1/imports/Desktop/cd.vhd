library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


--RUTA DE DATOS
entity cd is
  port (
    clk    : in std_logic;                      -- clock
    rst    : in std_logic;                      -- reset
    a_in   : in std_logic_vector(3 downto 0);    -- factor 1
    b_in   : in std_logic_vector(3 downto 0);    -- factor 2
    ctrl   : in std_logic_vector(7 downto 0);   -- Control
    status : out std_logic_vector(1 downto 0);  
    result : out std_logic_vector(7 downto 0));  -- Resultado
end entity cd;

architecture rtl of cd is
-------------------------------------------------------------
-- COMPONENETES
-------------------------------------------------------------
component mux_4bits_2op is
  port (
  cero:   in std_logic_vector(3 downto 0);
  uno:    in std_logic_vector(3 downto 0);
  op:     in std_logic;
  salida: out std_logic_vector(3 downto 0));
end component;

component mux_8bits_2op is
  port (
  cero:   in std_logic_vector(7 downto 0);
  uno:    in std_logic_vector(7 downto 0);
  op:     in std_logic;
  salida: out std_logic_vector(7 downto 0));
end component;

component adder8b is
    port( op1: in std_logic_vector(7 downto 0);
          op2: in std_logic_vector(7 downto 0);
          c: out std_logic_vector(7 downto 0) );
end component;

component restador4b is
    port( op1: in std_logic_vector(3 downto 0);
          op2: in std_logic_vector(3 downto 0);
          c: out std_logic_vector(3 downto 0) );
end component;
-------------------------------------------------------------
-- SENNALES
-------------------------------------------------------------

  signal a        : std_logic_vector (7 downto 0);
  signal a_in_8b  : std_logic_vector (7 downto 0);
  signal desp_a   : std_logic_vector (7 downto 0); -- Desplazado de a a la izq
  signal s_mux_a  : std_logic_vector (7 downto 0); -- Salida del mux_a
  
  signal b        : std_logic_vector (3 downto 0);
  signal desp_b   : std_logic_vector (3 downto 0); -- Desplazado de b a la der
  signal s_mux_b  : std_logic_vector (3 downto 0); -- Salida del mux_b
  
  signal n        : std_logic_vector (3 downto 0); 
  signal s_rest   : std_logic_vector (3 downto 0); -- Salida del restador
  signal s_mux_n  : std_logic_vector (3 downto 0); -- Salida del mux_n
 
  signal acc      : std_logic_vector (7 downto 0);
  signal s_sum    : std_logic_vector (7 downto 0); -- Salida del sumador
  signal s_mux_acc: std_logic_vector (7 downto 0); -- Salida del mux_acc

  -- SENNALES DE CONTROL
  signal a_mux        : std_logic;
  signal b_mux        : std_logic;
  signal n_mux        : std_logic;
  signal acc_mux      : std_logic;
  signal a_ld         : std_logic;
  signal b_ld         : std_logic;
  signal n_ld         : std_logic;
  signal acc_ld       : std_logic;


  -- SENNALES DE ESTADO
  signal n_es_cero: std_logic;
  signal b_es_uno : std_logic;
begin
 -----------------------------------------------------------------------------
  -- Internamente no trabajo con las componentes del vector ctrl y status sino que
  -- damos nombre a cada una de las componentes y trabajamos con ellas por
  -- separado. De esta forma es mucho más legible el codigo obtenido. Luego
  -- la componente status(0) la asigno a la senal n_es_zero y la componente
  -- status(1) la asigna la senal b_es_uno.
  -- Y lo mismo para el vector ctrl. La componente ctrl(0) se la asigno a a_ld,
  -- ctrl(1) a a_muz, ctrl(2) a b_ld y asi sucesivamente.
  -----------------------------------------------------------------------------
  
-------------------------------------------------------------
-- SENTENCIAS CONCURRENTES
-------------------------------------------------------------

  (a_ld, a_mux, b_ld,b_mux,acc_ld,acc_mux,n_ld,n_mux) <= ctrl;
  status <= (b_es_uno & n_es_cero);

   a_in_8b <= "0000" & a_in;
   desp_a  <= a(6 downto 0) & "0"; --Desplazar a a la izq
   desp_b  <= "0" & b(3 downto 1) ; --Desplazar b a la der
   b_es_uno <= b(0);
   result <= acc;
-------------------------------------------------------------
-- MUXES
-------------------------------------------------------------
mux_a: mux_8bits_2op port map(
    cero   => a_in_8b,
    uno    => desp_a,
    op     => a_mux,
    salida => s_mux_a
    );
    
mux_b: mux_4bits_2op port map(
    cero   => b_in,
    uno    => desp_b,
    op     => b_mux,
    salida => s_mux_b
    );
    
mux_n: mux_4bits_2op port map(
    cero   => "1000",
    uno    => s_rest,
    op     => n_mux,
    salida => s_mux_n
    );
    
mux_acc: mux_8bits_2op port map(
    cero   => "00000000",
    uno    => s_sum,
    op     => acc_mux,
    salida => s_mux_acc
    );
    
-------------------------------------------------------------
-- REGISTROS
-------------------------------------------------------------
reg_a: process (rst, clk) is
begin
    if rst = '0' then
        a <= "00000000";
    else
        if rising_edge(clk) then
            if a_ld = '1' then
                a <= s_mux_a;
                end if;
        end if;
    end if;        
end process reg_a;

reg_b: process (rst, clk) is
begin
    if rst = '0' then
        b <= "0000";
    else
        if rising_edge(clk) then
            if b_ld = '1' then
                b <= s_mux_b;
                end if;
        end if;
    end if;        
end process reg_b;

reg_n: process (rst, clk) is
begin
    if rst = '0' then
        n <= "0000";
    else
        if rising_edge(clk) then
            if n_ld = '1' then
                n <= s_mux_n;
                end if;
        end if;
    end if;        
end process reg_n;

reg_acc: process (rst, clk) is
begin
    if rst = '0' then
        acc <= "00000000";
    else
        if rising_edge(clk) then
            if acc_ld = '1' then
                acc <= s_mux_acc;
                end if;
        end if;
    end if;        
end process reg_acc;

-------------------------------------------------------------
-- SUMADOR
-------------------------------------------------------------
sumador: adder8b port map(
    op1 => a,
    op2 => acc,
    c => s_sum);

-------------------------------------------------------------
-- RESTADOR
-------------------------------------------------------------
restador: restador4b port map(
    op1 => n,
    op2 => "0001",
    c   => s_rest);  
      
-------------------------------------------------------------
-- COMPARADOR
-------------------------------------------------------------
comp: process (n) is
begin
    if n="0000" then
        n_es_cero <= '1';
    else   
        n_es_cero <= '0';
    end if;
end process comp;
end architecture rtl;
