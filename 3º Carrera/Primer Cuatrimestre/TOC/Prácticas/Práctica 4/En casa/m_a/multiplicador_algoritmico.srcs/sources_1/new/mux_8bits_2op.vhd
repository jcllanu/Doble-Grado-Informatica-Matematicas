library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity mux_8bits_2op is
  port (
  cero:   in std_logic_vector(7 downto 0);
  uno:    in std_logic_vector(7 downto 0);
  op:     in std_logic;
  salida: out std_logic_vector(7 downto 0));
end mux_8bits_2op;

architecture estructura of mux_8bits_2op is

begin
process (cero,uno,op) is
    begin
        if op='0' then
            salida<=cero;
        else
            salida<=uno;
        end if;
end process;
end estructura;
