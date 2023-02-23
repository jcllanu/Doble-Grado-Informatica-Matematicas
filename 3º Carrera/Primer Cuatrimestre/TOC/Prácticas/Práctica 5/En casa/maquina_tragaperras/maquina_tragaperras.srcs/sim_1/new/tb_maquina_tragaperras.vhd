library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity tb_tragaperras is
end tb_tragaperras;

architecture rtl of tb_tragaperras is

component tragaperras is
port (clk   : in  std_logic;
        rst : in  std_logic;
        ini : in  std_logic;
        fin : in  std_logic;
        led:  out std_logic_vector(9 downto 0);
        seg : out  STD_LOGIC_VECTOR (6 downto 0);
        an : out  std_logic_vector (3 downto 0)
        );
end component;
--entradas
signal clk, rst, ini,fin: std_logic;
--salidas
signal led :  std_logic_vector (9 downto 0);
signal seg :  std_logic_vector (6 downto 0);
signal an  :  std_logic_vector (3 downto 0);

--se define el periodo de reloj 
  constant clk_period : time := 50 ns;
  
  
begin
    dut : tragaperras  port map (
        clk => clk,
        rst => rst,
        ini => ini,
        fin => fin,
        led => led,
        seg => seg,
        an =>an
        );
        
      
  -- definicion del process de reloj
  p_clk : process
  begin
    clk <= '0';
    wait for clk_period/2;
    clk <= '1';
    wait for clk_period/2;
  end process p_clk;
  
  --proceso estimulos
      
      p_stim : process
    
  begin
    wait for 1 ps;
    rst<='1';
    ini <= '0';
    fin <= '0';
    --El debouncer no funciona bien y al princincipio genera un 1 en ini por su cuenta por lo que salta dirtectamente al estado s1
    wait for 60 ns;
    rst<='0';
    fin <= '1';--Pulsamos fin
    wait for 250 ms;--Mantenemos pulsado
    fin <= '0';--Soltamos fin
    wait for 100 ns;
    wait for 18000 ms;--Dejamos pasar 18 seg
    ini<='1';--Pulsamos ini
    wait for 250 ms;--Mantenemos pulsado
    ini <= '0';--Soltamos ini
    wait for 5900 ms;
    wait for 30 us;
    fin <= '1';--Pulsamos fin
    wait for 250 ms;--Mantenemos pulsado
    fin <= '0';--Soltamos fin
    wait for 18000 ms;--Esperamos 20 seg para ver las luces de victoria/derrota y las de atraer a un cliente
    wait;
  end process p_stim;
end rtl;