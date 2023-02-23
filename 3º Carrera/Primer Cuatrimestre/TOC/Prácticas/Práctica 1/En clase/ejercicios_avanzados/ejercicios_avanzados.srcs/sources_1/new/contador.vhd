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


entity contador is
    port(rst,clk,adelante: in std_logic; 
         O:            out std_logic_vector(3 downto 0));
            
end contador;

architecture struct of contador is
component contador_4bits is
   port(rst,clk,adelante: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
end component;


   signal conector: std_logic_vector(3 downto 0);
begin
i_registro: contador_4bits
   port map(
    rst=>rst,
    clk=>clk,
    I=>conector,
    O=>conector,
    adelante=>adelante);
salida: O<=conector;
end architecture struct;
