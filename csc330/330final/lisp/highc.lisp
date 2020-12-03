#!/usr/bin/sbcl --script

(defvar minIn 20000424)
(defvar maxIn 20041219)
(defvar maxR 0)
(defvar maxOut)

(defun getMax (n)
	
	(if (> n maxR) 
		(setf maxR n)
	)

	(cond 
		( (= n 1) maxR )
		( (oddp n) (getMax(+ 1 (* n 3))) )
		(t (getMax (/ n 2)) )
	)

)

(loop while (/= minIn maxIn)

	do (setq maxOut (getMax minIn))
	do (incf minIn)
)

(setq minIn 20000424)

(princ "Minimum Value: ")
(princ minIn)(terpri)
(princ "Maximum Value: ")
(princ maxIn)(terpri)
(princ "Max Number in Collatz Sequence: ")
(princ maxOut)(terpri)
