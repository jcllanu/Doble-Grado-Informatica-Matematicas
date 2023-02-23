--Juan Carlos Llamas Núñez 4ºDG Mat-Inf PD
--1
--a
mi_last::[a]->a
mi_last xs = foldl (\x y-> y) undefined xs
--b
mi_reverse::[a]->[a]
mi_reverse xs = foldl (\x y->y:x) [] xs
--c
mi_all::(a->Bool)->[a]->Bool
mi_all f xs = foldr (\x y-> f x && y)True xs
--d
mi_minimum::Ord a=>[a]->a
mi_minimum [] = undefined
mi_minimum xs = foldl min (head xs) xs 
--e
mi_map::(a->b)->[a]->[b]
mi_map f xs = foldl (\x y->x++[f y]) [] xs
--f
mi_filter::(a->Bool)->[a]->[a]
mi_filter f xs = foldl (\x y->x++if (f y) then [y] else []) [] xs
--g
mi_takeWhile::(a->Bool)->[a]->[a]
mi_takeWhile f xs = foldr(\x y->if f x then x:y else []) [] xs

--2
lista_opuestos = foldl (\x y-> x++[y,-y]) [] [1..100]

--3
lista_pares = concat([[(x,y-x)|x<-[0..y]]|y<-[0..]])

--4
--a
sufijos::[a]->[[a]]
sufijos xs = [drop n xs|n<-[0..length xs]]
--b
prefijos::[a]->[[a]]
prefijos xs = [take n xs|n<-[0..length xs]]
sublistas::[a]->[[a]]
sublistas xs =[]:(filter (\u-> length u/=0) conrepetidos)
              where conrepetidos = concat(map sufijos (prefijos xs))
--c 
permuta::[a]->[[a]]
permuta []=[[]]
permuta (x:xs) =[(take n ys)++[x]++(drop n ys)|ys<-permuta(xs), n<-[0..length ys]]
--d
sumandos::Integral a=>a->[[a]]

sumandos 1 =[[1]]
sumandos n =filter ordenado ([1:ys|ys<-sumandos (n-1)]++[(x+1):xs|(x:xs)<-sumandos (n-1)])
                 where ordenado [] =True
                       ordenado [x]=True
                       ordenado (x:xs)= ordenado(xs) && x<=minimum(xs) 
