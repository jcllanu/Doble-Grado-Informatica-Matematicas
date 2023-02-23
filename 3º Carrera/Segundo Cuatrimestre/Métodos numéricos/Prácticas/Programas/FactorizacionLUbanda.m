%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
%A=[1,2,1,3;1,1,1,4;2,1,4,10;-1,-3,7,5]
%b=[45;48;101;-4]
A=input("Introduzca una matriz banda cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
p=input("Introduzca el semiancho de banda de la matriz: ");
% p=n;%%ancho de banda
% salir=0;
% for d = n:-1:1
%     for i = 1:n+1-d
%         j=d+i-1;
%         if A(i,j)~=0 || A(j,i)~=0
%             salir=1;
%             p=d;
%             break;
%         end
%     end
%     if salir
%         break;
%     end
% end

L = eye(n);
U = zeros(n);
for i = 1:n
    %En los vectores L(i,1:i-1) y U(1:i-1,j) hay muchos ceros. En
    %concreto L(j,i)=0 y U(i,j)=0 si j-i>=p, por lo que fijado j, multiplicamos en i
    %hasta j-i<p <=> j-p<i <=> i >= j-p+1 y además i>=1.(Aquí i hace el
    %papel de j también)
    topeInf=max([1,i-p+1]);
    U(i,i)=A(i,i)-L(i,topeInf:i-1)*U(topeInf:i-1,i);
    if U(i,i) == 0
        error("La matriz no admite factorización LU.");
    end
    %Si j-i>=p (<=> j >= p+i) entonces U(i,j)=0 y L(j,i)=0 luego hacemos
    %el bucle hasta j < p+i o equivalentemente j <= p+i-1. Se sigue
    %teniendo que cumplir que j<=n luego j irá de i+1 al minimo de las
    %cantidades
    topeBucle=min([p+i-1,n]);
    for j =i+1:topeBucle
        topeInf=max([1,j-p+1]);
        U(i,j)=A(i,j)-L(i,topeInf:i-1)*U(topeInf:i-1,j);
        L(j,i)=(A(j,i)-L(j,topeInf:i-1)*U(topeInf:i-1,i))/U(i,i);
    end
end
% disp(L);
% disp(U);
% [L2,U2,P2]=lu(A);



seguir = 1;
while seguir
    b=input("Introduzca un vector b para resolver el sistema Au=b: ");
    if n~=length(b)
        error("El vector b debe ser un vector de n componentes."); 
    end
%   Au=b <=> LUu=b <=> Lw=b && Uu=w
%   Optimizamos la resolución por ser matrices banda
    w(1) = b(1);
%   Por ser L banda se tiene que L(i,j)=0 si i-j>=p luego el sumatorio que
%   corresponde al producto escalar de vectores indexado en j cumple que
%   i-j<p <=> j>i-p <=> j>=i-p+1 y además j>=1
    for i =2:n
        %w(i)= b(i)-L(i,1:i-1)*w(1:i-1)';Original
        ind=max([1,i-p+1]);
        w(i)= b(i)-L(i,ind:i-1)*w(ind:i-1)';
    end
%      disp(w');
%   Por ser U banda se tiene que U(i,j)=0 si j-i>=p luego el sumatorio que
%   corresponde al producto escalar de vectores indexado en j cumple que
%   j-i<p <=> j<i+p <=> j<=i+p-1 y además j<=n
    u(n)=w(n)/U(n,n);
    for i = n-1:-1:1
        %u(i)= (w(i)-U(i,i+1:n)*u(i+1:n)')/U(i,i);
        ind=min([n,i+p-1]);
        u(i)= (w(i)-U(i,i+1:ind)*u(i+1:ind)')/U(i,i);
    end
    disp("La solución al sistema es: ");
    disp(u');
%      disp(A\b');
%     if u'~=A\b'
%         error("La solución no es correcta");
%     end
    seguir=input("¿Quiere seguir resolviendo sistema? (1 para SÍ, 0 para NO): ");
%     clear b;
%     clear u;
%     clear w;
end
    
