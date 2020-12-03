#!/usr/bin/julia

function program()

	minIn = Int64(20000424)
	maxIn = Int64(20201203)
	j = Int64(0)
	maxOut = Int64(0)

	while minIn != maxIn

		j = minIn

		while(j != 1)
			if(j%2 == 0)
		   		j = j / 2
			else
		   		j = j * 3 + 1
			end

			if(j > maxOut)
				maxOut  = j
			end 
		end

		minIn = minIn + 1

	end

	minIn = Int64(20000424)

	print("Minimum Value: ")
	println(minIn)
	print("Maximum Value: ")
	println(maxIn)
	print("Max Number in Collatz Sequence: ")
	println(maxOut)

end

program()
