----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.10.2020 13:38:33
-- Design Name: 
-- Module Name: register - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity registro_paralelo_serie is
    port(rst,clk,load: in std_logic; 
         I, MemoriaI:         in std_logic_vector(3 downto 0);
         MemoriaO:            out std_logic_vector(3 downto 0);
         O:                   out std_logic);
            
end registro_paralelo_serie;

architecture struct of registro_paralelo_serie is
begin
 process(clk,rst)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                O<='0';
                MemoriaO<="0000";
            elsif load = '1' then
                O<=I(3);
                MemoriaO(0)<='0';
                MemoriaO(1)<=I(0);
                MemoriaO(2)<=I(1);
                MemoriaO(3)<=I(2);
            else
                O<=MemoriaI(3);
                MemoriaO(0)<='0';
                MemoriaO(1)<=MemoriaI(0);
                MemoriaO(2)<=MemoriaI(1);
                MemoriaO(3)<=MemoriaI(2);
            end if;
         end if;
     end process; 

end architecture struct;
