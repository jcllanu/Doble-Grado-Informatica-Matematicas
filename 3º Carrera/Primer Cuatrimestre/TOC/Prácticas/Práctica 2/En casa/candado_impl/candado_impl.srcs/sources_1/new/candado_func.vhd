library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity candado is
    port(
    I: in std_logic_vector(7 downto 0);
    btnC: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    O : out std_logic;
    seg: out std_logic_vector(3 downto 0));
end candado;

architecture estructura_comp of candado is

type estado is(inicial,tres,dos,uno,final);
signal estado_actual, estado_siguiente : estado;

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


p_combinacional: process(btnC, estado_actual, I, clave)
begin
    case estado_actual is
    
        when inicial=>
            O <= '1';
            seg <= "1000"; --Por poner un numero
            if btnC = '1' then 
                estado_siguiente<=tres;
                --Guardar clave
                cargar_clave<='1';
            else
                estado_siguiente <= inicial;
                cargar_clave <= '0';
            end if;
            
        when tres=>
            O <= '0';
            seg <= "0011";
            cargar_clave <= '0';
            if btnC = '1' then
                if clave=I then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= dos;
                end if;	
            else
                estado_siguiente <= tres;  
            end if;
            
        when dos =>
            O <= '0';
            seg <= "0010";
            cargar_clave <= '0';
            if btnC = '1' then 
                if clave=I then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= uno;
                end if;
            else	
                estado_siguiente <= dos;  
            end if;
            
        when uno=>
            O <= '0';
            seg <= "0001";
            cargar_clave <= '0';
            if btnC = '1' then 
                if clave=I then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= final;
                end if;
            else
                estado_siguiente <= uno;  
            end if;
            
        when final=>
            O <= '0';
            seg <= "0000";
            cargar_clave <= '0';
            estado_siguiente<=final;
        when others => 
            O <= '0';
            seg <= "0000";
            cargar_clave <= '0';
            estado_siguiente<=inicial;
    end case;
end process p_combinacional;
end estructura_comp;