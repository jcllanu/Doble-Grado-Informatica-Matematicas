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
    clave: in std_logic_vector(7 downto 0);
    boton: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    abierto : out std_logic;
    intentos_restantes: out std_logic_vector(3 downto 0));
end component;

--entradas
  signal rst  : std_logic;
  signal clk  : std_logic;
  signal clave : std_logic_vector(7 downto 0);
  signal boton : std_logic;

--salidas
  signal abierto : std_logic;
  signal intentos_restantes: std_logic_vector(3 downto 0);

--se define el periodo de reloj 
  constant clk_period : time := 10 ns;

begin

  -- instanciacion de la unidad a simular 
  dut : candado port map (
    rst  => rst,
    clk  => clk,
    clave => clave,
    boton => boton,
    abierto=> abierto,
    intentos_restantes=>intentos_restantes
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
    wait for 45 ns;
    rst  <= '0';
    clave <="00000000";
    boton <= '0';
    wait for 50 ns;
    wait until rising_edge(clk);
    rst  <= '1';
    wait until rising_edge(clk);
    clave <="00000001";
    boton <= '0';
    wait until rising_edge(clk);
    clave <="00000010";
    wait for 10 ns;
    boton <= '1';
    wait for 10 ns;
    boton <= '0';
    wait until rising_edge(clk);
    boton <= '0';
    clave <="00000110";
    wait until rising_edge(clk);    
    boton <= '1';
    clave <="00000000";
    wait until rising_edge(clk);    --Se guarda el numero
    clave <="00000001";             
    wait until rising_edge(clk);    -- Primer error
    clave <="00000010";
    wait until rising_edge(clk);    -- Segundo error
    clave <="00000000";
    boton <= '0';
    wait until rising_edge(clk);
    clave <="00000000";
    boton <= '0';
    wait until rising_edge(clk);
    clave <="00000000";
    boton <= '1';
    wait until rising_edge(clk);    -- Acierto
    
    
    
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    rst  <= '0';
    wait until rising_edge(clk);
    rst <= '1';
    boton <= '1';
    clave <="00000110";
    wait until rising_edge(clk);    -- Se guarda el numero
    boton <= '1';
    clave <="00000000";
    wait until rising_edge(clk);    --Primer error
    clave <="00000001";
    wait until rising_edge(clk);    --Segundo error
    clave <="00000010";
    wait until rising_edge(clk);    --Tercer error
    
    wait until rising_edge(clk);
    wait until rising_edge(clk);
    rst  <= '0';
    boton <= '0';
    wait until rising_edge(clk);
    rst <= '1';
    boton <= '1';
    clave <="00000110";
    wait until rising_edge(clk);    -- Se guarda el numero
    clave <="00000000";
    wait until rising_edge(clk);    --Primer error
    clave <="00000001";
    wait until rising_edge(clk);    --Segundo error
    clave <="00000110";
    wait until rising_edge(clk);    --Acierto
    wait;
  end process p_stim;

end beh;
