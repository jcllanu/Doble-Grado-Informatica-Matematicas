%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%a) x^3 - x - 1 = 0
%Despeje: f=@(x)(1+x)^(1/3) 
%[a,b]=[1,2]       k=1/(3*4^(1/3)) 


%c) x = -ln(x)
%Despeje: f=@(x)exp(-x)
%[a,b]=[1/3,1]       k=exp(-1/3) 


f=input("Introduzca una función para calcular sus puntos fijos: ");
disp("Introduzca la constante de contractividad k, es decir, un valor en [0,1) para el que")
k=input("f sea contractiva en un cierto intervalos [a,b] y f([a,b]) este contenido en [a,b]: ");
prec=input("Introduzca la precisión de la aproximación deseado (0 para usar la aproximación por defecto de 10^-5): ");
if prec==0
    prec=10^-5;
end
x_0=input("Por último, introduzca el primer elemento de la sucesión (cuanto más cerca del punto fijo, mejor): ");
sol=punto_fijo(f,x_0,k,prec);
disp("La aproximación del punto fijo con precisión " + prec + " es :");
format long
sol
