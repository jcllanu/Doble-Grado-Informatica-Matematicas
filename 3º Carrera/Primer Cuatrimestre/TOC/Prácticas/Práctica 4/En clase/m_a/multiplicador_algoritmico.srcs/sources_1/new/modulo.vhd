library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity modulo is
generic(width: natural:=4);
port (clk   : in  std_logic;
        rst : in  std_logic;
        init : in  std_logic;
        a_in  : in  std_logic_vector((width -1) downto 0);  -- factor 1
        b_in  : in  std_logic_vector((width -1) downto 0);  -- factor 2
        led : out std_logic_vector(7 downto 0);
        seg : out  STD_LOGIC_VECTOR (6 downto 0);
        an : out  std_logic_vector (3 downto 0);
        digito_mostrar: in std_logic
        );
end modulo;

architecture Behavioral of modulo is

component multiplicador is
generic(width: natural);
port (clk   : in  std_logic;
        rst : in  std_logic;
        init : in  std_logic;
        a_in  : in  std_logic_vector((width -1) downto 0);  -- factor 1
        b_in  : in  std_logic_vector((width -1) downto 0);  -- factor 2
        done : out std_logic;
        resultado:  out std_logic_vector(2*width -1 downto 0)--resultado
        );
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
signal init_debounceado: std_logic;
signal done_1bit: std_logic;
signal resul: std_logic_vector(2*width -1 downto 0);
signal digito: std_logic_vector(3 downto 0);

begin

    led <= (others=>done_1bit);
  
  reg_digito: process(clk,rst) is
  begin
    if rst='0' then
        digito<="0000";
    else
        if rising_edge(clk) then
            if digito_mostrar='0' then
                digito <= resul(3 downto 0);
            else
                 digito <= resul(7 downto 4);
            end if;
        else
        
        end if;
    end if;
   end process reg_digito;
    
mult: multiplicador
    generic map(
    width=>width)
    port map(
    clk => clk,
    rst => rst,
    init => init_debounceado,
    a_in => a_in,
    b_in => b_in,
    done => done_1bit,
    resultado=> resul);
    
deb: debouncer port map(
    rst => rst,
    clk => clk,
    x   => init,
    xDebFallingEdge => init_debounceado);
    
disp: displays port map(
        rst => rst,
        clk => clk,     
        digito_0 => digito,
        digito_1 => "0000",
        digito_2 => "0000",
        digito_3 => "0000",
        display => seg,
        display_enable=> an);
end Behavioral;
