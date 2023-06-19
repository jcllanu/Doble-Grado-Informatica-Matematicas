%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

function [sol]=punto_fijo(f,x_0,k,prec)
    x_1=f(x_0);
    n=(log(prec*(1-k))-log(abs(x_1-x_0)))/log(k);
    n=ceil(n);
    sol=x_0;
    for i=1:n
        sol=f(sol);
    end
end


