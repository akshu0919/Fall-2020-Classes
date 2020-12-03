package main

import "fmt"

func main() {

	minIn :=  int64(19700101)
	maxIn := int64(20000424)
	maxOut := int64(0)
	var j int64	
	
	for minIn != maxIn {

		j = minIn + 1

		for j != 1 {
			if j%2 == 0 {
				j = j / 2
			} else {
				j = j * 3 + 1
			  }
			
			if j>maxOut {
				maxOut = j
			}
		} 

		minIn = minIn + 1	

	}

	minIn = int64(19700101)	

	fmt.Print("Minimum Value: ")
	fmt.Println(minIn)
	fmt.Print("Maximum Value: ")
	fmt.Println(maxIn)
	fmt.Print("Max Possible Number in Collatz: ")
	fmt.Println(maxOut)
}
