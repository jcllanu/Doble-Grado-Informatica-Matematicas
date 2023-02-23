%%Juan Carlos Llamas Núñez 4ºDG Mat-Inf

elimina1([ ],X,[ ]).
elimina1([X|R],Y,NR) :- Y == X, elimina1(R,Y, NR).
elimina1([X|R],Y,[X|NR]) :- Y \== X, elimina1(R,Y,NR).

elimina2([ ],X,[ ]).
elimina2([X|R],Y,NR) :- Y = X, elimina2(R,Y, NR).
elimina2([X|R],Y,[X|NR]) :- Y \= X, elimina2(R,Y,NR).

elimina3([ ],X,[ ]).
elimina3([X|R],X,NR) :- elimina3(R,X,NR).
elimina3([X|R],Y,[X|NR]) :- Y \== X, elimina3(R,Y,NR).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%1.- Utilizando la estructura de ´arbol binario definida en clase y el if then else de Prolog, programa el predicado:
%maximo(A, X) ↔ A es un ´arbol binario de n´umeros enteros positivos dado y X es el elemento m´aximo
%de sus nodos. X vale 0 si el ´arbol es vac´ıo.

%Utilizamos if-then-else para programar la función máximo entre dos elementos, que después utilizamos para calcular
%el máximo entre la raíz, el máximo del hijo izquierdo y el máximo del hijo derecho

max(A,B,C):- A>B -> A=C ; B=C.
maximo(void,0).
maximo(arbol(X,I,D),M):- maximo(I,MI),maximo(D,MD), max(X,MI,Aux), max(Aux,MD,M).

%2. Define en Prolog el predicado:
%sublista(SXs,Xs) ↔ SXs es una sublista de la lista Xs.
%Usando los metapredicados de recolecci´on de respuestas programa:
%sublistas(LSX,Xs) ↔ LSX es la lista que contiene a todas las sublistas de Xs.

%Asumimos que sublista quiere decir una lista contenida en la listas oredenada y sin saltos, es decir, [1,2] es
%una sublista de [0,1,2,3] pero [1,3] no es una sublista de [0,1,2,3] porque faltaría el 2 entre el 1 y el 3

sublistaDesdeAhora([],X).
sublistaDesdeAhora([X|Xs],[X|Ys]):-sublistaDesdeAhora(Xs,Ys).
sublista([],X).
sublista([X|Xs],[X|Ys]):-sublista([X|Xs],Ys).
sublista([X|Xs],[X|Ys]):-sublistaDesdeAhora(Xs,Ys).
sublista([X|Xs],[Y|Ys]):-X\==Y,sublista([X|Xs],Ys).

sublistas(LSX,Xs):- setof(X,sublista(X,Xs),LSX).

%3.-Programa en Prolog el siguiente predicado:
%aplana(Xss, Xs) ↔ Xs es la lista que resulta de eliminar todos los corchetes en los subt´erminos de
%la lista Xss que sean listas. Equivale a iterar concat de Haskell, pero ten en cuenta que en Prolog los elementos de las listas no tienen por qu´e ser todos del mismo tipo. Por ejemplo, el objetivo
%aplana([[1],[a,b],[],2,[[c],3]],Xs). da como resultado Xs = [1,a,b,2,c,3].
%¿Sabes hacerlo sin utilizar predicados predefinidos de Prolog?

aplana(Xss,Xs):-aplanaAcc(Xss,Xs,[]).
aplanaAcc([],Xs,Xs).
aplanaAcc([X|Xss],Xs,Acc):-is_list(X)->(aplana(X,Aux),append(Acc,Aux,NAcc),aplanaAcc(Xss,Xs,NAcc));(append(Acc,[X],NAcc), aplanaAcc(Xss,Xs,NAcc)).
%El único uso que hemos hecho de funciones de Prolog ha sido para saber si algo es una lista, que lo sabemos programar y el append que también lo sabemos programar

%4. Programa en Prolog una versi´on recursiva para resolver el problema de las torres de Hanoi. Para ello,
%define un predicado:
%hanoi(N, A, B, C, M) donde N es el n´umero de fichas que hay que mover de la torre inicial, A es el
%nombre de la torre inicial, B es el nombre de la torre final, C es el nombre de la torre auxiliar y M es la
%secuencia de pares de movimientos de una torre a otra, hasta conseguir la traslaci´on de todas las fichas.
%Por ejemplo, para trasladar dos fichas de las torres con nombres, ini, fin, aux, respectivamente, la lista
%de movimientos ser´ıa: [(ini, aux), (ini, fin), (aux, fin)]

%Cuando solo hay una pieza hay que llevarla de la varilla inicio a la varilla final

hanoi(1,A,B,C,[(A,B)]):-!.

%Si hay más de una pieza:
%1.-Llevamos las N-1 piezas más pequeñas de la varilla inicial a la varilla auxiliar recursivamente y respetando los tamaños, es decir,
% resolvemos el problema de las torres de hanoi para tamaño N-1 cambiando las varillas Auxiliar por Final.
%2.-Llevamos la pieza más grande de la inicial a la final
%3.-Recursivamente llevamos las N-1 piezas que están en la varilla auxiliar a la varilla final resolviendo el problema de 
%las torres de hanoi para tamaño N-1 y cambiando las varillas Inicial por la Auxiliar.

hanoi(N,Ini,Fin,Aux,M):-Nbis is N-1, hanoi(Nbis,Ini,Aux,Fin,M1),append(M1,[(Ini,Fin)],M2),hanoi(Nbis,Aux,Fin,Ini,M3),append(M2,M3,M).
