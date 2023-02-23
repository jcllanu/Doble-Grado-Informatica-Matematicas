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


entity registro_ps is
    port(rst,clk,load: in std_logic; 
        I:         in std_logic_vector(3 downto 0);
        O:                   out std_logic);
            
end registro_ps;

architecture struct of registro_ps is
component registro_paralelo_serie is
    port(rst,clk,load: in std_logic; 
         I, MemoriaI:         in std_logic_vector(3 downto 0);
         MemoriaO:            out std_logic_vector(3 downto 0);
         O:                   out std_logic);
            
end component;


   signal conector: std_logic_vector(3 downto 0);
begin
i_registro: registro_paralelo_serie
   port map(
    rst=>rst,
    clk=>clk,
    load=>load,
    MemoriaI=>conector,
    MemoriaO=>conector,
    I=>I,
    O=>O);

end architecture struct;
