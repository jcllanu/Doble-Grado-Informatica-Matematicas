library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity componente_candado is
    port(
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    reset : in std_logic;
    O : out std_logic;
    seg: out std_logic_vector(6 downto 0));
end componente_candado;

architecture estructura_comp of componente_candado is
    
component candado is
    port(
    clave: in std_logic_vector(7 downto 0);
    boton: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    abierto : out std_logic;
    intentos_restantes: out std_logic_vector(3 downto 0));
end component;

component conv_7seg is
  port (x       : in  std_logic_vector (3 downto 0);
        display : out std_logic_vector (6 downto 0));
end component;

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

signal display7: std_logic_vector(3 downto 0);
signal s_boton: std_logic;
signal s_reset: std_logic;
begin
i_candado: candado
    port map(
    clave=>I,
    boton=>s_boton, --Boton
    clk =>clk,
    rst =>s_reset,
    abierto=>O,
    intentos_restantes=>display7
    );
i_conv_7seg: conv_7seg
    port map(
    x=>display7,
    display=>seg
    );
i_debouncer_boton: debouncer
    port map(
    rst=>s_reset,
    clk=>clk,
    x=>btnC,
    xDebRisingEdge=>s_boton
    );
i_debouncer_reset: debouncer
    port map(
    rst=>s_reset,
    clk=>clk,
    x=>reset,
    xDebRisingEdge=>s_reset
    );
end estructura_comp;