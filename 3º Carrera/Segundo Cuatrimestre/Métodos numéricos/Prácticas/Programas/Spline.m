%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%@(x)cos(x)
%@(x)sin(x)
%@(x)2*x.^3-7*x.^2 +x-3
%@(x)exp(-x.^2)
%@(x) x.^-1 +x
%@(x) x.^4-2*x.^3-x.^2+4* x-3 absci=[-1 0 1 2]
%absc=[-1,0,1,3]; orden=[-4,-1,0,20]; primDeriv=[6,22]
%absc=[0,1,3]; orden=[1,2,0]
mode=input("Introduzca 1 para interpolar una función y 0 para interpolar una tabla de valores: ");
if mode 
    f=input("Introduzca la función: ");   
end
abscisas=input("Introduzca los elementos de la partición (ordenados de menor a mayor): ");
n=length(abscisas)-1;
ordenadas=zeros(1,n+1);
if mode 
    ordenadas=f(abscisas);
else    
    ordenadas=input("Introduzca el vector de los valores de interpolación: ");
end
condiciones=input("Introduzca el tipo de condiciones I, II o III (1,2,3): ");

lambda=zeros(1,n);% de 0 a n-1 en las fórmulas
mu=zeros(1,n);% de 1 a n en las fórmulas
d=zeros(1,n+1);% de 0 a n en las fórmulas
for i=1:n-1
    lambda(i+1)= (abscisas(i+2)-abscisas(i+1))/(abscisas(i+2)-abscisas(i));
    %lambda(i)=h(i+1)/(h(i+1)+h(i)=(cuentas)
    %=(x(i+1)-x(i))/(x(i+1)-x(i-1)) con x(i)=abscisas(i+1)
    mu(i)=1-lambda(i+1);%mu(i)=1-lambda(i)
    d(i+1)=(6/(abscisas(i+2)-abscisas(i)))*(((ordenadas(i+2)-ordenadas(i+1))/(abscisas(i+2)-abscisas(i+1))) -((ordenadas(i+1)-ordenadas(i))/(abscisas(i+1)-abscisas(i))));
    %=(6/(h(i)+h(i+1)))*((y(i+1)-y(i))/h(i+1)-(y(i)-y(i-1))/h(i))=(cuentas)
    %=(6/(x(i+1)-x(i-1)))*((y(i+1)-y(i))/(x(i+1)-x(i)) -(y(i)-y(i-1))/(x(i)-x(i-1)))
    %con x(i)=abscisas(i+1), y(i)=ordenadas(i+1)
end

if condiciones==1
    lambda(1)=0;
    mu(n)=0;
    d(1)=0;
    d(n+1)=0;
elseif condiciones==2
    lambda(1)=1;
    mu(n)=1;
    
    if mode
        %Derivando
        syms x;
        derivada=symfun(diff(f,x),x);
        primDeriv=[derivada(abscisas(1)),derivada(abscisas(n+1))];
    else
        primDeriv=input("Introduzca los valores de la primera derivada en los extremos de la partición: ");
    end
    d(1)=(6/(abscisas(2)-abscisas(1)))*((ordenadas(2)-ordenadas(1))/(abscisas(2)-abscisas(1)) -primDeriv(1));
    %d(0)=(6/h(1))*((y(1)-y(0))/h(1) -y'(0))
    %con x(i)=abscisas(i+1), y(i)=ordenadas(i+1)
    d(n+1)=(6/(abscisas(n+1)-abscisas(n)))*(primDeriv(2) -(ordenadas(n+1)-ordenadas(n))/(abscisas(n+1)-abscisas(n))); 
    %d(n)=(6/h(n))*(y'(n) -(y(n)-y(n-1))/h(n))
else
    lambda(1)=(abscisas(2)-abscisas(1))/(abscisas(2)-abscisas(1)+abscisas(n+1)-abscisas(n));%Guardamos lambda(n) en lambda(1)(destinado en principio a almacenar lambda(0)
    %lambda(n)=h(1)/(h(1)+h(n))
    mu(n)=1-lambda(1);
    d(1)=0;%No lo usamos
    d(n+1)=(6/(abscisas(2)-abscisas(1)+abscisas(n+1)-abscisas(n)))*(((ordenadas(2)-ordenadas(n+1))/(abscisas(2)-abscisas(1))) -((ordenadas(n+1)-ordenadas(n))/(abscisas(n+1)-abscisas(n)))); 
    %d(n)=(6/(h(n)+h(1)))*((y(1)-y(n))/h(1) -(y(n)-y(n-1))/h(n))
end
M=zeros(1,n+1);%Momentos
if condiciones==3
     A=diag(2*ones(1,n),0)+ diag(mu(2:n),-1)+diag(lambda(2:n),1)+ diag(lambda(1),-(n-1))+diag(mu(1),n-1);
     M(2:n+1)=A\d(2:n+1)';
     M(1)=M(n+1);
else
    M=SistemasTridiagonales(mu,2*ones(1,n+1),lambda,d);
end
alfa=zeros(1,n);
beta=zeros(1,n);
gamma=zeros(1,n);
delta=zeros(1,n);

a=zeros(1,n);
b=zeros(1,n);
c=zeros(1,n);
d=zeros(1,n);

axis equal
axis on
grid on
hold on
if mode
   fplot(f,'k');
end
disp("Coeficientes de los polinomios a_0 + a_1x + a_2x^2 + a^3x^3 (a_0, a_1, a_2, a_3): ");
for i=1:n
    alfa(i)=ordenadas(i);
    beta(i)=((ordenadas(i+1)-ordenadas(i))/(abscisas(i+1)-abscisas(i)))-((2*M(i)+M(i+1))*(abscisas(i+1)-abscisas(i))/6);
    gamma(i)=M(i)/2;
    delta(i)=(M(i+1)-M(i))/(6*(abscisas(i+1)-abscisas(i)));
    
    a(i)=alfa(i)-beta(i)*abscisas(i)+gamma(i)*abscisas(i)^2-delta(i)*abscisas(i)^3;
    b(i)=beta(i)-2*abscisas(i)*gamma(i)+3*abscisas(i)^2*delta(i);
    c(i)=gamma(i)-3*abscisas(i)*delta(i);
    d(i)=delta(i);
    
    pintar([delta(i),gamma(i),beta(i),alfa(i)],abscisas(i:i+1),ordenadas(i:i+1));
    disp([a(i),b(i),c(i),d(i)]);
end
hold off

function pintar(pol,abscisas,ordenadas)
    n=1000;
    dis=(abscisas(2)-abscisas(1))/n;
    x=[abscisas(1):dis:abscisas(2)];
    y=polyval(pol,x-abscisas(1));
    plot(x,y,'r');
    plot(abscisas,ordenadas,'ob');
    
end