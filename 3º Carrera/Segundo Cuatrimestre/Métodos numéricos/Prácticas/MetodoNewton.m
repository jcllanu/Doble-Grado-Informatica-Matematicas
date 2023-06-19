%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%a) x^2 - 2 = 0
%F(x)=@(x) x^2 - 2
%[a,b]=[1,2] Hipótesis H1 => x_0=2

%b) x^3 - 3 = 0
%F(x)=@(x) x^3 - 3
%[a,b]=[1,3] Hipótesis H1 => x_0=3

disp("Introduzca una función para calcular una de sus raíces. La función")
F=input("debe cumplir las hipótesis H en un intervalo [a,b]: ");
x_0=input("Introduzca x_0 como el extremo del intervalo [a,b] donde la función y la segunda derivada tienen el mismo signo: ");
prec=input("Introduzca la precisión de la aproximación deseada (0 para usar la aproximación por defecto de 10^-6): ");
if prec==0
    prec=10^-6;
end

sol=newton(F,x_0,prec);
disp("La aproximación de la raiz con precisión " + prec + " es :");
format long
sol
%abs(double(sol)-sqrt(2))
%abs(double(sol)-3^(1/3))
