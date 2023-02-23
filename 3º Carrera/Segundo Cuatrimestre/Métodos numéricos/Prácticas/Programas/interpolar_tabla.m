%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
function [pol,monico,dif_div]=interpolar_tabla(absci,orde, pol, monico,dif_div)
%absci=   x0    x1  ...   xm  |  xm+1  ...  xn
%orde = f(x0) f(x1) ... f(xm) |f(xm+1) ... f(xn)
%pol  =   am    am-1      a0 //Coeficientes del polinomio de interpolacion
%                              de los puntos x0...xm
%monico=  bm    bm-1      b0 //Coeficientes de (x-x0)(x-x1)...(x-xm-1)
%dif_div= f[x0 x1...xm] f[x1...xm] ... f(xm)//Diagonal de diferencias
%                                             divididas
    q=length(absci);%q=n+1
    p=length(dif_div);%p=m+1
    
    for i=[p+1:q]%Para xm+1 hasta xn
        dif_div(i)=orde(i);
        for j=[i-1:-1:1]
            dif_div(j)=(dif_div(j)-dif_div(j+1))/(absci(j)-absci(i));
        end
        if p==0 && i == p+1
            monico=[1];
        else
            monico=[monico 0]-[0 absci(i-1)*monico];
        end
            pol=[0 pol]+dif_div(1)*monico;
        
    end
end


