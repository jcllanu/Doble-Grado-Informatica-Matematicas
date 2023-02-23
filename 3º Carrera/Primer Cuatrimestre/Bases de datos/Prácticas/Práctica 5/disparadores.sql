DROP TABLE contiene;
DROP TABLE pedidos;
DROP TABLE auditoría;
DROP VIEW vista_pedidos;

CREATE TABLE pedidos(código CHAR(6) NOT NULL, fecha CHAR(10) NOT NULL, 
importe NUMBER(6,2) DEFAULT 0, cliente CHAR(20) NOT NULL, notas CHAR(1024),
especial CHAR(1) NOT NULL, CHECK (especial in('S','N')), CHECK (importe>=0),
PRIMARY KEY(código));

CREATE VIEW vista_pedidos AS SELECT * FROM pedidos;

CREATE TABLE contiene(pedido CHAR(6) REFERENCES pedidos(código), plato 
CHAR(20) NOT NULL, precio NUMBER(6,2) NOT NULL, unidades NUMBER(2,0) NOT NULL,
CHECK (precio>=0), CHECK (unidades>0), PRIMARY KEY(pedido,plato));

CREATE TABLE auditoría(operación CHAR(6) NOT NULL, tabla CHAR(50) NOT NULL,
fecha CHAR(10) NOT NULL, hora CHAR(8) NOT NULL,

CHECK (operación in('DELETE','INSERT','UPDATE')));
 --Esta tabla no contiene Primary key porque puedes hacer operaciones 
 --simultaneas del mismo tipo en una misma tabla y en un mismo instante
 

CREATE OR REPLACE TRIGGER tr_pedidos
AFTER INSERT OR DELETE OR UPDATE ON pedidos
BEGIN
    IF DELETING THEN
        INSERT INTO auditoría VALUES('DELETE','pedidos',
        to_char(sysdate,'dd/mm/yyyy'),to_char(sysdate,'hh:mi:ss'));
    ELSIF INSERTING THEN
        INSERT INTO auditoría VALUES('INSERT','pedidos',
        to_char(sysdate,'dd/mm/yyyy'),to_char(sysdate,'hh:mi:ss'));
    ELSIF UPDATING THEN
        INSERT INTO auditoría VALUES('UPDATE','pedidos',
        to_char(sysdate,'dd/mm/yyyy'),to_char(sysdate,'hh:mi:ss'));
    END IF; 
END tr_pedidos;
/

BEGIN
    INSERT INTO pedidos VALUES('123456','11/12/2020',0,'Juan Carlos',
    'Entrar por la chimenea','S');
    UPDATE pedidos SET importe=importe+1 WHERE código='123456';
    DELETE FROM pedidos WHERE código='123456';
END;
/



CREATE OR REPLACE TRIGGER tr_contiene
AFTER INSERT OR DELETE OR UPDATE ON contiene
FOR EACH ROW
BEGIN
    IF DELETING THEN
        UPDATE pedidos SET importe= importe - :OLD.precio*:OLD.unidades
        WHERE :OLD.pedido=código;
    ELSIF INSERTING THEN
        UPDATE pedidos SET importe=:NEW.precio*:NEW.unidades
        WHERE :NEW.pedido=código;
    ELSIF UPDATING THEN
        UPDATE pedidos SET importe=importe-:OLD.precio*:OLD.unidades +
        :NEW.precio*:NEW.unidades WHERE :OLD.pedido=código;
    END IF; 
END tr_contiene;
/
BEGIN
    INSERT INTO pedidos VALUES('123456','11/12/2020',0,'Juan Carlos',
    'Entrar por la chimenea','S');
    INSERT INTO contiene VALUES('123456','Tortilla',20,2);
    UPDATE contiene SET precio=precio+5, unidades = unidades + 6 
    WHERE pedido='123456'and plato='Tortilla';
    DELETE FROM contiene WHERE pedido='123456';
    DELETE FROM pedidos WHERE código='123456';
END;
/


/*
SOLUCIÓN 1 (FOR EACH ROW): 
ERROR: ORA-04091: la tabla JULLAMAS.PEDIDOS está mutando, 
puede que el disparador/la función no puedan verla
La tabla está mutando porque estamos intentando modificarla con un disparador 
cuando realizamos un UPDATE sobre ella. Para solucionarlo vamos a usar INSTEAD OF
CREATE OR REPLACE TRIGGER tr_especial
AFTER INSERT OR UPDATE ON pedidos
FOR EACH ROW
DECLARE
    v_media pedidos.importe%TYPE;
BEGIN
    SELECT AVG(importe) INTO v_media FROM pedidos;
    UPDATE pedidos SET especial = CASE WHEN importe>v_media THEN 'S' ELSE 'N' END;
END tr_especial;
*/
--SOLUCIÓN 2 (INSTEAD OF): 
CREATE OR REPLACE TRIGGER tr_especial
INSTEAD OF INSERT OR UPDATE ON vista_pedidos
FOR EACH ROW
DECLARE
    v_media pedidos.importe%TYPE;
    v_num NATURAL;
    v_sum pedidos.importe%TYPE;
BEGIN
    SELECT COUNT(importe),SUM(importe) INTO v_num,v_sum FROM pedidos;
    IF INSERTING THEN
        v_media:=(v_sum+:NEW.importe)/(v_num+1);
    ELSIF UPDATING THEN 
        v_media:=(v_sum-:OLD.importe+:NEW.importe)/(v_num);
        DELETE FROM pedidos WHERE código=:OLD.código;
    END IF;
    INSERT INTO pedidos VALUES(:NEW.código,:NEW.fecha,:NEW.importe,
    :NEW.cliente,:NEW.notas,:NEW.especial);
    UPDATE pedidos SET especial = CASE WHEN importe>v_media THEN 'S' ELSE 'N' END;
END tr_especial;
/
BEGIN
    INSERT INTO vista_pedidos VALUES('123456','11/12/2020',11,'Juan Carlos','Entrar por la chimenea','N');
    INSERT INTO vista_pedidos VALUES('123457','11/12/2020',20,'Felipe','Entrar por la ventana','N');
    INSERT INTO vista_pedidos VALUES('123458','11/12/2020',1,'Mónica','Entrar por la terraza','N');
    UPDATE vista_pedidos SET importe=50 WHERE código='123458';
END;
/
