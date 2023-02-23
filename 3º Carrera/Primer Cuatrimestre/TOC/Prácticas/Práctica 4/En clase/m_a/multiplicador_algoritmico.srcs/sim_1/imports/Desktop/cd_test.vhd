library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity test_multiplicador is
end test_multiplicador;

architecture rtl of test_multiplicador is

component multiplicador is
port (clk   : in  std_logic;
        rst : in  std_logic;
        init : in  std_logic;
        a_in  : in  std_logic_vector(3 downto 0);  -- factor 1
        b_in  : in  std_logic_vector(3 downto 0);  -- factor 2
        done : out std_logic;
        resultado:  out std_logic_vector(7 downto 0)--resultado
        );
        
end component;
--entradas
signal a,b : std_logic_vector(3 downto 0);
signal clk, rst, init: std_logic;

--salidas
signal ready : std_logic;
signal acc : std_logic_vector(7 downto 0);

-- Expected output
  signal S_xpct : std_logic_vector(7 downto 0) := (others => '0');
  
--se define el periodo de reloj 
  constant clk_period : time := 50 ns;
  
  
begin
    dut : multiplicador 
    port map ( a_in => a,
        b_in => b,
        clk => clk,
        rst => rst,
        init => init,
        resultado => acc,
        done => ready
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
    variable v_i : natural := 0;
    variable v_j : natural := 0;
  begin
    wait for 1 ps;
    rst<='0';
    wait for 60 ns;
    rst<='1';
    
    i_loop : for v_i in 0 to 15 loop
      j_loop : for v_j in 0 to 15 loop
        init<='1';
        a <= std_logic_vector(to_unsigned(v_i, 4));
        b <= std_logic_vector(to_unsigned(v_j, 4));
        S_xpct <= std_logic_vector(to_unsigned(v_i * v_j, 8));
        wait for 5 ns;
        assert acc = S_xpct
          report "Error multiplying, "&integer'image(v_i)&" * " &integer'image(v_j)& " = " & integer'image(v_i*v_j) &
          " not " &integer'image(to_integer(unsigned(S_xpct)))
          severity error;
        wait for 100 ns;
         init<='0';
        wait until ready='1';
        wait for 1000 ns;
      end loop j_loop;
    end loop i_loop;

    wait;
  end process p_stim;
end rtl;