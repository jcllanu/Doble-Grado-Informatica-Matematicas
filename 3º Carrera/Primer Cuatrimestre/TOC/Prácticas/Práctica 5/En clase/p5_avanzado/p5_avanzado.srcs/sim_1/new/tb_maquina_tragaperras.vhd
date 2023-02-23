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
        mod_mem: in std_logic;
        din: in std_logic_vector(3 downto 0);
        salida_mem: out std_logic_vector(3 downto 0);
        led:  out std_logic_vector(9 downto 0);
        seg : out  STD_LOGIC_VECTOR (6 downto 0);
        an : out  std_logic_vector (3 downto 0)
        );
end component;
--entradas
signal clk, rst, ini,fin,mod_mem: std_logic;
signal din: std_logic_vector(3 downto 0);
--salidas
signal led :  std_logic_vector (9 downto 0);
signal seg :  std_logic_vector (6 downto 0);
signal an  :  std_logic_vector (3 downto 0);
signal salida_mem:  std_logic_vector (3 downto 0);
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
        an =>an,
        salida_mem=>salida_mem,
        mod_mem=>mod_mem,
        din=>din
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
    mod_mem<='1';
    --Algo no funciona bien (probablemente el debouncer) y al princincipio genera un 1 en ini por su cuenta por lo que salta directamente al estado s4
    wait for 60 ns;
    rst<='0';
    wait for 100 ms;
    din<="0000";
    wait for 100 ms;
    din<="0001";
    wait for 100 ms;
    din<="0010";
    wait for 100 ms;
    din<="0011";
    wait for 100 ms;
    din<="0100";
    
    
    wait;
  end process p_stim;
end rtl;