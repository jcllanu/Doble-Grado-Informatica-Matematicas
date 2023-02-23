----------------------------------------------------------------------------------
-- Company:        Universidad Complutense de Madrid
-- Engineer:       
-- 
-- Create Date:    
-- Design Name:    Practica 1b
-- Module Name:    tb_registro_pipo - rtl 
-- Project Name:   Practica 1b
-- Target Devices: Basys-3 
-- Tool versions:  Vivado 2019.1
-- Description:    Testbench registro PIPO 
-- Dependencies: 
-- Revision: 
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_textio.all;
use std.textio.all;


entity tb_candado is
end tb_candado;

architecture beh of tb_candado is

-- declaracion del componente que vamos a simular

component candado is
    port(
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    O : out std_logic;
    seg: out std_logic_vector(6 downto 0));
end component;

--entradas
  signal rst  : std_logic;
  signal clk  : std_logic;
  signal clave : std_logic_vector(7 downto 0);
  signal boton : std_logic;

--salidas
  signal abierto : std_logic;
  signal intentos_restantes: std_logic_vector(6 downto 0);

--se define el periodo de reloj 
  constant clk_period : time := 50 ns;

begin

  -- instanciacion de la unidad a simular 
  dut : candado port map (
    rst  => rst,
    clk  => clk,
    I => clave,
    btnC => boton,
    O=> abierto,
    seg=>intentos_restantes
    );

  -- definicion del process de reloj
  p_clk : process
  begin
    clk <= '0';
    wait for clk_period/2;
    clk <= '1';
    wait for clk_period/2;
  end process p_clk;


  --proceso de estimulos
  p_stim : process
  begin
    -- se mantiene el rst activado durante 50 ns.
    rst  <= '1';
    clave <="00000000";
    boton <= '0';
    wait for 40 ns;
    wait for 50 ns;
    rst  <= '0';
    wait for 50 ns;
    clave <="00000001";
    boton <= '0';
    wait for 50 ns;
    clave <="00000010";
    wait for 10 ns;
    boton <= '1';
    wait for 10 ns;
    boton <= '0';
    wait for 50 ns;
    boton <= '0';
    clave <="00000110";
    wait for 50 ns;    
    boton <= '1';
    clave <="00000000";
    wait for 50 ns;    --Se guarda el numero
    clave <="00000001";             
    wait for 50 ns;    -- Primer error
    clave <="00000010";
    wait for 50 ns;    -- Segundo error
    clave <="00000000";
    boton <= '0';
    wait for 50 ns;
    clave <="00000000";
    boton <= '0';
    wait for 50 ns;
    clave <="00000000";
    boton <= '1';
    wait for 50 ns;    -- Acierto
    
    
    
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    rst  <= '1';
    boton <= '0';
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    rst <= '0';
    wait until rising_edge(clk);
    wait for 40 ns;    
    boton <= '1';
    clave <="00000000";
    wait for 50 ns;    
    clave <="00000001";
    wait for 50 ns;    
    clave <="00000010";
    wait for 50 ns;    
    
    wait;
  end process p_stim;

end beh;
