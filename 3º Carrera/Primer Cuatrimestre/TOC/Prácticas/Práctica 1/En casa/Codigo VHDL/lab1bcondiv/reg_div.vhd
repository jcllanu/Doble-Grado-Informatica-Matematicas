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


entity registro_paralelo_divisor is
    port(rst,clk,load: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
            
end registro_paralelo_divisor;

architecture struct of registro_paralelo_divisor is
component registro_paralelo is
    port(rst,clk,load: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
            
end component;
component divisor is
  port (
    rst        : in  std_logic;         -- asynch reset
    clk_100mhz : in  std_logic;         -- 100 MHz input clock
    clk_1hz    : out std_logic          -- 1 Hz output clock
    );
end component;

   signal clk1hz_a_clk: std_logic;
begin
i_registro: registro_paralelo
   port map(
    rst=>rst,
    clk=>clk1hz_a_clk,
    load=>load,
    I=>I,
    O=>O);
i_divisor: divisor
    port map(
        rst=>rst,
        clk_100mhz=>clk,
        clk_1hz=>clk1hz_a_clk);

end architecture struct;
