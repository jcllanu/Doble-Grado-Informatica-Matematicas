%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%@(x)cos(x)
%@(x)sin(x)
%@(x)2*x.^3-7*x.^2 +x-3
%@(x)exp(-x.^2)
%@(x) x.^-1 +x
%@(x) x.^4-2*x.^3-x.^2+4* x-3 absci=[-1 0 1 2]
%absc=[2,3,-1,4]; orden=[1,2,3,4]

mode=input("Introduzca 1 para interpolar una función y 0 para interpolar una tabla de valores: ");
if mode 
    f=input("Introduzca la función: ");
    abscisas=input("Introduzca el vector de abscisas de interpolación: ");
    ordenadas=f(abscisas);
    
    [pol,monico,dif_div]=interpolar_tabla(abscisas,ordenadas, [], [],[]);
    disp(pol);
    
    
    pintar(mode,f,pol,abscisas,ordenadas);
    seguir=1;
    while seguir
        seguir=input("Introduzca 1 para añadir otro punto: ");
        if seguir
           
           aux=input("Introduzca la abscisa de interpolación: ");
           abscisas=[abscisas,aux];
           ordenadas=[ordenadas,f(aux)];
           [pol,monico,dif_div]=interpolar_tabla(abscisas,ordenadas, pol,monico,dif_div);
           disp(pol);
           pintar(mode,f,pol,abscisas,ordenadas);
        end
    end
else
    abscisas=input("Introduzca el vector de abscisas de interpolación: ");
    ordenadas=input("Introduzca el vector de los valores de interpolación: ");
    [pol,monico,dif_div]=interpolar_tabla(abscisas,ordenadas, [], [],[]);
    disp(pol);
    pintar(mode,f,pol,abscisas,ordenadas);
    seguir=1;
    while seguir
        seguir=input("Introduzca 1 para añadir otro punto: ");
        if seguir
           aux=input("Introduzca la abscisa de interpolación y el valor de la función en ese punto: ");
           abscisas=[abscisas,aux(1)];
           ordenadas=[ordenadas,aux(2)];
           [pol,monico,dif_div]=interpolar_tabla(abscisas,ordenadas, pol,monico,dif_div);
           disp(pol);
           pintar(mode,f,pol,abscisas,ordenadas);
        end
    end
end

function pintar(mode,f,pol,abscisas,ordenadas)
    cla reset;
    %axis equal
    axis on
    grid on
    hold on
    if mode
         fplot(f,'k');
    end
    a=min(abscisas);
    b=max(abscisas);
    n=1000;
    dis=(b-a)/n;
    x=[a-n*dis/10:dis:b+n*dis/10];
    y=polyval(pol,x);
    plot(x,y,'r');
    plot(abscisas,ordenadas,'ob');
    
end