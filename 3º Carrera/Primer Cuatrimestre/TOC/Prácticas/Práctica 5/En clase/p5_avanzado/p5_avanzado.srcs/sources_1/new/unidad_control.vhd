library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

 entity uc is
    port (
      clk    : in  std_logic;                      -- clock
      rst    : in  std_logic;                      -- reset
      ini    : in  std_logic;                      -- External control signal
      fin    : in  std_logic;                      -- External control signal
      mod_mem: in  std_logic;                      -- External control signal
      ctrl   : out std_logic_vector(4 downto 0);   -- Control vector
      status : in  std_logic_vector(2 downto 0));   -- Status vector
  end uc;

architecture rtl of uc is
  type t_estado is (s0, s1, s2, s3, s4);
  signal estado_actual, estado_siguiente : t_estado;
  
   -- SENNALES DE ESTADO
  signal iguales        : std_logic;--Indica si mux1=mux2
  signal sec_terminada  : std_logic;--Indica si la secuencia de victoria/derrota ha terminado
  signal mod_mem_terminado: std_logic;
  
begin

  -----------------------------------------------------------------------------
  -- Internamente no trabajo con las componentes del vector status sino que
  -- damos nombre a cada una de las componentes y trabajamos con ellas por
  -- separado. De esta forma es mucho más legible el codigo obtenido. Luego
  -- la componente status la asigno a las sennales iguales y sec_terminada;
  -----------------------------------------------------------------------------
    (iguales,sec_terminada, mod_mem_terminado) <= status;
  -----------------------------------------------------------------------------
  -- Proceso estado siguiente.
  -----------------------------------------------------------------------------
  p_estado_siguiente : process (estado_actual, ini,fin, mod_mem, iguales,sec_terminada, mod_mem_terminado) is
  begin 
    case estado_actual is
      when s0 =>
        if ini = '0' then
          estado_siguiente <= s0;
        else
            --Nuevo estado s4
            if mod_mem='0' then
                estado_siguiente <= s1;
            else
                estado_siguiente <= s4;
            end if;   
        end if;
      when s1 =>
        if fin = '0' then
          estado_siguiente <= s1;
        else
           if iguales = '1' then
              estado_siguiente <= s2;
           else
              estado_siguiente <= s3;
           end if;
        end if;
      when s2 =>
         if sec_terminada = '0' then
            estado_siguiente <= s2;
        else
            estado_siguiente <= s0;
        end if;     
      when s3 =>
         if sec_terminada = '0' then
            estado_siguiente <= s3;
        else
            estado_siguiente <= s0;
        end if;
       when s4 =>
         if mod_mem_terminado='0' then
            estado_siguiente <= s4;
         else
            estado_siguiente <= s0;
         end if;
      when others => 
        estado_siguiente <= s0;
    end case;
  end process p_estado_siguiente;
  
p_salidas : process (estado_actual) is
  begin 
    case estado_actual is
      when s0 =>
        ctrl <= "00010";
      when s1 =>
        ctrl <= "11000";
      when s2 =>
        ctrl <= "10110";  
      when s3 =>
        ctrl <= "10100";
      when s4 =>
        ctrl <= "00001";
      when others =>
        ctrl <= "00000";
    end case;
  end process p_salidas;
  
  p_registro_estado : process (clk, rst) is
  begin
    if rst = '1' then
      estado_actual <= s0;
    elsif rising_edge(clk) then
      estado_actual <= estado_siguiente;
    end if;
  end process p_registro_estado;

end architecture rtl;
