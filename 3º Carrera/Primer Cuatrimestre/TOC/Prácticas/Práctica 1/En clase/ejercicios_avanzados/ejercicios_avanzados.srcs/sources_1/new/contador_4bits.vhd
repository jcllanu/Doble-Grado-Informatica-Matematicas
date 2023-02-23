library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity contador_4bits is
   port(rst,clk,adelante: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
end contador_4bits;

architecture rtl of contador_4bits is
    signal a_u, b_u: unsigned(3 downto 0);
    signal uno: std_logic_vector(3 downto 0);
begin
    process(clk,rst)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                O<="0000";
            elsif adelante = '1' then
                uno<="0001";
                a_u <= unsigned(I);
                b_u <= a_u + unsigned(uno);
                O <= std_logic_vector(b_u(3 downto 0));
            else
                uno<="0001";
                a_u <= unsigned(I);
                b_u <= a_u - unsigned(uno);
                O <= std_logic_vector(b_u(3 downto 0));
            end if;
         else
            O<=I;
         end if;
     end process; 
    
end rtl;