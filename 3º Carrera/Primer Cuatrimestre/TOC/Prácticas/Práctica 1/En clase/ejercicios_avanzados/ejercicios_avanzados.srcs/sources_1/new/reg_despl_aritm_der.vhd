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


entity registro_desplazamiento_aritm_der is
    port(rst,clk,load: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
            
end registro_desplazamiento_aritm_der;

architecture circuito of registro_desplazamiento_aritm_der is

begin
    process(clk,rst)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                O<=(others=>'0');
            elsif load = '1' then
            --El bit de la derecha se pierde y el bit del signo anterior se conserva en el resultado
                O(3)<=I(3);
                O(2)<=I(3);
                O(1)<=I(2);
                O(0)<=I(1);
             
            end if;
         end if;
     end process; 

end circuito;
