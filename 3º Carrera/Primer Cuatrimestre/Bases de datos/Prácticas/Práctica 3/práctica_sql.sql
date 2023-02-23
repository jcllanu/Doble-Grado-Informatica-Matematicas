/abolish
/duplicates on

create table programadores(dni string primary key, nombre string, direcci�n string, tel�fono string);
insert into programadores values('1','Jacinto','Jazm�n 4','91-8888888');
insert into programadores values('2','Herminia','Rosa 4','91-7777777');
insert into programadores values('3','Calixto','Clavel 3','91-1231231');
insert into programadores values('4','Teodora','Petunia 3','91-6666666');

create table analistas(dni string primary key, nombre string, direcci�n string, tel�fono string);
insert into analistas values('4','Teodora','Petunia 3','91-6666666');
insert into analistas values('5','Evaristo','Luna 1','91-1111111');
insert into analistas values('6','Luciana','J�piter 2','91-8888888');
insert into analistas values('7','Nicodemo','Plut�n 3',NULL);

create table distribuci�n(c�digoPr string, dniEmp string, horas int, primary key (c�digoPr, dniEmp));
insert into distribuci�n values('P1','1',10);
insert into distribuci�n values('P1','2',40);
insert into distribuci�n values('P1','4',5);
insert into distribuci�n values('P2','4',10);
insert into distribuci�n values('P3','1',10);
insert into distribuci�n values('P3','3',40);
insert into distribuci�n values('P3','4',5);
insert into distribuci�n values('P3','5',30);
insert into distribuci�n values('P4','4',20);
insert into distribuci�n values('P4','5',10);

create table proyectos(c�digo string primary key, descripci�n string, dniDir string);
insert into proyectos values('P1','N�mina','4');
insert into proyectos values('P2','Contabilidad','4');
insert into proyectos values('P3','Producci�n','5');
insert into proyectos values('P4','Clientes','5');
insert into proyectos values('P5','Ventas','6');

--JUAN CARLOS LLAMS N��EZ
--CREATE VIEW vistaN AS Consulta_SQL;

CREATE VIEW empleados AS (SELECT * FROM programadores UNION SELECT * FROM analistas);

--VISTA 1
CREATE VIEW vista1 AS SELECT dni FROM SELECT * FROM programadores UNION SELECT * FROM analistas;

--VISTA 2
CREATE VIEW vista2 AS SELECT dni FROM SELECT * FROM programadores INTERSECT SELECT * FROM analistas;

--VISTA 3
CREATE VIEW vista3 AS SELECT dni FROM SELECT dni FROM empleados EXCEPT (SELECT dniEmp AS dni FROM distribuci�n UNION SELECT dniDir AS dni FROM proyectos);

--VISTA 4
CREATE VIEW vista4(c�digo) AS (SELECT c�digo FROM proyectos) EXCEPT (SELECT c�digoPr AS c�digo FROM distribuci�n JOIN analistas ON dniEmp=dni);
                                                                     
--VISTA 5
CREATE VIEW vista5 AS SELECT DISTINCT dni FROM (SELECT * FROM analistas EXCEPT SELECT * FROM programadores) JOIN proyectos ON dni=dniDir;

--VISTA 6
CREATE VIEW vista6 AS SELECT  descripci�n,nombre,horas FROM 
((programadores JOIN distribuci�n ON dni=dniEmp) JOIN 
 proyectos ON c�digo=c�digoPr);

--VISTA 7
CREATE VIEW vista7 AS SELECT DISTINCT A.tel�fono FROM empleados AS A JOIN  empleados AS B ON A.dni!=B.dni AND A.tel�fono =B.tel�fono;

--VISTA 8
CREATE VIEW vista8 AS SELECT dni FROM programadores NATURAL JOIN analistas;

--VISTA 9
CREATE VIEW vista9 AS SELECT dniEmp AS dni, sum(horas) AS horas FROM distribuci�n GROUP BY dniEmp;

--VISTA 10
CREATE VIEW vista10 AS SELECT dni, nombre, c�digoPr AS proyecto FROM empleados LEFT JOIN distribuci�n ON dniEmp=dni;

--VISTA 11 
CREATE VIEW vista11 AS SELECT dni, nombre FROM (SELECT * FROM programadores UNION SELECT * FROM analistas) WHERE tel�fono IS NULL;

--VISTA 12
CREATE VIEW vista12 AS SELECT dni FROM (empleados JOIN distribuci�n ON dni=dniEmp)
GROUP BY dni
HAVING
SUM(horas)/COUNT(dni)<(SELECT AVG(cociente) AS media FROM (SELECT SUM(horas)/COUNT(c�digoPr) AS cociente FROM distribuci�n GROUP BY c�digoPr));

--VISTA 13
CREATE VIEW vista13 AS SELECT dni FROM (SELECT dniEmp AS dni, c�digoPr FROM distribuci�n) DIVISION (SELECT c�digoPr FROM distribuci�n JOIN empleados ON dni=dniEmp AND nombre='Evaristo');

--VISTA 14
CREATE VIEW proyectosEvaristo AS SELECT c�digoPr FROM distribuci�n JOIN empleados ON dni=dniEmp AND nombre='Evaristo';

CREATE VIEW EmpleadosConProyectosEvaristo AS SELECT * FROM proyectosEvaristo NATURAL JOIN SELECT * FROM distribuci�n JOIN empleados ON dni=dniEmp;

CREATE VIEW vista14 AS SELECT dni FROM (SELECT dni, nombre, COUNT(dni) AS multiplicidad FROM EmpleadosConProyectosEvaristo GROUP BY dni, nombre HAVING multiplicidad>=(SELECT COUNT(*) FROM proyectosEvaristo));

--VISTA 15
CREATE VIEW noTrabajanConEvaristo AS SELECT * FROM  (SELECT dni FROM empleados) EXCEPT (SELECT dni FROM EmpleadosConProyectosEvaristo); 

CREATE VIEW vista15 AS SELECT c�digoPr, dni, horas*1.2 AS horas FROM distribuci�n JOIN noTrabajanConEvaristo ON dni=dniEmp;

--VISTA 16
CREATE VIEW EmpleadosJefes AS SELECT dniEmp, dniDir FROM proyectos JOIN distribuci�n ON c�digo=c�digoPr;

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