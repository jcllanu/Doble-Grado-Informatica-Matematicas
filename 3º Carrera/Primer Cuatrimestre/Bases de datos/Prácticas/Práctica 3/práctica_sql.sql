/abolish
/duplicates on

create table programadores(dni string primary key, nombre string, dirección string, teléfono string);
insert into programadores values('1','Jacinto','Jazmín 4','91-8888888');
insert into programadores values('2','Herminia','Rosa 4','91-7777777');
insert into programadores values('3','Calixto','Clavel 3','91-1231231');
insert into programadores values('4','Teodora','Petunia 3','91-6666666');

create table analistas(dni string primary key, nombre string, dirección string, teléfono string);
insert into analistas values('4','Teodora','Petunia 3','91-6666666');
insert into analistas values('5','Evaristo','Luna 1','91-1111111');
insert into analistas values('6','Luciana','Júpiter 2','91-8888888');
insert into analistas values('7','Nicodemo','Plutón 3',NULL);

create table distribución(códigoPr string, dniEmp string, horas int, primary key (códigoPr, dniEmp));
insert into distribución values('P1','1',10);
insert into distribución values('P1','2',40);
insert into distribución values('P1','4',5);
insert into distribución values('P2','4',10);
insert into distribución values('P3','1',10);
insert into distribución values('P3','3',40);
insert into distribución values('P3','4',5);
insert into distribución values('P3','5',30);
insert into distribución values('P4','4',20);
insert into distribución values('P4','5',10);

create table proyectos(código string primary key, descripción string, dniDir string);
insert into proyectos values('P1','Nómina','4');
insert into proyectos values('P2','Contabilidad','4');
insert into proyectos values('P3','Producción','5');
insert into proyectos values('P4','Clientes','5');
insert into proyectos values('P5','Ventas','6');

--JUAN CARLOS LLAMS NÚÑEZ
--CREATE VIEW vistaN AS Consulta_SQL;

CREATE VIEW empleados AS (SELECT * FROM programadores UNION SELECT * FROM analistas);

--VISTA 1
CREATE VIEW vista1 AS SELECT dni FROM SELECT * FROM programadores UNION SELECT * FROM analistas;

--VISTA 2
CREATE VIEW vista2 AS SELECT dni FROM SELECT * FROM programadores INTERSECT SELECT * FROM analistas;

--VISTA 3
CREATE VIEW vista3 AS SELECT dni FROM SELECT dni FROM empleados EXCEPT (SELECT dniEmp AS dni FROM distribución UNION SELECT dniDir AS dni FROM proyectos);

--VISTA 4
CREATE VIEW vista4(código) AS (SELECT código FROM proyectos) EXCEPT (SELECT códigoPr AS código FROM distribución JOIN analistas ON dniEmp=dni);
                                                                     
--VISTA 5
CREATE VIEW vista5 AS SELECT DISTINCT dni FROM (SELECT * FROM analistas EXCEPT SELECT * FROM programadores) JOIN proyectos ON dni=dniDir;

--VISTA 6
CREATE VIEW vista6 AS SELECT  descripción,nombre,horas FROM 
((programadores JOIN distribución ON dni=dniEmp) JOIN 
 proyectos ON código=códigoPr);

--VISTA 7
CREATE VIEW vista7 AS SELECT DISTINCT A.teléfono FROM empleados AS A JOIN  empleados AS B ON A.dni!=B.dni AND A.teléfono =B.teléfono;

--VISTA 8
CREATE VIEW vista8 AS SELECT dni FROM programadores NATURAL JOIN analistas;

--VISTA 9
CREATE VIEW vista9 AS SELECT dniEmp AS dni, sum(horas) AS horas FROM distribución GROUP BY dniEmp;

--VISTA 10
CREATE VIEW vista10 AS SELECT dni, nombre, códigoPr AS proyecto FROM empleados LEFT JOIN distribución ON dniEmp=dni;

--VISTA 11 
CREATE VIEW vista11 AS SELECT dni, nombre FROM (SELECT * FROM programadores UNION SELECT * FROM analistas) WHERE teléfono IS NULL;

--VISTA 12
CREATE VIEW vista12 AS SELECT dni FROM (empleados JOIN distribución ON dni=dniEmp)
GROUP BY dni
HAVING
SUM(horas)/COUNT(dni)<(SELECT AVG(cociente) AS media FROM (SELECT SUM(horas)/COUNT(códigoPr) AS cociente FROM distribución GROUP BY códigoPr));

--VISTA 13
CREATE VIEW vista13 AS SELECT dni FROM (SELECT dniEmp AS dni, códigoPr FROM distribución) DIVISION (SELECT códigoPr FROM distribución JOIN empleados ON dni=dniEmp AND nombre='Evaristo');

--VISTA 14
CREATE VIEW proyectosEvaristo AS SELECT códigoPr FROM distribución JOIN empleados ON dni=dniEmp AND nombre='Evaristo';

CREATE VIEW EmpleadosConProyectosEvaristo AS SELECT * FROM proyectosEvaristo NATURAL JOIN SELECT * FROM distribución JOIN empleados ON dni=dniEmp;

CREATE VIEW vista14 AS SELECT dni FROM (SELECT dni, nombre, COUNT(dni) AS multiplicidad FROM EmpleadosConProyectosEvaristo GROUP BY dni, nombre HAVING multiplicidad>=(SELECT COUNT(*) FROM proyectosEvaristo));

--VISTA 15
CREATE VIEW noTrabajanConEvaristo AS SELECT * FROM  (SELECT dni FROM empleados) EXCEPT (SELECT dni FROM EmpleadosConProyectosEvaristo); 

CREATE VIEW vista15 AS SELECT códigoPr, dni, horas*1.2 AS horas FROM distribución JOIN noTrabajanConEvaristo ON dni=dniEmp;

--VISTA 16
CREATE VIEW EmpleadosJefes AS SELECT dniEmp, dniDir FROM proyectos JOIN distribución ON código=códigoPr;

CREATE VIEW jefe(dniEmp,dniDir) AS 
SELECT dniEmp,dniDir FROM EmpleadosJefes
UNION
SELECT  A.dniEmp,B.dniDir FROM jefe AS A JOIN jefe AS B ON A.dniDir=B.dniEmp;

CREATE VIEW EmpleadosJefesNombre AS SELECT dniEmp,dniDir,nombre AS nombreJefe FROM jefe JOIN empleados ON dniDir=dni;
CREATE VIEW EmpleadosJefesNombres AS SELECT dniEmp,dniDir,nombreJefe, nombre AS nombreEmp FROM EmpleadosJefesNombre JOIN empleados ON dniEmp=dni;
CREATE VIEW vista16 AS SELECT nombreEmp as nombre FROM EmpleadosJefesNombres WHERE nombreJefe='Evaristo' AND nombreEmp!='Evaristo';





SELECT * FROM vista1;
SELECT * FROM vista2;
SELECT * FROM vista3;
SELECT * FROM vista4;
SELECT * FROM vista5;
SELECT * FROM vista6;
SELECT * FROM vista7;
SELECT * FROM vista8;
SELECT * FROM vista9;
SELECT * FROM vista10;
SELECT * FROM vista11;
SELECT * FROM vista12;
SELECT * FROM vista13;
SELECT * FROM vista14;
SELECT * FROM vista15;
SELECT * FROM vista16;