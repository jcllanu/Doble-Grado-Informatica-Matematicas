library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;


entity multilpicador_std is
  port (
  X: in std_logic_vector(3 downto 0);
  Y: in std_logic_vector(3 downto 0);
  S: out std_logic_vector(7 downto 0)
  );
end multilpicador_std;

architecture estructura of multilpicador_std is
    signal X_i, Y_i, S_i: integer;
    
begin
    X_i <= to_integer(unsigned(X));
    Y_i <= to_integer(unsigned(Y));
    S_i <= X_i * Y_i;
    S <= std_logic_vector(to_unsigned(S_i,8));
end estructura;
