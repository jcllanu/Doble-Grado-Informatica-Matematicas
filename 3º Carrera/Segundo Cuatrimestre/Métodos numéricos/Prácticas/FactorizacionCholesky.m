%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
%A=[1,-1,1,0;-1,2,-1,2;1,-1,5,2;0,2,2,6]
%b=[4,-3,16,8]
A=input("Introduzca una matriz cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
if ~issymmetric(A)
    error("La matriz introducida no es simétrica."); 
end
B = zeros(n);
for i = 1:n
    Bii2=A(i,i)-B(i,1:i-1)*B(i,1:i-1)';
    if Bii2 <= 0
        error("La matriz tiene algún menor principal nulo.");
    end
    B(i,i)=sqrt(Bii2);
    for j =i+1:n
        B(j,i)=(A(i,j)-B(i,1:i-1)*B(j,1:i-1)')/B(i,i);
    end
end
% disp(B);
% B2=chol(A)' %el comando chol de matlab nos devuelve B' en lugar de B

seguir = 1;
while seguir
    b=input("Introduzca un vector b para resolver el sistema Au=b: ");
    if n~=length(b)
        error("El vector b debe ser un vector de n componentes."); 
    end
%     Au=b <=> BB'u=b <=> Bw=b && B'u=w
% Remonte triangular inferior
    w(1) = b(1)/B(1,1);
    for i =2:n
        w(i)= (b(i)-B(i,1:i-1)*w(1:i-1)')/B(i,i);
    end
%     disp(w');
% Remonte triangular superior
    u(n)=w(n)/B(n,n);
    for i = n-1:-1:1
        u(i)= (w(i)-u(i+1:n)*B(i+1:n,i))/B(i,i);
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
    
