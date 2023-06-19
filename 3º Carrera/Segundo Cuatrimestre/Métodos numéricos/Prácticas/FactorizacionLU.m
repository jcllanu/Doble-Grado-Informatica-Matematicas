%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
%A=[1,2,1,3;1,1,1,4;2,1,4,10;-1,-3,7,5]
%b=[45,48,101,-4]
A=input("Introduzca una matriz cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
L = eye(n);
U = zeros(n);
for i = 1:n
    %Para obtener la fórmula general basta poner la fórmula del producto de
    %matrices y despejar convenientemente
    U(i,i)=A(i,i)-L(i,1:i-1)*U(1:i-1,i);
    if U(i,i) == 0
        error("La matriz no admite factorización LU.");
    end
    for j =i+1:n
        U(i,j)=A(i,j)-L(i,1:i-1)*U(1:i-1,j);
        L(j,i)=(A(j,i)-L(j,1:i-1)*U(1:i-1,i))/U(i,i);
    end
end
% disp(L);
% disp(U);
% [L2,U2,P2]=lu(A);%es distinta que la que hacemos nosotros porque su P no es Id

seguir = 1;
while seguir
    b=input("Introduzca un vector b para resolver el sistema Au=b: ");
    if n~=length(b)
        error("El vector b debe ser un vector columna de n componentes."); 
    end
%     Au=b <=> LUu=b <=> Lw=b && Uu=w
% Remonte para triangular inferior con unos en la diagonal
    w(1) = b(1);
    for i =2:n
        w(i)= b(i)-L(i,1:i-1)*w(1:i-1)';
    end
%     disp(w');
% Remonte para triangular superior
    u(n)=w(n)/U(n,n);
    for i = n-1:-1:1
        u(i)= (w(i)-U(i,i+1:n)*u(i+1:n)')/U(i,i);
    end
    disp("La solución al sistema es: ");
    disp(u');
%     disp(A\b');
%     if u'~=A\b'
%         error("La solución no es correcta");
%     end
    seguir=input("¿Quiere seguir resolviendo sistema? (1 para SÍ, 0 para NO): ");
%     clear b;
%     clear u;
%     clear w;
end
    
