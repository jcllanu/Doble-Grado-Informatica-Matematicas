/abolish
/duplicates on
-- Datos: David Pérez Asensio
-- "With 50 million copies sold, not only is Bing Crosby's "White Christmas" the best-selling Christmas song of all time, it's also the best-selling single ever, according to Guinness World Records." (https://www.countryliving.com/life/news/a45720/white-christmas-song-history/)
-- 10/10/2015


CREATE TABLE hits (
  theme varchar(50) NOT NULL,
  copies int NOT NULL,
  PRIMARY KEY (theme, copies));

INSERT INTO hits (theme, copies) VALUES
('I Will Always Love You', 20),
('If I Didn''t Care', 19),
('In the Summertime', 31),
('It''s Now or Never', 20),
('My Heart will Go On', 25),
('Rock Around the Clock', 25),
('Silent Night', 30),
('We Are the World', 20),
('White Christmas', 50);


--JUAN CARLOS LLAMAS NÚÑEZ   3ºDG

--Guardamos en numCopias todos los numeros de copias distintos
CREATE VIEW numCopias AS SELECT DISTINCT copies FROM hits;

--A cada numero de copias le asignamos la posición siendo 1 el mayor número de copias, 2 el segundo...
--Esto lo hacemos con un join en el que contamos el numero de veces que una copia es menor o igual que cualquiera de las copias.
--El mayor numero de copias es solo menor o igual que él mismo (le asignamos un 1), el segundo mayor número de copias es menor o igual que el mayor número de copias y él mismo (le asignamos un 2) ...
CREATE VIEW posicionAsociada AS SELECT A.copies, COUNT(A.copies) AS n FROM (SELECT * FROM numCopias AS A JOIN SELECT * FROM numCopias AS B ON A.copies<=B.copies ) GROUP BY A.copies;

--Solo falta juntar la información que tenemos con un join 
CREATE VIEW vista1(copies,theme,n) AS SELECT hits.copies, theme, n FROM hits JOIN posicionAsociada ON hits.copies=posicionAsociada.copies ORDER BY n ASC, theme ASC;


SELECT * FROM vista1;


