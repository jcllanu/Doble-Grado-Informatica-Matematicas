%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
%A=diag(ones(1,5),-1)+ diag(ones(1,6),0)+diag(ones(1,6),0)+ diag(ones(1,5),1)
%b=[1:6]
%Sol: [0,1,0,2,0,3]

A=input("Introduzca una matriz banda cuadrada A: ");
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
if ~issymmetric(A)
    error("La matriz introducida no es simétrica."); 
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

B = zeros(n);
for i = 1:n
    %Muchos de los elementos en B(i,1:i-1) y en B(j,1:i-1)son 0. En
    %concreto, B(j,i)=0 si j-i>=p. Fijando j, i tendrá que cumplir j-i<p 
    %<=> j-p<i <=> j-p+1<=i y i>0
    %En este caso i juega el papel de j
    topeInf=max([i-p+1,1]);
    
    Bii2=A(i,i)-B(i,topeInf:i-1)*B(i,topeInf:i-1)';
    if Bii2 <= 0
        error("La matriz tiene algún menor principal nulo.");
    end
    B(i,i)=sqrt(Bii2);
    %Si j-i>=p (<=> j >= p+i) entonces B(j,i)=0 luego hacemos
    %el bucle hasta j < p+i o equivalentemente j <= p+i-1. Se sigue
    %teniendo que cumplir que j<=n luego j irá de i+1 al minimo de las
    %cantidades
    topeBucle=min([p+i-1,n]);
    
    for j =i+1:topeBucle
        topeInf=max([j-p+1,1]);
        B(j,i)=(A(i,j)-B(i,topeInf:i-1)*B(j,topeInf:i-1)')/B(i,i);
    end
end
% disp(B);
% B2=chol(A)'

seguir = 1;
while seguir
    b=input("Introduzca un vector b para resolver el sistema Au=b: ");
    if n~=length(b)
        error("El vector b debe ser un vector de n componentes."); 
    end
%     Au=b <=> BB'u=b <=> Bw=b && B'u=w
    w(1) = b(1)/B(1,1);
%   Optimizamos la resolución por ser matrices banda

%   Por ser B banda se tiene que B(i,j)=0 si i-j>=p luego el sumatorio que
%   corresponde al producto escalar de vectores indexado en j cumple que
%   i-j<p <=> j>i-p <=> j>=i-p+1 y además j>=1
    for i =2:n
        %w(i)= (b(i)-B(i,1:i-1)*w(1:i-1)')/B(i,i); Original
        ind=max([1,i-p+1]);
        w(i)= (b(i)-B(i,ind:i-1)*w(ind:i-1)')/B(i,i);
    end
%     disp(w');
    u(n)=w(n)/B(n,n);
%   Hacemos lo análogo para B'    
    for i = n-1:-1:1
        %u(i)= (w(i)-u(i+1:n)*B(i+1:n,i))/B(i,i); Original
        ind=min([n,i+p-1]);
        u(i)= (w(i)-u(i+1:ind)*B(i+1:ind,i))/B(i,i);
    end
    disp("La solución al sistema es: ");
    disp(u');
%     disp(A\b');
%     if u'~=A\b
%         error("La solución no es correcta");
%     end
    seguir=input("¿Quiere seguir resolviendo sistema? (1 para SÍ, 0 para NO): ");
%     clear b;
%     clear u;
%     clear w;
end
    
