/abolish
/multiline on
/duplicates on
/type_casting off
/datalog

CREATE TABLE jugadores (
  nick STRING PRIMARY KEY,
  edad INTEGER CHECK (edad>0),
  ciudad STRING);

CREATE TABLE juegos (
  nombre STRING PRIMARY KEY,
  tipo STRING CHECK (tipo IN ('puzzle','estrategia','plataformas')),
  niveles INTEGER CHECK (niveles BETWEEN 1 AND 10));

CREATE TABLE partidas (
  juego STRING REFERENCES juegos(nombre),
  nick STRING REFERENCES jugadores(nick),
  nivel INTEGER CHECK (nivel BETWEEN 1 AND 10),
  superado STRING CHECK (superado IN ('S', 'N')),
  tiempo NUMBER(8,1) CHECK (tiempo>0),
  PRIMARY KEY (juego, nick, nivel));

INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Azan',  20, 'Madrid');
INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Basra', 18, 'Segovia');
INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Cruc',  23, 'Madrid');
INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Eos',   60, 'Sevilla');
INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Luz',   20, 'Oviedo');
INSERT INTO jugadores(nick, edad, ciudad) VALUES ('Zorai', 10, 'Sevilla');

INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Tetris',      'puzzle',      10);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Bubble',      'puzzle',       8);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Candy Crush', 'puzzle',      10);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Mine',        'puzzle',       7);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('The Room',    'puzzle',       5);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Lyne',        'puzzle',      10);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Anomaly',     'estrategia',   2);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Age',         'estrategia',  10);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Empire',      'estrategia',   6);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('Oscura',      'plataformas',  4);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('BadLand',     'plataformas',  4);
INSERT INTO juegos (nombre, tipo, niveles) VALUES ('RayMan',      'plataformas', 10);

INSERT INTO partidas(juego, nick, nivel, superado)         VALUES ('Bubble',  'Azan',  1, 'N');
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Bubble',  'Basra', 1, 'S',  10.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Mine',    'Azan',  1, 'S',  15.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Mine',    'Basra', 1, 'S',  25.0);
INSERT INTO partidas(juego, nick, nivel, superado)         VALUES ('Lyne',    'Cruc',  1, 'N');
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Lyne',    'Eos',   1, 'S',  50.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('RayMan',  'Zorai', 1, 'S',  30.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('RayMan',  'Eos',   1, 'S',  30.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Eos',   1, 'S',  30.0);
INSERT INTO partidas(juego, nick, nivel, superado)         VALUES ('Age',     'Azan',  1, 'N');
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Age',     'Basra', 1, 'S',  20.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Eos',   2, 'S',  40.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Eos',   3, 'S',  50.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Eos',   4, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Azan',  1, 'S', 140.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Azan',  2, 'S', 140.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Azan',  3, 'S', 150.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('BadLand', 'Azan',  4, 'S', 160.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  1, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  2, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  3, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  4, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  5, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Empire',  'Azan',  6, 'S',  60.0);
INSERT INTO partidas(juego, nick, nivel, superado)         VALUES ('Tetris',  'Azan',  1, 'N');
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Basra', 1, 'S',  10.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Azan',  2, 'S',  15.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Basra', 2, 'S',  25.0);
INSERT INTO partidas(juego, nick, nivel, superado)         VALUES ('Tetris',  'Cruc',  1, 'N');
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Eos',   1, 'S',  50.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Zorai', 1, 'S',  30.0);
INSERT INTO partidas(juego, nick, nivel, superado, tiempo) VALUES ('Tetris',  'Eos',   2, 'S',  30.0);

--JUAN CARLOS LLAMAS NÚÑEZ

--VISTA 1
CREATE VIEW v1 AS SELECT tipo, max(tiempo) AS tiempo FROM partidas JOIN juegos ON nombre=juego WHERE superado='S' and nivel=1 GROUP BY tipo ORDER BY tipo;

--VISTA 2
CREATE VIEW v2 AS SELECT juego, count(*) AS jugadores FROM partidas JOIN juegos ON nombre=juego WHERE superado='S' and nivel=niveles GROUP BY juego ORDER BY juego;

--VISTA 3
CREATE VIEW promedioNiveles AS SELECT tipo AS tipo2, avg(niveles) AS promedio FROM juegos GROUP BY tipo;
CREATE VIEW v3 AS SELECT nombre AS juego, niveles, promedio FROM juegos JOIN promedioNiveles ON tipo=tipo2 ORDER BY juego;

--VISTA 4
CREATE VIEW jugadoresTetris AS SELECT DISTINCT nick AS nick2 FROM partidas WHERE juego='Tetris';
CREATE VIEW v4 AS SELECT nick, edad, ciudad FROM jugadores JOIN jugadoresTetris ON nick=nick2 WHERE edad=(SELECT max(edad) FROM jugadores JOIN jugadoresTetris ON nick=nick2) ORDER BY nick;

--VISTA 5
CREATE VIEW partidasFinalesSuperadas AS SELECT juego AS juego2, nick AS nick2, niveles FROM partidas JOIN juegos ON nombre=juego WHERE niveles=nivel and superado='S';

CREATE VIEW todasPartidasDeFinalesSuperadas AS SELECT juego, nick, niveles,count(*) AS nivelesSuperados FROM partidas JOIN partidasFinalesSuperadas ON juego=juego2 and nick=nick2 WHERE superado='S' GROUP BY juego, nick, niveles;

CREATE VIEW v5 AS SELECT nick,juego AS nombre FROM todasPartidasDeFinalesSuperadas WHERE niveles<>nivelesSuperados ORDER BY nick, nombre; 

--VISTA 6
CREATE VIEW juegosBasra AS SELECT DISTINCT juego FROM partidas WHERE nick='Basra';
CREATE VIEW v6 AS SELECT nick FROM (SELECT nick, juego FROM partidas) DIVISION juegosBasra WHERE nick<>'Basra' ORDER BY nick;

--VISTA 7

CREATE VIEW numJuegos AS SELECT count(*) AS stop FROM juegos;
CREATE VIEW recursion(n,stop) AS SELECT 1, stop FROM numJuegos UNION SELECT n+1,stop FROM recursion WHERE n<stop;
CREATE VIEW v7 AS SELECT SUBSTR('abcdefghijklmnñopqrstuvwxyz',n,1) AS letra FROM recursion;


SELECT * FROM v1;
SELECT * FROM v2;
SELECT * FROM v3;
SELECT * FROM v4;
SELECT * FROM v5;
SELECT * FROM v6;
SELECT * FROM v7;
