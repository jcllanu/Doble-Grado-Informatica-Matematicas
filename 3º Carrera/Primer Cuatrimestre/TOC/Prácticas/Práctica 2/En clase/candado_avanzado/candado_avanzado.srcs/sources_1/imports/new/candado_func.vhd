library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity candado is
    port(
    Irestantes: in std_logic_vector(3 downto 0);
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    O : out std_logic_vector(7 downto 0);
    seg: out std_logic_vector(3 downto 0));
end candado;

architecture estructura_comp of candado is

type estado is(inicial, contando, final);
signal estado_actual, estado_siguiente : estado;

signal cargar_intentos: std_logic;
signal intentos_restantes: std_logic_vector(3 downto 0);
signal restar_intentos: std_logic;

signal clave: std_logic_vector(7 downto 0);
signal cargar_clave: std_logic;
begin
 
p_reg_estado : process(clk, rst)
begin
    if rst = '1' then
        estado_actual <= inicial;
    elsif rising_edge(clk) then
        estado_actual <= estado_siguiente;  
    end if;
end process p_reg_estado;

p_reg_clave : process(clk, rst)
begin
    if rst='1' then
        clave <=(others=>'0');
    elsif rising_edge(clk) then
        if cargar_clave='1' then        
            clave <= I;
        end if;
    end if; 
end process p_reg_clave;

p_reg_intentos_restantes : process(clk, rst)
begin
    if rst='1' then
        intentos_restantes <=(others=>'0');
    elsif rising_edge(clk) then
        if cargar_intentos='1' then
            if restar_intentos='0' then
                intentos_restantes <= Irestantes;
            else
                intentos_restantes <= std_logic_vector(to_unsigned(to_integer(unsigned(intentos_restantes))-1,4));
            end if;
        end if;
    end if; 
end process p_reg_intentos_restantes;

p_combinacional: process(btnC, estado_actual, I, clave)
begin
    case estado_actual is
    
        when inicial=>
            O <= "11111111";
            seg <= "1111"; --Por poner un numero
            restar_intentos <= '0';
            if btnC = '1' then 
                estado_siguiente<=contando;
                --Guardar clave
                cargar_clave <= '1';
                cargar_intentos <= '1';
            else
                estado_siguiente <= inicial;
                cargar_clave <= '0';
                cargar_intentos <= '0';
            end if;
            
        when contando=>
            O <= "00000000";
            seg <= intentos_restantes;
            cargar_clave <= '0';
           
            if btnC = '1' then
                if clave=I then 
                    estado_siguiente <= inicial;
                    cargar_intentos <= '0';
                    restar_intentos <= '0';
                else
                   if unsigned(intentos_restantes)>0 then
                     estado_siguiente <= contando;
                     --restar intentos
                      cargar_intentos <= '1';
                      restar_intentos <= '1';
                   else
                     estado_siguiente<= final;
                     cargar_intentos <= '0';
                     restar_intentos <= '0';
                   end if;
                end if;	
            else
                estado_siguiente <= contando;
                cargar_intentos <= '0';
                restar_intentos <= '0';
            end if;
            
        when final=>
            O <= "00000000";
            seg <= "0000";
            cargar_clave <= '0';
            estado_siguiente<=final;
            cargar_intentos <= '0';
            restar_intentos <= '0';
        when others => 
            O <= "00000000";
            seg <= "0000";
            cargar_clave <= '0';
            estado_siguiente<=final;
            cargar_intentos <= '0';
            restar_intentos <= '0';
    end case;
end process p_combinacional;
end estructura_comp;