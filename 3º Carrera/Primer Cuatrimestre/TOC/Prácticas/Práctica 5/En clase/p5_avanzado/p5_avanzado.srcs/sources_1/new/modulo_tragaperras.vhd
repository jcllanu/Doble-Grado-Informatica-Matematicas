
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tragaperras is
port (clk   : in  std_logic;
        rst : in  std_logic;
        ini : in  std_logic;
        fin : in  std_logic;
        mod_mem: in std_logic;
        din: in std_logic_vector(3 downto 0);
        salida_mem: out std_logic_vector(3 downto 0);
        led:  out std_logic_vector(9 downto 0);
        seg : out  STD_LOGIC_VECTOR (6 downto 0);
        an : out  std_logic_vector (3 downto 0)
        );
end tragaperras;

architecture estructura of tragaperras is

  --RUTA DE DATOS
component cd is
  port (
    rst       : in std_logic;
    clk       : in std_logic;
    ctrl      : in std_logic_vector(4 downto 0);   -- Sennales de control
    din       : in std_logic_vector(3 downto 0);
    salida_mem: out std_logic_vector(3 downto 0);
    status    : out std_logic_vector(2 downto 0);  -- Sennales de estado
    digito_1  : out std_logic_vector(3 downto 0);  -- Salida de la ruta de datos que ataca a la entrada al digito 1 del conversor de 7 seg
    digito_2  : out std_logic_vector(3 downto 0);  -- Salida de la ruta de datos que ataca a la entrada al digito 1 del conversor de 7 seg
    leds      : out std_logic_vector(9 downto 0) -- Salida de leds
   ); 
end component;
  
--UNIDAD DE CONTROL
component uc is
    port (
      clk    : in  std_logic;                      -- clock
      rst    : in  std_logic;                      -- reset
      ini    : in  std_logic;                      -- External control signal
      fin    : in  std_logic;                      -- External control signal
      mod_mem: in  std_logic;                      -- External control signal
      ctrl   : out std_logic_vector(4 downto 0);   -- Control vector
      status : in  std_logic_vector(2 downto 0));   -- Status vector
  end component;
  
--DEBOUNCER
component debouncer is
  port (
    rst             : in  std_logic;
    clk             : in  std_logic;
    x               : in  std_logic;
    xDeb            : out std_logic;
    xDebFallingEdge : out std_logic;
    xDebRisingEdge  : out std_logic
    );
end component;

--DISPLAYS
component displays is
    Port ( 
        rst : in STD_LOGIC;
        clk : in STD_LOGIC;       
        digito_0 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_1 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_2 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_3 : in  STD_LOGIC_VECTOR (3 downto 0);
        display : out  STD_LOGIC_VECTOR (6 downto 0);
        display_enable : out  STD_LOGIC_VECTOR (3 downto 0)
     );
 end component;
     
 --SENNALES
  signal ctrl    : std_logic_vector(4 downto 0);  -- Control vector
  signal status  : std_logic_vector(2 downto 0);  --Status vector
  signal digito_1: std_logic_vector(3 downto 0); --Primer digito
  signal digito_2: std_logic_vector(3 downto 0); --Primer digito
  signal leds    : std_logic_vector(9 downto 0); --Primer digito
  signal ini_debounceado : std_logic;
  signal fin_debounceado : std_logic;
  
begin
led<=leds;
i_cd : cd port map (
    clk => clk,
    rst => rst,
    ctrl => ctrl,
    din=>din,
    salida_mem=>salida_mem,
    status => status,
    digito_1 => digito_1,
    digito_2 => digito_2,
    leds => leds
);
    
i_uc : uc port map (
    clk    => clk,
    rst    => rst,
    ini    => ini_debounceado,
    fin    => fin_debounceado,
    mod_mem => mod_mem,
    ctrl   => ctrl,
    status => status
 );
 
deb_ini: debouncer port map(
    rst => rst,
    clk => clk,
    x   => ini,
    xDebFallingEdge => ini_debounceado
);

deb_fin: debouncer port map(
    rst => rst,
    clk => clk,
    x   => fin,
    xDebFallingEdge => fin_debounceado
);

disp: displays port map(
        rst => rst,
        clk => clk,     
        digito_0 => digito_1,
        digito_1 => digito_2,
        digito_2 => "0000",
        digito_3 => "0000",
        display => seg,
        display_enable=> an);
end estructura;
