----------------------------------------------------------------------------------
-- Company:        Universidad Complutense de Madrid
-- Engineer:       
-- 
-- Create Date:    
-- Design Name:    Practica 1b
-- Module Name:    tb_registro_siso - rtl 
-- Project Name:   Practica 1b
-- Target Devices: Spartan-3 
-- Tool versions:  ISE 14.1
-- Description:    Testbench registro SISO 
-- Dependencies: 
-- Revision: 
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_textio.all;
use std.textio.all;


entity tb_registro is
end tb_registro;

architecture beh of tb_registro is

-- declaracion del componente que vamos a simular

  component registro_paralelo is
    port(rst,clk,load: in std_logic; 
         I:            in std_logic_vector(3 downto 0);
         O:            out std_logic_vector(3 downto 0));
            
end component;

--entradas
  signal rst : std_logic;
  signal clk : std_logic;
  signal I  : std_logic_vector(3 downto 0);
  signal load  : std_logic;
--salidas
  signal O : std_logic_vector(3 downto 0);

--se define el periodo de reloj 
  constant clk_period : time := 50 ns;

begin

  -- instanciacion de la unidad a simular 

  uut : registro_paralelo port map (
    rst => rst,
    clk => clk,
    load => load,
    I => I,
    O  => O
    );

  -- definicion del process de reloj
  p_reloj : process
  begin
    clk <= '0';
    wait for clk_period/2;
    clk <= '1';
    wait for clk_period/2;
  end process;


  --proceso de estimulos
  p_stim : process
  begin
    -- se mantiene el rst activado durante 50 ns.
    rst <= '1';
    I  <= "0000";
    wait for 50 ns;
    rst <= '0';
    I  <= "0001";
    load <= '1';
    wait for 50 ns;
    rst <= '0';
    I  <= "1000";
    load <= '0';
    wait for 50 ns;
    rst <= '0';
    I  <= "0000";
    load <= '0';
    wait for 50 ns;
    rst <= '0';
    I  <= "1111";
    load <= '1';
    wait for 50 ns;
    rst <= '0';
    I  <= "1101";
    load <= '0';
    wait for 50 ns;
    rst <= '0';
    I  <= "1001";
    load <= '1';
    wait for 50 ns;
    rst <= '0';
    I  <= "1110";
    load <= '0';
    wait for 50 ns;
    rst <= '0';
    I  <= "1111";
    load <= '1';
    wait for 50 ns;
    rst <= '0';
    I  <= "0001";
    load <= '1';
    wait for 50 ns;
    rst <= '1';
    I  <= "0011";
    load <= '1';
    wait;
  end process;

end beh;


