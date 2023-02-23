library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity mux_4bits_2op is
  port (
  cero:   in std_logic_vector(3 downto 0);
  uno:    in std_logic_vector(3 downto 0);
  op:     in std_logic;
  salida: out std_logic_vector(3 downto 0));
end mux_4bits_2op;

architecture estructura of mux_4bits_2op is

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
