library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multiplicador_sumador is
    port(
    X : in std_logic_vector(3 downto 0);
    Y : in std_logic_vector(3 downto 0);
    S : out std_logic_vector(7 downto 0)
    );
end multiplicador_sumador;

architecture estructura of multiplicador_sumador is
component adder8b is
     port( a: in std_logic_vector(7 downto 0);
          b: in std_logic_vector(7 downto 0);
          c: out std_logic_vector(7 downto 0) );
end component;

signal output_sum1, output_sum2,output_sum3: std_logic_vector(7 downto 0);
signal input_sum1_der, input_sum1_izq, input_sum2_der, input_sum2_izq, input_sum3_der, input_sum3_izq: std_logic_vector(7 downto 0);
begin
    input_sum1_der <= "0000"&(X(3)and Y(0))&(X(2)and Y(0))&(X(1)and Y(0))&(X(0)and Y(0));
    input_sum1_izq <= "000"&(X(3)and Y(1))&(X(2)and Y(1))&(X(1)and Y(1))&(X(0)and Y(1))&"0";
    input_sum2_der <= output_sum1;
    input_sum2_izq <= "00"&(X(3)and Y(2))&(X(2)and Y(2))&(X(1)and Y(2))&(X(0)and Y(2))&"00";
    input_sum3_der <= output_sum2;
    input_sum3_izq <= "0"&(X(3)and Y(3))&(X(2)and Y(3))&(X(1)and Y(3))&(X(0)and Y(3))&"000";
    S <= output_sum3;
sum1 : adder8b
    port map (a => input_sum1_der,
              b => input_sum1_izq,
              c => output_sum1);
sum2 : adder8b
    port map (a => input_sum2_der,
              b => input_sum2_izq,
              c => output_sum2);
              
sum3 : adder8b
    port map (a => input_sum3_der,
              b => input_sum3_izq,
              c => output_sum3);

              
end estructura;
