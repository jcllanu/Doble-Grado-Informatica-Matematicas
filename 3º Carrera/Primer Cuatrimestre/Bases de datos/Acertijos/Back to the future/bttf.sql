
/duplicates on
--JUAN CARLOS LLAMAS N��EZ
CREATE VIEW vista1 AS SELECT COUNT(fechas.fecha) AS count FROM intervalos,fechas WHERE intervalos.desde<=fechas.fecha and fechas.fecha<=intervalos.hasta GROUP BY fechas.fecha ORDER BY fechas.fecha;
SELECT * FROM vista1;