--Juan Carlos Llamas Núñez 4º DG Mat-Inf PD
--1
type Punto = (Int, Int)
data Direccion = Arriba | Abajo | Izquierda | Derecha deriving (Eq, Ord, Show)

--La precondición de mueve es que p es un punto correcto, es decir, que si (f,c)=p entonces 0<=f<=100 y 0<=c<=100
mueve :: Punto -> Direccion -> Maybe Punto
mueve p Arriba = if f>=1 then Just (f-1,c) else Nothing where (f,c) = p
mueve p Abajo = if f<=99 then Just (f+1,c) else Nothing where (f,c) = p
mueve p Izquierda = if c>=1 then Just (f,c-1) else Nothing where (f,c) = p
mueve p Derecha = if c<=99 then Just (f,c+1) else Nothing where (f,c) = p

--La precondición de destino es que p es un punto correcto
--Si en algún momento del recorrido se sale de la cuadrícula, el resultado es Nothing
destino :: Punto -> [Direccion] -> Maybe Punto
destino p ms = foldl (\x y -> if x == Nothing then Nothing else mueve (f x) y) (Just p) ms where f (Just a) = a

--La precondición de trayectoria es que p es un punto correcto
--Si en algún momento del recorrido se sale de la cuadrícula, el resultado es Nothing a partir del momento en el que se sale
trayectoria :: Punto -> [Direccion] -> [Maybe Punto]
trayectoria p ms = foldl (\xs y -> if (last xs)==Nothing then xs++[Nothing] else xs++[mueve (f (last xs)) y]) [Just p] ms where f (Just a) = a
--Obs: aparece el punto de partida p en la lista. Si se quisiera quitar simplemente basta aplicar la función tail sobre el resultado de trayectoria 

--2
data Nat = Cero |Suc Nat deriving (Eq, Ord)

infix 6 +.
(+.) :: Nat -> Nat -> Nat
(+.) Cero x = x
(+.) (Suc x) y = x +. (Suc y)

infix 7 *.
(*.) :: Nat -> Nat -> Nat
(*.) Cero x = Cero
(*.) (Suc x) y = y +. x*. y

natToInt :: Nat->Int
natToInt Cero = 0
natToInt (Suc x) = 1 + natToInt x

instance Show Nat where
 show n = show(natToInt n)  

--3
data Complejo =  C Float Float deriving Eq

instance Show Complejo where
 show (C a b) = show a ++ (if b>=0 then "+" else "") ++ show b ++"i"

instance Num Complejo where
 (C a b) + (C c d) = C (a + c) (b + d) 
 (C a b) - (C c d) = C (a - c) (b - d)
 (C a b) * (C c d) = C (a * c - b * d) (a * d + b * c)
--Incluimos la implementación de otras funciones de la clase Num para números complejos (Obs: abs ~ módulo)
 fromInteger n = (C (fromInteger n) 0)
 abs (C a b) = (C (sqrt(a**2+b**2)) 0)
 negate x = (C 0 0)-x
--No implementamos signum porque está función no está bien definida en los complejos

instance Fractional Complejo where
 (C a b) / (C c d) = (C a b) * (C (1 / (c**2 + d**2)) 0) *  (C c (-d))
--Incluimos la implementación de otras funciones de la clase Fractional para números complejos
 fromRational r = (C (fromRational r) 0)

--4
class Medible a where
 medida::a->Int

instance Medible Bool where
 medida x = if x then 1 else 0

instance Medible a => Medible [a] where
 medida xs = sum (map medida xs)

instance (Medible a, Medible b) => Medible (a,b) where
 medida (a,b) = medida a Prelude.+ medida b




