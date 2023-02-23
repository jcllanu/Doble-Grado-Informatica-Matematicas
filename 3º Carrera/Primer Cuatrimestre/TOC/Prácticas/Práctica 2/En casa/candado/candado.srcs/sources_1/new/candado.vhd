library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity candado is
    port(
    clave: in std_logic_vector(7 downto 0);
    boton: in std_logic;
    clk : in std_logic;
    rst : in std_logic;
    abierto : out std_logic;
    intentos_restantes: out std_logic_vector(3 downto 0));
end candado;

architecture estructura of candado is
    type estado_t is (inicial, tres, dos, uno, final);
    signal estado_actual, estado_siguiente : estado_t;
    signal clave_buena: std_logic_vector(7 downto 0);
begin

p_reg : process(clk, rst)
begin
    if rst = '0' then
        estado_actual <= inicial;
    else
        if rising_edge(clk) then
            estado_actual <= estado_siguiente;
        end if;
    end if;
end process p_reg;

p_combinacional: process(clave, boton, estado_actual)
begin
    case estado_actual is
        when inicial=>
            abierto <= '1';
            intentos_restantes<="1000"; --Por poner un numero
            if boton = '1' then --Quizás es a 0 si es en activo a baja
                estado_siguiente<=tres;
                --Guardar clave
                clave_buena<=clave;
            else
                estado_siguiente<=inicial;
            end if;
            
        when tres=>
            abierto <= '0';
            intentos_restantes<="0011";
            if boton = '1' then
                if clave_buena=clave then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= dos;
                end if;
            else
                estado_siguiente<=tres;  
            end if;
            
        when dos=>
            abierto <= '0';
            intentos_restantes<="0010";
            if boton = '1' then 
                if clave_buena=clave then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= uno;
                end if;
            else
                estado_siguiente<=dos;  
            end if;
            
        when uno=>
            abierto <= '0';
            intentos_restantes<="0001";
           if boton = '1' then 
                if clave_buena=clave then 
                    estado_siguiente <= inicial;
                else
                    estado_siguiente <= final;
                end if;
            else
                estado_siguiente<=uno;  
            end if;
            
        when final=>
            abierto <= '0';
            intentos_restantes<="0000"; --Por poner un numero
    end case;
end process p_combinacional;
end estructura;
