library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multiplicador_sumador_reg is
    port(
    X : in std_logic_vector(3 downto 0);
    Y : in std_logic_vector(3 downto 0);
    S : out std_logic_vector(7 downto 0);
    clk: in std_logic;
    rst: in std_logic
    );
    
end multiplicador_sumador_reg;

architecture estructura of multiplicador_sumador_reg is

component adder8b is
     port( a: in std_logic_vector(7 downto 0);
          b: in std_logic_vector(7 downto 0);
          c: out std_logic_vector(7 downto 0) );
end component;

signal output_sum1, output_sum2,output_sum3: std_logic_vector(7 downto 0);
signal output_reg1, output_reg2, output_reg3, output_reg4, output_reg5: std_logic_vector(7 downto 0);
signal input_1, input_2, input_3, input_4: std_logic_vector(7 downto 0);

begin
    input_1<="0000"&(X(3)and Y(0))&(X(2)and Y(0))&(X(1)and Y(0))&(X(0)and Y(0));
    input_2 <= "000"&(X(3)and Y(1))&(X(2)and Y(1))&(X(1)and Y(1))&(X(0)and Y(1))&"0";
    input_3 <= "00"&(X(3)and Y(2))&(X(2)and Y(2))&(X(1)and Y(2))&(X(0)and Y(2))&"00";
    input_4 <= "0"&(X(3)and Y(3))&(X(2)and Y(3))&(X(1)and Y(3))&(X(0)and Y(3))&"000";
    S <= output_sum3;
    
sum1 : adder8b
    port map (a => input_1,
              b => input_2,
              c => output_sum1);
sum2 : adder8b
    port map (a => output_reg1,
              b => output_reg2,
              c => output_sum2);
              
sum3 : adder8b
    port map (a => output_reg4,
              b => output_reg5,
              c => output_sum3);

p_reg_Fase1: process(clk,rst)
begin
   if rst='1' then
     output_reg1<=(others=>'0');
     output_reg2<=(others=>'0');
     output_reg3<=(others=>'0');
   elsif rising_edge(clk) then
     output_reg1<=output_sum1;
     output_reg2<=input_3;
     output_reg3<=input_4;
   end if;
     end process p_reg_Fase1;
 
     
p_reg_Fase2: process(clk,rst)
begin
   if rst='1' then
     output_reg4<=(others=>'0');
     output_reg5<=(others=>'0');
   elsif rising_edge(clk) then
     output_reg4<=output_sum2;
     output_reg5<=output_reg3;
   end if;
     end process p_reg_Fase2;
end estructura;
