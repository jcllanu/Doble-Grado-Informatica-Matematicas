library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

 entity uc is
    port (
      clk    : in  std_logic;                      -- clock
      rst    : in  std_logic;                      -- reset
      init   : in  std_logic;                      -- External control signal
      done   : out std_logic;                      -- External control signal
      ctrl   : out std_logic_vector(7 downto 0);   -- Control vector
      status : in  std_logic_vector(1 downto 0));  -- Status vector
  end uc;

architecture rtl of uc is
  type t_estado is (s0, s1, s2, s3, s4);
  signal estado_actual, estado_siguiente : t_estado;
  signal n_es_cero, b_es_uno             : std_logic;
begin

  -----------------------------------------------------------------------------
  -- Internamente no trabajo con las componentes del vector status sino que
  -- damos nombre a cada una de las componentes y trabajamos con ellas por
  -- separado. De esta forma es mucho más legible el codigo obtenido. Luego
  -- la componente status(0) la asigno a la sennal n_es_cero y la componente
  -- status(1) la asigna la senal b_es_uno.
  -----------------------------------------------------------------------------
    (b_es_uno, n_es_cero) <= status;

  -----------------------------------------------------------------------------
  -- Proceso estado siguiente.
  -----------------------------------------------------------------------------
  p_estado_siguiente : process (estado_actual, init, n_es_cero, b_es_uno) is
  begin 
    case estado_actual is
      when s0 =>
        if init = '1' then
          estado_siguiente <= s1;
        else
          estado_siguiente <= s0;
        end if;
      when s1 =>
        estado_siguiente <= s2;
      when s2 =>
        if n_es_cero = '1' then
           estado_siguiente <= s0;
        else
            if b_es_uno = '1' then
                estado_siguiente <= s3;
            else
                estado_siguiente <= s4;
            end if;
        end if;        
      when s3 =>
       estado_siguiente <= s2;
      when s4 =>
        estado_siguiente <= s2;
      when others => 
        estado_siguiente <= s0;
    end case;
  end process p_estado_siguiente;
  
p_salidas : process (estado_actual) is
  begin 
    case estado_actual is
      when s0 =>
      done <= '1';
      ctrl <= "00000000";
      when s1 =>
        done <= '0';
        ctrl <= "10101010";
      when s2 =>
        done <= '0';
        ctrl <= "00000000";  
      when s3 =>
       done <= '0';
       ctrl <= "11111111";
      when s4 =>
        done <= '0';
        ctrl <= "11110011";
      when others => 
        done <= '1';
        ctrl <= "00000000";
    end case;
  end process p_salidas;
  
  p_registro_estado : process (clk, rst) is
  begin
    if rst = '0' then
      estado_actual <= s0;
    elsif rising_edge(clk) then
      estado_actual <= estado_siguiente;
    end if;
  end process p_registro_estado;

end architecture rtl;
