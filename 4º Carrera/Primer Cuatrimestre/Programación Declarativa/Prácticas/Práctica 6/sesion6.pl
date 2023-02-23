%Juan Carlos Llamas Núñez 4º DG Mat-Inf
%
% Tenemos un conjunto de fichas apiladas en tres columnas (o pilas) sobre una mesa.
%  según el esquema siguiente:
%
%   d
%   c   g
%   b   f   i
%   a   e   h
%  -----------
% Esta información se representa mediante los siguientes predicados.
% sobre(X,Y) <-> la ficha X esta sobre la ficha Y.
% izquierda(X,Y) <-> la ficha X esta inmediatamente a la izquierda 
% de la ficha Y.
% cima(X) <-> la ficha X esta en la cima de una columna.

% Hechos:

cima(d).
sobre(d,c).
sobre(c,b).
sobre(b,a).


cima(g).
sobre(g,f).
sobre(f,e).


cima(i).
sobre(i,h).


izquierda(c,g).

izquierda(b,f).
izquierda(f,i).

izquierda(a,e).
izquierda(e,h).

% Se definen nuevos predicados para manejar esta información.


% por_encima_de(X,Y) <-> la ficha X esta en la misma pila que la ficha Y y más arriba.
% uso: por_encima_de(e/s,e/s).
por_encima_de(X,Y) :- sobre(X,Y).
por_encima_de(X,Y) :- sobre(X,Z), por_encima_de(Z,Y).

% por_encima_de_ERROR(X,Y).
%Llamadas recursivas infinitas cuando no hay más soluciones o el objetivo es falso.
% uso: por_encima_de_ERROR(e/s, e/s). 
por_encima_de_ERROR(X,Y) :- sobre(X,Y).
por_encima_de_ERROR(X,Y) :- por_encima_de_ERROR(X,Z), sobre(Z,Y).


% pila_izquierda(X,Y) <-> la ficha X está en la pila situada inmediatamente a la izquierda de 
%la pila en la que está la ficha Y
% uso: pila_izquierda(e/s,e/s)
pila_izquierda(X,Y) :- izquierda(X,Y).				% misma altura
pila_izquierda(X,Y) :- izquierda(Z,Y), por_encima_de(X,Z).	% X mas arriba que Y
pila_izquierda(X,Y) :- izquierda(X,Z), por_encima_de(Y,Z).	% X mas abajo que Y

 
% por_arriba(X,L) <-> L es la lista que contiene todas las fichas que están por encima de la ficha X.
% uso:  por_arriba(e/s,e/s).
por_arriba_ls(X,[]) :- cima(X).
por_arriba_ls(X,[Y|L]) :- sobre(Y,X), por_arriba_ls(Y,L).
 


% poner_encima(X,Y) <-> la ficha X se puede poner encima de la ficha Y  
% si ambas están en la cima de su pila, y en pilas contiguas.
% uso: poner_encima(e/s,e/s)
poner_encima(X,Y) :- cima(X), cima(Y), pilas_contiguas(X,Y).


% pilas_contiguas(X,Y) <-> la pila de la ficha X y la de la ficha Y están una al lado de la otra.
% uso: pilas_contiguas(e/s,e/s).
pilas_contiguas(X,Y) :- pila_izquierda(X,Y).
pilas_contiguas(X,Y) :- pila_izquierda(Y,X).

%1.-
%mas_por_encima_que(X,Y) <-> la ficha X tiene más fichas por encima que la ficha Y, no necesariamente en
%la misma pila, ni en pilas contiguas

mas_elementos([X|Xs],[]).
mas_elementos([X|Xs],[Y|Ys]):-mas_elementos(Xs,Ys).

mas_por_encima_que(X,Y):-por_arriba_ls(X,Xs),por_arriba_ls(Y,Ys),mas_elementos(Xs,Ys).

%2.-
%intercala(L1,L2,L) <-> L1 y L2 son dos listas y L es la lista resultante de intercalar los elementos de L1 y
%L2 y cuya longitud es igual al doble de la lista de menor longitud.

intercala([],X,[]).
intercala(X,[],[]).
intercala([X|Xs],[Y|Ys],[X,Y|Zs]):-intercala(Xs,Ys,Zs).

%3.-
%simetricas(Xss,Yss) <-> Xss es una lista de listas y Yss es la lista de elementos de Xss que son listas
%simétricas.

es_lista([]).
es_lista([X|Xs]):-es_lista(Xs).

simetricas([],[]).
simetricas([X|Xss],[X|Yss]):-es_lista(X),invertir2(X,[],X),simetricas(Xss,Yss).
simetricas([X|Xss],Yss):-es_lista(X),simetricas(Xss,Yss).

invertir2([],Xs,Xs).
invertir2([X|Xs],Ys,Zs):-invertir2(Xs,[X|Ys],Zs).

%4.-
%rama(X,Y) <-> X es una lista con los elementos de una rama del árbol Y, en orden según su profundidad.
arbol_binario(void).
arbol_binario(arbol(_,I,D)):-arbol_binario(I),arbol_binario(D).

rama([],void).
rama([X|Xs],arbol(X,I,D)):-arbol_binario(I),arbol_binario(D),rama(Xs,I).
rama([X|Xs],arbol(X,I,D)):-arbol_binario(I),arbol_binario(D),rama(Xs,D).