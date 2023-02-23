--JUAN CARLOS LLAMAS NÚÑEZ 4º DG Mat-Inf
--1.-
--  a)
conversor_seg :: Integral a => Integral b => Integral c => Integral d => Integral e => (a,b,c,d,e)
conversor_seg = let{
                    a=10^6 `div` (365*24*60*60);
                    d=(10^6 `mod` (365*24*60*60)) `div` (24*60*60);
                    h=((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `div` (60*60);
                    m=(((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`div`60;
                    s=(((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`mod`60;
                    } in (a,d,h,m,s)
--Utilizamos let e identacion para facilitar su lectura. La idea es que hay que dividir los segundos que quedan entre 
--el numero de segundos que hay en un año y eso serán los años. Los restantes los obtenemos con el módulo y hacemos lo propio para los días

--(En clase) conversor_seg =(10^6 `div` (365*24*60*60), (10^6 `mod` (365*24*60*60)) `div` (24*60*60), ((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `div` (60*60), (((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`div`60,(((10^6 `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`mod`60)


--  b)
convers_from_seg :: Integral a => a -> (a,a,a,a,a)
convers_from_seg x = let{
                    a=x `div` (365*24*60*60);
                    d=(x `mod` (365*24*60*60)) `div` (24*60*60);
                    h=((x `mod` (365*24*60*60)) `mod` (24*60*60)) `div` (60*60);
                    m=(((x `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`div`60;
                    s=(((x `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`mod`60;
                    } in (a,d,h,m,s)
--mismo razonamiento que en el apartado anterior

--(En clase) f x = (x `div` (365*24*60*60), (x `mod` (365*24*60*60)) `div` (24*60*60), ((x `mod` (365*24*60*60)) `mod` (24*60*60)) `div` (60*60), (((x `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`div`60,(((x `mod` (365*24*60*60)) `mod` (24*60*60)) `mod` (60*60))`mod`60)


--2.-
--  a)
bisiesto :: Integral a => a -> Bool
bisiesto x= if x `mod`4 == 0 
     then if x `mod`100 == 0 
          then if x`mod`400 ==0  
               then True 
               else False 
          else True 
     else False
--Usando if. "Año bisiesto es el divisible entre 4, salvo que sea año secular -último de cada siglo, terminado en «00»-, en cuyo caso también ha de ser divisible entre 400."

--(En clase) bisiesto x= if x `mod`4 == 0 then (if x `mod`100 == 0 then (if x`mod`400 ==0  then True else False) else True) else False


--  b)
bisiestoBis :: Integral a => a -> Bool
bisiestoBis x 
    |(x `mod`4 == 0) &&((x `mod`100 /= 0) ||(x`mod`400 ==0)) =True
    | otherwise =False
--Usando guardas. Un año es bisiesto cuando es divisible entre 4 y, es divisible entre 400 o no es divisible entre 100


--3.-
media:: Integral a=> Fractional b => [a] -> b
media xs= fromIntegral(sum(xs))/fromIntegral(length(xs))
--Problema con los tipos que solucionamos con fromIntegral.


--4.-
--  a)
num_digitos :: Integral a => Num b => a -> b
num_digitos x 
      |x<0       =num_digitos(-x)
      |x<10      =1 
      |otherwise =1+num_digitos (x `div`10)
--Definición recursiva y guardas

--(En clase)
--auxiliar x = if x==0 then 0 else 1+auxiliar(x `div`10)
--num_digitos x= if x==0 then 1 else auxiliar x


--  b)
sum_digitos :: Integral a => a -> a
reduccion :: Integral a => a -> a
sum_digitos x 
    |x==0        =0
    |otherwise   =(x`mod`10)+sum_digitos(x`div`10)

reduccion x 
    |x<0                 =reduccion(-x)
    |sum_digitos(x)<10   =sum_digitos(x)
    |otherwise           =reduccion(sum_digitos(x))
--Necesitamos la definición auxiliar de sum_digitos que devuelve la suma de los digitos de un número dado. Definiciones recursivas

--(En clase)
--sum_digitos x = if x==0 then 0 else (x`mod`10) +sum_digitos(x`div`10)
--reduccion x = if x<0 then reduccion(-x) else (if sum_digitos(x)<10 then sum_digitos(x) else reduccion(sum_digitos(x)))

--5.-
disyBoolEstrUNO :: Bool -> Bool -> Bool
disyBoolEstrDOS :: Bool -> Bool -> Bool
disyBoolEstrTRES :: Bool -> Bool -> Bool

--estricta en primer parametro, siempre evalúa x
disyBoolEstrUNO x y
       |x           =True
       |otherwise   =y

--estricta en segundo parametro, siempre evalúa y
disyBoolEstrDOS x y
       |y           =True
       |otherwise   =x

--estricta en ambos parametros. Evalúa tanto x como y pero semánticamente es correcto porque not(y&&False)=True
disyBoolEstrTRES x y
       |x           = not(y&&False)
       |y           =True
       |otherwise   =False
