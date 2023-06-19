%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
%A=[0,1,2,1;1,2,1,3;1,1,-1,1;0,1,8,12]
%b=[1,0,5,2]
A=input("Introduzca una matriz cuadrada A: ");
A_original=A;
[n,m]=size(A);
if n~=m 
    error("La matriz introducida no es cuadrada."); 
end
punt = 1:n;
for k = 1:n-1
    [m,p]=max(abs(A(punt(k:n),k)));%Guardamos en m el maximo en valor 
    %absoluto del trozo apropiado de la columna k-esima y en p el índice
    %donde se alcanza dicho máximo
    if m==0       
        error("La matriz no tiene rango máximo."); 
    end
    %transformamos p porque p está en {1,2,...n-k+1} y lo queremos en
    %{k,k+1,...n}
    p=p+k-1;
    %intercambiamos las filas con los punteros
    aux = punt(p);
    punt(p) = punt(k);
    punt(k) = aux;
%     disp("-------------------------------")
%     for i =1:n
%         disp(A(punt(i),:))
%     end
%     disp("-------------------------------")

    for i = k+1:n
        A(punt(i),k)=A(punt(i),k)/A(punt(k),k);%Guardo los multiplicadores 
        %(lo que había partido por el pivote)
    end
    %Restamos a cada trozo de fila el trozo de la fila del pivote por el
    %multiplicador
    for j = k+1:n
        A(punt(j),k+1:n) = A(punt(j),k+1:n)-A(punt(j),k)*A(punt(k),k+1:n);
    end
%     for i =1:n
%         disp(A(punt(i),:))
%     end
end
%No hace falta tratar la última columna pero comprobamos que el elemento no
%es cero porque en este caso la matriz no tiene rango máximo
if A(punt(n), n)==0       
    error("La matriz no tiene rango máximo."); 
end
% disp(A);
% disp(punt);


seguir = 1;
while seguir
    b=input("Introduzca un vector b para resolver el sistema Au=b: ");
    if n~=length(b)
        error("El vector b debe ser un vector de n componentes."); 
    end
%     Au=b <=> PAu=Pb <=> LUu=Pb <=> Lw=Pb && Uu=w

%   Remonte triangular inferior con unos en la diagonal
    w(1) = b(punt(1));
    
    for i =2:n
        w(i)= b(punt(i))-A(punt(i),1:i-1)*w(1:i-1)';
    end
%     disp(w);
%   Remonte triangular superior
    u(n)=w(n)/A(punt(n),n);
    for i = n-1:-1:1
        u(i)= (w(i)-A(punt(i),i+1:n)*u(i+1:n)')/A(punt(i),i);
    end
    disp("La solución al sistema es: ");
    disp(u');
%     disp(A_original\b');
%     if u'~=A_original\b'
%         error("La solución no es correcta");
%     end
    seguir=input("¿Quieres seguir resolviendo sistema? (1 para SÍ, 0 para NO): ");
%     clear b;
%     clear u;
end
    
