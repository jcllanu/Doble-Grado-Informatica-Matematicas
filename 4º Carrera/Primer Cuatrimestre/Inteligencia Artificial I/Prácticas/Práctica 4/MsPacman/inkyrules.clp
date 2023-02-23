	
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

;Cuando INKY es comestible se aleja del fantasma más cercano si ese fantasma es comestible

(defrule INKYseSacrificaPorPinky
	(INKY (edible true) (nearestGhost ?ng))
	(PINKY (edible true))
	(test (= ?ng PINKY))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "Comestible y el más cercano es Pinky (comestible) --> Alejarse de Pinky") (ghost PINKY)))
)

(defrule INKYseSacrificaPorSue
	(INKY (edible true) (nearestGhost ?ng))
	(SUE (edible true))
	(test (= ?ng SUE))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "Comestible y el más cercano es Sue (comestible) --> Alejarse de Sue") (ghost SUE)))
)

(defrule INKYseSacrificaPorBlinky
	(INKY (edible true) (nearestGhost ?ng))
	(BLINKY (edible true))
	(test (= ?ng INKY))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "Comestible y el más cercano es Inky (comestible) --> Alejarse de Blinky") (ghost BLINKY)))
)

(defrule INKYhuye
	(INKY (edible true))
	=>
	(assert (ACTION (id INKYrunAway) (info "Comestible --> huir")))
)

;Si INKY no es comestible persigue al Pacman siempre

(defrule INKYsepararseSUE
    (declare (salience 10))
	(INKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost SUE)) (test (not (= ?d -1)))
	(SUE (edible false))
	(INFO (numberPPillsLeft ?pp)) (test (not (= ?pp 1)))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "SUE esta muy cerca --> separarse de el") (ghost SUE)))
)

(defrule INKYsepararsePinky
    (declare (salience 10))
	(INKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost PINKY)) (test (not (= ?d -1)))
	(PINKY (edible false))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "Pinky esta muy cerca --> separarse de el") (ghost PINKY)))
)

(defrule INKYsepararseBlinky
    (declare (salience 10))
	(INKY (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost INKY)) (test (not (= ?d -1)))
	(BLINKY (edible false))
	(INFO (numberPPillsLeft 0))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id INKYrunAwayFromGhost) (info "Blinky esta muy cerca --> separarse de el") (ghost BLINKY)))
)

(defrule INKYaPorMsPacMan
	(INKY (edible false))
	=>
	(assert (ACTION (id INKYchasePacman) (info "MsPacMan vulnerable --> perseguir")))
)

