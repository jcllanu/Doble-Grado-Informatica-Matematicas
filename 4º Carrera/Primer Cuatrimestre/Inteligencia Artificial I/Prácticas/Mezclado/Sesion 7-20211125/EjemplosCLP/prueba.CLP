;; prueba.clp  (se puede cargar usando (load prueba.clp)
(deftemplate descendiente_directo
	(slot ascendiente1)
	(slot ascendiente2)
    	(slot descendiente)
	(slot sexo)    
)    
    
(deffacts Letras
	(dd juan maria rosa m)    ; hechos desdendiente directo (ordenados) sin template.	(dd juan maria luis h)
	(dd jose laura pilar m)
  	(dd luis pilar miguel h)	; estos hechos se cargan en la MT al hacer reset.
	(dd miguel isabel jaime h)
	(dd pedro rosa pablo h)
	(dd pedro rosa begoña m)
	(descendiente_directo (ascendiente1 juan) (ascendiente2 maria)(descendiente luis) (sexo h))   ;; usando hechos con templates.
)

;; esta regla sin lado izquierdo se puede usar para inicializar en vez de usar deffacts. 
;; Su lado izquierdo implicito es (initial-fact) que se carga en la MT al hacer (reset)
;; Esta regla se ejecuta al hacer (run)

(defrule inicializar 
	=>
	(assert (dd paco Lorena h)) 
) 

;; La siguiente regla (sintaxis CLIPS) permite asertar en la base de hechos predicados de la forma (padre Juan Rosa) o (madre María Rosa) a partir de los hechos iniciales dd. 

(defrule padres
    (dd ?x ?z ?y ?)
    =>
    (assert (padre ?x ?y))
    (assert (madre ?z ?y)))

(defrule padres_bis
    (descendiente_directo (ascendiente1 ?x) (ascendiente2 ?z) (descendiente ?y) (sexo ?))
    =>
    (assert (padre ?x ?y))
    (assert (madre ?z ?y)))