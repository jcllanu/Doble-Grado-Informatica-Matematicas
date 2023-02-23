%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN

%A=[1,2,-2;1,1,1;2,2,1]
%b=[-1,6,7]
%(Diverge)

%A=[2,-1,1;2,2,2;-1,-1,2]
%b=[-1,6,7]
%(Converege)

%A=M-N con M=D y N=E+F

%Au=b <=> (M-N)u=b <=> Mu=Nu+b <=> Du=(E+F)u + b (<=> u=Bu+c punto fijo)
%Y la iteración es: Du^k+1=(E+F)u^k + b = b - Au^k +Du^k = r^k + Du^k
%con r^k =(def) b - Au^k = D(u^k+1 - u^k)
%1.- Calcular r^k = b - Au^k
%2.- Calcular d^k solucion de Dd^k=r^k (d^k=(def) u^k+1 - u^k)
%3.- Calcular u^k+1=d^k+u^k

A=input("Introduzca una matriz cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
if ~all(diag(A))
    error("No se puede aplicar el método de Jacobi (alguno de los elementos de la diagonal es cero)."); 
end

b=input("Introduzca un vector b para resolver el sistema Au=b: ");
if n~=length(b)
    error("El vector b debe ser un vector de n componentes."); 
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
    r_k=b'-A*u_k;
    d_k=r_k./diag(A);
    u_k = u_k + d_k;
    %En realidad: u_k+1=u_k + d_k; u_k=u_k+1; pero podemos simplificarlo
    
%     for i = 1:n
%         r_k(i)=b(i)-A(i,:)*u_k;
%         d_k(i)=r_k(i)/A(i,i);
%         u_k_1(i)=u_k(i)+d_k(i);
%     end
    cont=cont+1;
    
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
