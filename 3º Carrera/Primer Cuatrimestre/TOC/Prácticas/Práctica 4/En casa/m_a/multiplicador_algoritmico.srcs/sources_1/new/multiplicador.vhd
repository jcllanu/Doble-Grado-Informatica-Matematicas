
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multiplicador is
port (clk   : in  std_logic;
        rst : in  std_logic;
        init : in  std_logic;
        a_in  : in  std_logic_vector(3 downto 0);  -- factor 1
        b_in  : in  std_logic_vector(3 downto 0);  -- factor 2
        done : out std_logic;
        resultado:  out std_logic_vector(7 downto 0)--resultado
        );
end multiplicador;

architecture estructura of multiplicador is


  --RUTA DE DATOS
component cd is
  port (
    clk    : in std_logic;                      -- clock
    rst    : in std_logic;                      -- reset
    a_in   : in std_logic_vector(3 downto 0);    -- factor 1
    b_in   : in std_logic_vector(3 downto 0);    -- factor 2
    ctrl   : in std_logic_vector(7 downto 0);   -- Control
    status : out std_logic_vector(1 downto 0);  
    result : out std_logic_vector(7 downto 0));  -- Resultado
end component;

--UNIDAD DE CONTROL
  component uc is
    port (
      clk    : in  std_logic;                      -- clock
      rst    : in  std_logic;                      -- reset
      init   : in  std_logic;                      -- External control signal
      done   : out std_logic;                      -- External control signal
      ctrl   : out std_logic_vector(7 downto 0);   -- Control vector
      status : in  std_logic_vector(1 downto 0));  -- Status vector

  end component;

  signal ctrl   : std_logic_vector(7 downto 0);  -- Control vector
  signal status : std_logic_vector(1 downto 0);  --Status vector
  
begin

  i_cd : cd port map (
    clk    => clk,
    rst    => rst,
    a_in   => a_in,
    b_in   => b_in,
    ctrl   => ctrl,
    status => status,
    result=>resultado);

  i_uc : uc port map (
    clk    => clk,
    rst    => rst,
    init   => init,
    done    => done,
    ctrl   => ctrl,
    status => status);


end estructura;
