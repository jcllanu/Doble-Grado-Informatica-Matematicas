%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%A=[1,2,-2;1,1,1;2,2,1]
%b=[-1,6,7]
%(Diverge)

%A=[2,-1,1;2,2,2;-1,-1,2]
%b=[-1,6,7]
%(Converege)

%A=M-N con M= D/w - E y N=((1-w)/w)D + F

%Au=b <=> (M-N)u=b <=> Mu=Nu+b <=> (D/w - E)u=(((1-w)/w)D + F)u + b (<=> u=Bu+c punto fijo)
%Y la iteración es: (D/w - E)u^k+1=(((1-w)/w)D + F)u^k + b <=>
%(D/w)u^k+1 = r^k +(D/w)u^k <=> D(u^k+1-u^k)=wr^k
%con r^k =(def) b -((D-F)u^k - Eu^k+1) (No es el vector residuo pero
%también funciona la parada)
%1.- Calcular r^k = b - Au^(k,i)
%2.- Calcular d^k solucion de Dd^k=wr^k (d^k=(def) u^k+1 - u^k)
%3.- Calcular u^k+1=d^k+u^k


A=input("Introduzca una matriz cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
if ~all(diag(A))
    error("No se puede aplicar el método de relajación (alguno de los elementos de la diagonal es cero)."); 
end
b=input("Introduzca un vector b para resolver el sistema Au=b: ");
if n~=length(b)
    error("El vector b debe ser un vector de n componentes."); 
end
w=input("Introduzca el parámetro de relajación (0<w<2): ");
if w<=0 || w>=2
    error("El parámetro de relajación debe estar en (0,2)."); 
end
maxIt=input("Introduzca el número máximo de iteraciones: ");
prec=input("Introduzca la precisión del test de parada: ");


cont=0;
d_k=zeros(1,n);%Vector fila
u_k=zeros(n,1);%Vector columna
%Incializamos r_k para saber si hace falta entrar en el bucle
r_k=b'-A*u_k;%Vector columna
%calculamos prec*norm(b) una sola vez y no cada vuelta del bucle
tope=prec*norm(b);
while cont<maxIt && norm(r_k)>=tope
    %Podemos cambiar u_k_1 por u_k
    for i = 1:n
        %r_k(i)=b(i)-A(i,1:i-1)*u_k_1(1:i-1)-A(i,i:n)*u_k(i:n);
        r_k(i)=b(i)-A(i,:)*u_k;
        d_k(i)=w*r_k(i)/A(i,i);
        %u_k_1(i)=u_k(i)+d_k(i);
        u_k(i)=u_k(i)+d_k(i);
    end
    cont=cont+1;
%     u_k=u_k+1;
%     disp(cont+".- u=");
%     disp(u_k);
end


if norm(r_k)>=tope
    disp("Se ha alcanzado el número máximo de iteraciones ("+maxIt+") y la solución vale: ");
    disp(u_k);
%     disp(A\b');
else
    disp("Se ha alcanzado la precisión en "+cont+" iteraciones y la solución vale:");
    disp(u_k);
%     disp(A\b');
end;
