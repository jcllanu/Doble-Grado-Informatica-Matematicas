library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity divisor is
    port (
    rst         : in std_logic;
    clk_100mhz  : in std_logic;
    clk_frec0   : out std_logic; --Algo más de un hercio
    clk_frec1   : out std_logic; --Frecuencia del contador 1
    clk_frec2   : out std_logic  --Frecuencia del contador 2
    );
end divisor;

architecture Behavioral of divisor is
    signal cntr_reg    : unsigned(22 downto 0);
    signal cntr_reg_f1 : unsigned(20 downto 0);
    signal cntr_reg_f2 : unsigned(18 downto 0);
    signal clk_1hz_reg : std_logic;
    signal clk_f1_reg  : std_logic;
    signal clk_f2_reg  : std_logic;
    signal tope_f1     : unsigned(20 downto 0);
    signal tope_f2     : unsigned(18 downto 0);
    
begin
    tope_f1<=(0=>'0', others=>'1');
    tope_f2<=(0=>'0', others=>'1');
    clk_frec0<=clk_1hz_reg;
    clk_frec1<=clk_f1_reg;
    clk_frec2<=clk_f2_reg;
    p_cntr: process(rst, clk_100mhz) is
    begin
    
    if rst='1' then
        clk_1hz_reg<='0';
        clk_f1_reg<='0';
        clk_f2_reg<='0';
        cntr_reg<=(others=>'0');
        cntr_reg_f1<=(others=>'0');
        cntr_reg_f2<=(others=>'0');
    elsif rising_edge(clk_100mhz) then
        if cntr_reg = (22 downto 0 =>'1') then
            cntr_reg<=(others=>'0');
            clk_1hz_reg<=not(clk_1hz_reg);
        else
            cntr_reg <= cntr_reg+1;
            clk_1hz_reg<=clk_1hz_reg;
        end if;
        
        if cntr_reg_f1 = tope_f1 then
            cntr_reg_f1<=(others=>'0');
            clk_f1_reg<=not(clk_f1_reg);
        else
            cntr_reg_f1 <= cntr_reg_f1+1;
            clk_f1_reg<=clk_f1_reg;
        end if;
        
         if cntr_reg_f2 = tope_f2 then
            cntr_reg_f2<=(others=>'0');
            clk_f2_reg<=not(clk_f2_reg);
        else
            cntr_reg_f2 <= cntr_reg_f2+1;
            clk_f2_reg<=clk_f2_reg;
        end if;
    end if;
    end process p_cntr;
end Behavioral;
