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


entity tb_contador is
end tb_contador;

architecture beh of tb_contador is

-- declaracion del componente que vamos a simular

  component contador is
    port(rst,clk,adelante: in std_logic; 
         O:            out std_logic_vector(3 downto 0));       
end component;

--entradas
  signal rst : std_logic;
  signal clk : std_logic;
  signal adelante : std_logic;
--salidas
  signal O : std_logic_vector(3 downto 0);
--se define el periodo de reloj 
  constant clk_period : time := 50 ns;

begin

  -- instanciacion de la unidad a simular 

  uut : contador port map (
    rst => rst,
    clk => clk,
    adelante => adelante,
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
    adelante <= '1';
    wait for 50 ns;
    rst <= '0';
    adelante <= '1';
    wait for 850 ns;
    rst <= '0';
    adelante <= '0';
    wait for 850 ns;
    rst <= '0';
    adelante <= '1';
    wait for 150 ns;
    adelante <= '0';
    wait for 50 ns;
    rst <= '0';
    adelante <= '1';
    wait;
  end process;

end beh;


