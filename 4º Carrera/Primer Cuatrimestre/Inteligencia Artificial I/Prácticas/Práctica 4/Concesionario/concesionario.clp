
;;;=======================================================
;;;
;;;     Concesionario ENALJECA, sucursal Madrid
;;;
;;;     Este concesionario de expertos recomienda el 
;;;     mejor coche para ti.
;;;
;;;     CLIPS Version 6.3 Example
;;;
;;;     Para ejecutar, simplemente (load), (reset), (run)
;;;
;;;=======================================================

;;****************
;;* DEFFUNCTIONS *
;;****************

(deffunction ask-question (?question $?allowed-values)
   (printout t ?question)
   (bind ?answer (read))
   (if (lexemep ?answer) 
       then (bind ?answer (lowcase ?answer)))
   (while (not (member ?answer ?allowed-values)) do
      (printout t ?question)
      (bind ?answer (read))
      (if (lexemep ?answer) 
          then (bind ?answer (lowcase ?answer))))
   ?answer)

(deffunction yes-or-no-p (?question)
   (bind ?response (ask-question ?question yes no y n))
   (if (or (eq ?response yes) (eq ?response y))
       then yes 
       else no))

(deffunction no-or-yes-p (?question)
   (bind ?response (ask-question ?question yes no y n))
   (if (or (eq ?response yes) (eq ?response y))
       then no 
       else yes))

;;;***************
;;;* QUERY RULES *
;;;***************

;;; Aspectos relevantes: Autonomía, Puntos de Recarga, Precio, Coste Dia a Dia, Ventajas Ecológicas.

;;; ELECTRICO: Poca autonomia, mas economicos en el dia a dia que los hibridos, ventajas ecologicas, mas caros y menos contaminantes.
;;; HIBRIDO: Más autonomia y menos caros que un electrico, ventajas ecologicas menores, precio razonable.
;;; GASOLINA: Más baratos, no tienen ventajas ecologicas considerables, muchas gasolineras y mucha autonomia.
;;; DIESEL: Muy contaminantes, ninguna ventaja ecológica, precio razonable, caros en el dia a dia y muchas gasolineras.
;;; Gas GNC: Autonomía razonable, muy baratos en el dia a dia, menos gasolineras, ventajas ecologicas menores, precio razonable.
;;; GLP: Un poco menos contaminantes que los de gasolina, menos gasolineras, pocas ventajas ecologicas y un poco mas baratos en el dia a dia.

;;;  1   Para el dia a dia
;;;	   1.1    Hacer viajes largos (+ 2 horas)
;;;		1.1.1    Gama alta
;;;			1.1.1.1    Aprovecharse de ventajas ecologicas
;;;				HIBRIDO
;;;			1.1.1.2    No aprovecharse de ventajas ecologicas
;;;				GASOLINA
;;;		1.1.2    Gama baja
;;;			1.1.1.1    Aprovecharse de ventajas ecologicas
;;;                             HIBRIDO
;;;			1.1.1.2    No aprovecharse de ventajas ecologicas
;;;				1.1.1.2.1   Tiene estaciones con GLP en los destinos usuales
;;;                             	GLP
;;;				1.1.1.2.2   No tiene estaciones con GLP en los destinos usuales
;;;					GASOLINA
;;;        1.2    Hacer viajes por ciudad cortos
;;;		1.2.1    Gama alta
;;;			1.2.1.1    Aprovecharse de ventajas ecologicas
;;;                             ELECTRICO
;;;			1.2.1.2    No aprovecharse de ventajas ecologicas
;;;				1.2.1.2.1   Tiene estaciones con Gas GNC en su ciudad
;;;                             	Gas GNC
;;;				1.2.1.2.2   No tiene estaciones con Gas GNC en su ciudad
;;;					GASOLINA
;;;		1.2.2    Gama baja
;;;			1.2.2.1    Aprovecharse de ventajas ecologicas
;;;                             HIBRIDO
;;;			1.2.2.2    No aprovecharse de ventajas ecologicas
;;;                             GASOLINA
;;;  2   Para usar de vez en cuando
;;;        2.1    Hacer viajes largos (+ 2 horas)
;;;		2.1.1    Gama alta
;;;			2.1.1.1    Aprovecharse de ventajas ecologicas
;;;                             HIBRIDO
;;;			2.1.1.2    No aprovecharse de ventajas ecologicas
;;;                             DIESEL
;;;		2.1.2    Gama baja
;;;			2.1.2.1    Aprovecharse de ventajas ecologicas
;;;                             HIBRIDO
;;;			2.1.2.2    No aprovecharse de ventajas ecologicas
;;;				2.1.2.2.1   Tiene estaciones con GLP en su ciudad
;;;                             	GLP
;;;				2.1.2.2.2   No tiene estaciones con GLP en su ciudad
;;;					GASOLINA
;;;        2.2    Hacer viajes por ciudad cortos
;;;		2.2.1    Gama alta
;;;			2.2.1.1    Aprovecharse de ventajas ecologicas
;;;                             ELECTRICO
;;;			2.2.1.2    No aprovecharse de ventajas ecologicas
;;;                             GASOLINA
;;;		2.2.2    Gama baja
;;;			2.2.2.1    Aprovecharse de ventajas ecologicas
;;;                             HIBRIDO
;;;			2.2.2.2    No aprovecharse de ventajas ecologicas
;;;				2.2.2.2.1   Tiene estaciones con Gas GNC en su ciudad
;;;                             	Gas GNC
;;;				2.2.2.2.2   No tiene estaciones con Gas GNC en su ciudad
;;;					2.2.2.2.2.1   Tiene estaciones con GLP en su ciudad
;;;                             		GLP
;;;					2.2.2.2.2.2   No tiene estaciones con GLP en su ciudad
;;;						GASOLINA

(defrule determine-frecuencia-de-uso ""
   (not (uso-frecuente ?))
   (not (recomendar ?))
   =>
   (assert (uso-frecuente (yes-or-no-p "¿Quiere un coche para el dia a dia (yes/no)? "))))

(defrule determine-frecuencia-de-uso2 ""
   (not (uso-frecuente ?))
   (not (recomendar ?))
   =>
   (assert (uso-frecuente (no-or-yes-p "¿Quiere un coche para usar solamente de vez en cuando (yes/no)? "))))

(defrule determine-longitud-viajes ""
   (not (longitud-viajes ?))
   (not (recomendar ?))
   =>
   (assert (longitud-viajes (yes-or-no-p "¿Va a realizar viajes largos (yes/no)? "))))

(defrule determine-longitud-viajes2 ""
   (not (longitud-viajes ?))
   (not (recomendar ?))
   =>
   (assert (longitud-viajes (no-or-yes-p "¿Realizará mayoritariamente viajes cortos por ciudad (yes/no)? "))))

(defrule determine-coste-gama ""
   (not (coste-gama ?))
   (not (recomendar ?))
   =>
   (assert (coste-gama (yes-or-no-p "¿Busca un coche de alto presupuesto (alta gama)(yes/no)? "))))

(defrule determine-coste-gama2 ""
   (not (coste-gama ?))
   (not (recomendar ?))
   =>
   (assert (coste-gama (no-or-yes-p "¿Busca un coche de bajo presupuesto (gama baja) (yes/no)? "))))

(defrule determine-ventajas-ecologicas ""
   (not (ventajas-ecologicas ?))
   (not (recomendar ?))
   =>
   (assert (ventajas-ecologicas (yes-or-no-p "¿Quiere aprovecharse de coches con ventajas ecologicas (yes/no)? "))))

(defrule determine-GNC ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (not (GNC ?))
   (not (recomendar ?))
   =>
   (assert (GNC (yes-or-no-p "¿Tiene estaciones GNC en sus destinos usuales (yes/no)? "))))

(defrule determine-GNC-2 ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (not (GNC ?))
   (not (recomendar ?))
   =>
   (assert (GNC (yes-or-no-p "¿Tiene estaciones GNC en sus destinos usuales (yes/no)? "))))

(defrule determine-GLP ""
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas no)
   (not (GLP ?))
   (not (recomendar ?))
   =>
   (assert (GLP (yes-or-no-p "¿Tiene estaciones GLP en sus destinos usuales (yes/no)? "))))

(defrule determine-GLP-2 ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GNC no)
   (not (GLP ?))
   (not (recomendar ?))
   =>
   (assert (GLP (yes-or-no-p "¿Tiene estaciones GLP en sus destinos usuales (yes/no)? "))))

;;;************************
;;;* RECOMMENDATION RULES *
;;;************************

(defrule determine-recomend-yyyy ""
   (uso-frecuente yes)
   (longitud-viajes yes)
   (coste-gama yes)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-yyyn ""
   (uso-frecuente yes)
   (longitud-viajes yes)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-yyny ""
   (uso-frecuente yes)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-yynn-GLP ""
   (uso-frecuente yes)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GLP yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "GLP")))

(defrule determine-recomend-yynn-noGLP ""
   (uso-frecuente yes)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GLP no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-ynyy ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "ELECTRICO")))

(defrule determine-recomend-ynyn-GNC ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (GNC yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "Gas GNC")))

(defrule determine-recomend-ynyn-noGNC ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (GNC no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-ynny ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-ynnn ""
   (uso-frecuente yes)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-nyyy ""
   (uso-frecuente no)
   (longitud-viajes yes)
   (coste-gama yes)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-nyyn ""
   (uso-frecuente no)
   (longitud-viajes yes)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (not (recomendar ?))
   =>
   (assert (recomendar "DIESEL")))

(defrule determine-recomend-nyny ""
   (uso-frecuente no)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-nynn-GLP ""
   (uso-frecuente no)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GLP yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "GLP")))

(defrule determine-recomend-nynn-noGLP ""
   (uso-frecuente no)
   (longitud-viajes yes)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GLP no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-nnyy ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "ELECTRICO")))

(defrule determine-recomend-nnyn ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama yes)
   (ventajas-ecologicas no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

(defrule determine-recomend-nnny ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "HIBRIDO")))

(defrule determine-recomend-nnnn-GNC ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GNC yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "Gas GNC")))

(defrule determine-recomend-nnnn-GLP ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GNC no)
   (GLP yes)
   (not (recomendar ?))
   =>
   (assert (recomendar "GLP")))

(defrule determine-recomend-nnnn-noGLPnoGNC ""
   (uso-frecuente no)
   (longitud-viajes no)
   (coste-gama no)
   (ventajas-ecologicas no)
   (GNC no)
   (GLP no)
   (not (recomendar ?))
   =>
   (assert (recomendar "GASOLINA")))

;;;********************************
;;;* STARTUP AND CONCLUSION RULES *
;;;********************************

(defrule system-banner ""
  (declare (salience 10))
  =>
  (printout t crlf crlf)
  (printout t "Concesionario ENALJECA")
  (printout t crlf crlf)
  (printout t "Para recomendarle un coche adecuado, le haremos unas preguntas sencillas acerca de sus preferencias y su modo de vida.")
  (printout t crlf crlf)
  (printout t "Por favor, responda con yes o no.")
  (printout t crlf crlf))

(defrule print-recomendacion ""
  (declare (salience 10))
  (recomendar ?item)
  =>
  (printout t crlf crlf)
  (printout t "En base a sus respuestas, pensamos que el coche mas adecuado para usted es:")
  (printout t crlf crlf)
  (format t " %s%n%n%n" ?item)
  (printout t crlf crlf)
  (printout t "Esperamos que este servicio haya sido de utilidad. Ahora, la decisión final le corresponde tomarla a usted.")
  (printout t crlf crlf))
