%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

function [sol]=newton(F,x_0,prec)
    syms x;
    derivada=symfun(diff(F,x),x);
    x_n =double(x_0-F(x_0)/derivada(x_0));
    x_n_1 =x_0;%x_n-1
    while abs(x_n-x_n_1)>=prec*abs(x_n_1) || F(x_n)>=prec
        x_n_1=x_n;
        x_n=double(x_n_1-F(x_n_1)/derivada(x_n_1));
    end
    sol=x_n;
end
