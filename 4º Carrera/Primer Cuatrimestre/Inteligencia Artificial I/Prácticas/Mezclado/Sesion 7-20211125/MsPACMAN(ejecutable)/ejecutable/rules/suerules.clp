	
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
(defrule SUEsepararseBlinky
    (declare (salience 10))
	(SUE (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost BLINKY)) (test (not (= ?d -1)))
	(BLINKY (edible false))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id SUErunAwayFromGhost) (info "Fantasma muy cerca --> separarse de el") (ghost BLINKY)))
)

(defrule SUEsepararsePinky
    (declare (salience 10))
	(SUE (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost PINKY)) (test (not (= ?d -1)))
	(PINKY (edible false))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id SUErunAwayFromGhost) (info "Pinky esta muy cerca --> separarse de el") (ghost PINKY)))
)

(defrule SUEsepararseInky
    (declare (salience 10))
	(SUE (edible false) (distanceNearestGhost ?d) (distancePacman ?p) (nearestGhost INKY)) (test (not (= ?d -1)))
	(INKY (edible false))
	(INFO (numberPPillsLeft 0))
	(test (< ?d 15)) (test (< ?d ?p))
	=>
	(assert (ACTION (id SUErunAwayFromGhost) (info "Inky esta muy cerca --> separarse de el") (ghost INKY)))
)

(defrule SUEdefiendePowerPill ;Cuando solo queda 1 PowerPill, SUE ayuda a INKY a defenderla
	(SUE (edible false))
	(MSPACMAN (nearestPPill ?npp))
	(INFO (numberPPillsLeft 1))
	=>
	(assert (ACTION (id SUEmoveToPPill) (info "Queda 1 powerpill --> Defender powerpill") (powerPillNode ?npp)))
)

(defrule SUEpersigueINKY
	(declare (salience 15))
	(SUE (edible false) (distanceToPacmanNearestPPill ?d))
	(INFO (numberPPillsLeft 1))
	(INKY (edible false) (distanceNearestGhost ?dis) (distanceToPacmanNearestPPill ?dpp) (nearestGhost SUE))
	(test (> ?dpp ?dis)) (test (< ?d 45))
	=>
	(assert (ACTION (id SUEchaseGhost) (info "Queda 1 powerpill --> Defender powerpill") (ghost INKY)))
)

(defrule SUEseAlejaDeINKY
	(declare (salience 15))
	(SUE (edible false) (distanceToPacmanNearestPPill ?d))
	(INFO (numberPPillsLeft 1))
	(INKY (edible false) (distanceNearestGhost ?dis) (distanceToPacmanNearestPPill ?dpp) (nearestGhost SUE))
	(test (< ?dpp ?dis)) (test (< ?d 45))
	=>
	(assert (ACTION (id SUErunAwayFromGhost) (info "Queda 1 powerpill --> Defender powerpill") (ghost INKY)))
)

(defrule SUEhuye
	(SUE (edible true))
	=>
	(assert (ACTION (id SUErunAway) (info "Comestible --> huir")))
)

(defrule SUEaPorMsPacMan
	(SUE (edible false))
	(INFO (numberPPillsLeft ?pp))
	(test (not (= ?pp 1)))
	=>
	(assert (ACTION (id SUEchasePacman) (info "MsPacMan vulnerable --> perseguir")))
)