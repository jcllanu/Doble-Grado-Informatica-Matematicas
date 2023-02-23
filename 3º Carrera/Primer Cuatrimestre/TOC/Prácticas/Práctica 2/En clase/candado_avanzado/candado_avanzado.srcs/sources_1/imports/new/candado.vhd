library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity candado_comp is
    port(
    IR: in std_logic_vector(3 downto 0);
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    O : out std_logic_vector(7 downto 0);
    seg: out std_logic_vector(6 downto 0));
end candado_comp;

architecture estructura_comp of candado_comp is

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
component candado is
    port(
    Irestantes: in std_logic_vector(3 downto 0);
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    O : out std_logic_vector(7 downto 0);
    seg: out std_logic_vector(3 downto 0));
end component;


signal s_boton: std_logic;
signal s_display7: std_logic_vector(3 downto 0);


begin

i_conv_7seg: conv_7seg
    port map(
    display=>seg,
    x=>s_display7
    );
i_debouncer: debouncer
    port map(
    rst=>rst,
    clk=>clk,
    x=>btnC,
    xDebFallingEdge=>s_boton
    );
i_candado: candado
    port map(
    Irestantes=>IR,
    I=>I,
    btnC=>s_boton,
    clk=>clk,
    rst =>rst,
    O =>O,
    seg=>s_display7
    );

end estructura_comp;