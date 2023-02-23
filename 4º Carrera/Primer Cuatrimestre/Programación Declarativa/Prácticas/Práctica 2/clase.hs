--Juan Carlos Llamas Núñez 4ºDG Mat-Inf
--1
--a
cuadrados::Int->[Int]
cuadrados n= map (\x->x^2) [0..n]
--b
cuadradosBis::Int->[(Int,Int)]
cuadradosBis n= map (\x->(x,x^2)) [n,n-1..0]
--c
--falta tipo
suma_cos::(Floating a, Enum a) => a -> a
suma_cos n = sum (map (\x->x*abs(cos(x))) [1..n])
--d
sum_5_3::Int->Int
sum_5_3 n = sum(filter (\x->x`mod`5==0 || x`mod`3==0) [1..n-1])
--e
primer_primo::Int->Int
primer_primo n =head(filter (\x->x>n) primos) where
                   primos=filter (\x->all (\y->x`mod`y/=0) [2..x-1]) [2..]
--2
--a
iguales::(Enum a, Eq b) => (a->b) -> (a->b) -> a -> a -> Bool
iguales f g n m = all (\x-> f x == g x) [n..m]
--b
menor::Enum a=>a->(a->Bool)->a
menor n p=head(filter p [n..])
--c
--Con Enum da problemas al restar 1
mayorA::Integral a=>a->a->(a->Bool)->a
mayorA n m p=head(filter p [m,(m-1)..n])
--d
ex::Enum a=>a->a->(a->Bool)->Bool
ex n m p=any p [n..m]

--3
--a
filter2::[a]->(a->Bool)->(a->Bool)->([a],[a])
filter2 xs p q =(filter p xs, filter q xs)
--b 
filters::[a]->[a->Bool]->[[a]]
--la x de la funcion lambda es una funcion
filters xs ps =map (\x->filter x xs) ps
--c
mapx::a->[a->b]->[b]
--la y de la funcion lambda es una funcion
mapx x fs = map (\y-> y x) fs
--4
--a
mifoldr1::(a->a->a)->[a]->a
mifoldr1 f [x] = x
mifoldr1 f (x:xs) = f x (mifoldr1 f xs)
--b
mifoldl1::(a->a->a)->[a]->a
mifoldl1 f [x] = x
mifoldl1 f (x:y:xs) = mifoldl1 f ((f x y):xs)