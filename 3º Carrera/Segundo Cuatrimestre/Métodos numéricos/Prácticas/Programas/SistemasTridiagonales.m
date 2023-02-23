%Juan Carlos Llamas Núñez 3ºDG Mat-Inf MN
function [x] = SistemasTridiagonales(a,b,c,d)
n=length(d);
% if ~(length(a)+1==n &&length(b)==n && length(c)+1==n)
%     error("Las dimensiones de los vectores introducidos no son correctas")
% end
m(1) = b(1);
% if m(1)==0
%     error("La matriz no tiene todos los menores principales distintos de 0")
% end
g(1) = d(1)/m(1);
for i = 2:n
    m(i) = b(i)-c(i-1)*a(i-1)/m(i-1);%Cambiamos a(i) por a(i-1) porque 
    %nuestro vector a va de 1 a n-1 en lugar de ir de 2 a n como en el ejercicio
%    if m(i)==0
%         error("La matriz no tiene todos los menores principales distintos de 0")
%     end
    %igual aquí
    g(i) = (d(i)-g(i-1)*a(i-1))/m(i); 
end
x(n)=g(n);
for i=n-1:-1:1
    x(i)=g(i)-c(i)*x(i+1)/m(i);
end
end

%x=SistemasTridiagonales([1,2,3],[1,0,1,0],[3,4,5],[5,6,8,9])
%Sol: [-6, 3.6667, 3, -0.4667]
