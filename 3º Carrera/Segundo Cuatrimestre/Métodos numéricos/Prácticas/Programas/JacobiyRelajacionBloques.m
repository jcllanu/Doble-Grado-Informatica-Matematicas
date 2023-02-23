Aii=diag(8*ones(1,20),0)+ diag(-1*ones(1,19),-1)+diag(-1*ones(1,19),1)+diag(-1*ones(1,18),-2)+diag(-1*ones(1,18),2);
A=[];
for i = 1:20
    %B es la fila (bloque de filas) i
    B=[];
    for j = 1:20
        if j==i
            B=[B,Aii];
        else
            Aij=(((-1)^(i+j))/(i+j))*eye(20);
            B=[B,Aij];
        end
    end
    A=[A;B];
end
b=ones(400,1);

maxIt=input("Introduzca el número máximo de iteraciones: ");
prec=input("Introduzca la precisión del test de parada: ");
modo=input("Introduzca 1 para resolver por el método de Jacobi y 0 para resolver por el método de relajación: ");
if~modo
   w_rel=input("Introduzca el parámetro de relajación (0<w<2): ");
   if w_rel<=0 || w_rel>=2
       error("El parámetro de relajación debe estar en (0,2)."); 
   end
end

cont=0;

n=20;
L = eye(n);
U = zeros(n);
B = zeros(n);

anch=3;%Semiancho de banda

if modo  %Jacobi/LU (banda)  
    for i = 1:n
        topeInf=max([1,i-anch+1]);
        U(i,i)=Aii(i,i)-L(i,topeInf:i-1)*U(topeInf:i-1,i);
        if U(i,i) == 0
            error("La matriz no admite factorización LU.");
        end
        topeBucle=min([anch+i-1,n]);
        for j =i+1:topeBucle
            topeInf=max([1,j-anch+1]);
            U(i,j)=Aii(i,j)-L(i,topeInf:i-1)*U(topeInf:i-1,j);
            L(j,i)=(Aii(j,i)-L(j,topeInf:i-1)*U(topeInf:i-1,i))/U(i,i);
        end
    end%Aii=L*U
else  %Relajación/Cholesky (banda)  
    for i = 1:n
        topeInf=max([i-anch+1,1]);
        Bii2=Aii(i,i)/w_rel-B(i,topeInf:i-1)*B(i,topeInf:i-1)';
        if Bii2 <= 0
            error("La matriz tiene algún menor principal nulo.");
        end
        B(i,i)=sqrt(Bii2);
        topeBucle=min([anch+i-1,n]);
        for j =i+1:topeBucle
            topeInf=max([j-anch+1,1]);
            B(j,i)=(Aii(i,j)/w_rel-B(i,topeInf:i-1)*B(j,topeInf:i-1)')/B(i,i);
        end
    end%Aii/w=B*B'          
end

%Aquí la matriz Aii ya está factorizada LU/Cholesky

u_k_1=zeros(400,1);%Vector columna
u_k=zeros(400,1);%para que entre en la primera vuelta
p=20;

while cont<maxIt && norm(u_k_1-u_k)>=prec*norm(u_k_1)
    u_k = u_k_1;
   for ind = 1:p   
       if modo  %Jacobi/LU (banda)
   %Resolver el sistema Du^k+1=b+(E+F)u^k           
   %Resolver el sistema Aii*ui=bi-Ai(1,i-1)*u(1,i-1)-Ai(i+1,p)*u(i+1,p)
   %                        ^--u^k+1        ^---u^k------------^
   %cambiando i por ind
        segMiembro=b(n*(ind-1)+1:n*ind);%bi
        segMiembro=segMiembro-A(n*(ind-1)+1:n*ind,1:n*(ind-1))*u_k(1:n*(ind-1));%-Ai(1,i-1)*u(1,i-1)
        segMiembro=segMiembro-A(n*(ind-1)+1:n*ind,n*ind+1:n*p)*u_k(n*ind+1:n*p);%-Ai(i+1,p)*u(i+1,p)
         %Resolver por remonte LU*ui=segMiembro (LU=Aii es igual p.t. i)
            w(1) = segMiembro(1);
            for i =2:n
                topeInf=max([1,i-anch+1]);
                w(i)= segMiembro(i)-L(i,topeInf:i-1)*w(topeInf:i-1)';
            end
            ui(n)=w(n)/U(n,n);
            for i = n-1:-1:1
                topeSup=min([n,i+anch-1]);
                ui(i)= (w(i)-U(i,i+1:topeSup)*ui(i+1:topeSup)')/U(i,i);
            end
            u_k_1(n*(ind-1)+1:n*ind)=ui';
            
       else  %Relajación/Cholesky (banda)
   %Resolver el sistema (D/w -E)u^k+1=b+(((1-w)/w)D+F)u^k      
   %Resolver el sistema (Aii/w)*ui=bi+(1-w)/w)Aii*ui-Ai(1,i-1)*u(1,i-1)-Ai(i+1,p)*u(i+1,p)
   %                            ^--u^k+1           ^---u^k     ^--u^k+1           ^---u^k
   %cambiando i por ind
        segMiembro=b(n*(ind-1)+1:n*ind);%bi
        segMiembro=segMiembro+((1-w_rel)/w_rel)*Aii*u_k(n*(ind-1)+1:n*ind);%(1-w)/w)Aii*ui
        segMiembro=segMiembro-A(n*(ind-1)+1:n*ind,1:n*(ind-1))*u_k_1(1:n*(ind-1));%-Ai(1,i-1)*u(1,i-1)
        segMiembro=segMiembro-A(n*(ind-1)+1:n*ind,n*ind+1:n*p)*u_k(n*ind+1:n*p);%-Ai(i+1,p)*u(i+1,p)
         %Resolver por remonte BB'*ui=segMiembro
            w(1) = segMiembro(1)/B(1,1);
            for i =2:n
                topeInf=max([1,i-anch+1]);
                w(i)= (segMiembro(i)-B(i,topeInf:i-1)*w(topeInf:i-1)')/B(i,i);
            end
            ui(n)=w(n)/B(n,n);  
            for i = n-1:-1:1
                topeSup=min([n,i+anch-1]);
                ui(i)= (w(i)-ui(i+1:topeSup)*B(i+1:topeSup,i))/B(i,i);
            end
            u_k_1(n*(ind-1)+1:n*ind)=ui';
       end
   end
    cont=cont+1;
end

if norm(u_k_1-u_k)>=prec*norm(u_k_1)
    disp("Se ha alcanzado el número máximo de iteraciones ("+maxIt+") y la solución vale: ");
    disp(u_k_1);
else
    disp("Se ha alcanzado la precisión en "+cont+" iteraciones y la solución vale:");
    disp(u_k_1);
end;
%disp(norm(A\b-u_k_1));