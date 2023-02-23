	
;FACTS ASSERTED BY GAME INPUT, INFO ABOUT THE ACTUAL TICK OF THE GAME
(deftemplate BLINKY
	(slot edible (type SYMBOL))
	(slot edibleTime (type INTEGER))
	(slot nearestGhost (type SYMBOL))
	(slot distanceNearestGhost (type INTEGER))
	(slot distanceToPacmanNearestPPill (type INTEGER))
	(slot distancePacman (type INTEGER))
)
	
(deftemplate INKY
	(slot edible (type SYMBOL))
	(slot edibleTime (type INTEGER))
	(slot nearestGhost (type SYMBOL))
	(slot distanceNearestGhost (type INTEGER))
	(slot distanceToPacmanNearestPPill (type INTEGER))
	(slot distancePacman (type INTEGER))
)
	
(deftemplate PINKY
	(slot edible (type SYMBOL))
	(slot edibleTime (type INTEGER))
	(slot nearestGhost (type SYMBOL))
	(slot distanceNearestGhost (type INTEGER))
	(slot distanceToPacmanNearestPPill (type INTEGER))
	(slot distancePacman (type INTEGER))
)

(deftemplate SUE
	(slot edible (type SYMBOL))
	(slot edibleTime (type INTEGER))
	(slot nearestGhost (type SYMBOL))
	(slot distanceNearestGhost (type INTEGER))
	(slot distanceToPacmanNearestPPill (type INTEGER))
	(slot distancePacman (type INTEGER))
)
	
(deftemplate MSPACMAN
    (slot nearestGhost (type SYMBOL))
    (slot distanceNearestGhost (type INTEGER))
    (slot nearestEdibleGhost (type SYMBOL))
    (slot distanceNearestEdibleGhost (type INTEGER))
    (slot nearestPPill (type INTEGER))
    (slot distanceNearestPPill (type INTEGER))
)	

(deftemplate INFO
	(slot numberOfLives (type INTEGER))
	(slot timeLeft (type INTEGER))
	(slot level (type INTEGER))
	(slot score (type INTEGER))
	(slot numberPillsLeft (type INTEGER))
	(slot numberPPillsLeft (type INTEGER))
)


;POSSIBLE ACTION FACTS (X = ghost name in capital letters {BLINKY, INKY, PINKY, SUE})
; XrandomMove: Descripcion => Movimiento aleatorio 
;             Extra Facts necesarios => ninguno
; XchasePacman: Descripcion => Perseguir a MsPacMan 
;          Extra Facts necesarios => ninguno
; XchaseGhost: Descripcion => Ir hacia otro de los fantasmas 
;          Extra Facts necesarios => ghost
; XmoveToPPill: Descripcion => Ir hacia la ubicacion de una powerPill 
;           Extra Facts necesarios => powerPillNode
; XrunAway: Descripcion => Huir de MsPacMan 
;           Extra Facts necesarios => ninguno
; XrunAwayFromGhost: Descripcion => Alejarse de uno de los fanstasmas
;                    Extra Facts necesarios => ghost
; XrunAwayFromPosition: Descripcion => Alejarse de una posicion
;                       Extra Facts necesarios => position


;DEFINITION OF THE ACTION FACT
(deftemplate ACTION
	(slot id)
	(slot info (default ""))
	(slot ghost (type SYMBOL))
	(slot powerPillNode (type INTEGER))
	(slot position (type INTEGER))
)


;DEFINITION OF THE RULES
;EXAMPLES:

(defrule PINKYsepararseBlinky
    (declare (salience 10))
	(PINKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost BLINKY)) (test (not (= ?d -1)))
	(BLINKY (edible false))
	(INFO (numberPPillsLeft 0))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id PINKYrunAwayFromGhost) (info "Blinky esta muy cerca --> separarse de el") (ghost BLINKY)))
)

(defrule PINKYsepararseSue
    (declare (salience 10))
	(PINKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost SUE)) (test (not (= ?d -1)))
	(SUE (edible false))
	(INFO (numberPPillsLeft ?pp)) (test (not (= ?pp 1)))
	(test (< ?d 15)) (test (< ?d ?p)) 
	=>
	(assert (ACTION (id PINKYrunAwayFromGhost) (info "Sue esta muy cerca --> separarse de el") (ghost SUE)))
)

(defrule PINKYsepararseInky
    (declare (salience 10))
	(PINKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost INKY)) (test (not (= ?d -1)))
	(INKY (edible false))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id PINKYrunAwayFromGhost) (info "Inky esta muy cerca --> separarse de el") (ghost INKY)))
)

(defrule PINKYhuye
	(PINKY (edible true))
	=>
	(assert (ACTION (id PINKYrunAway) (info "Comestible --> huir")))
)

(defrule PINKYaPorMsPacMan
	(PINKY (edible false))
	=>
	(assert (ACTION (id PINKYchasePacman) (info "MsPacMan vulnerable --> perseguir")))
)