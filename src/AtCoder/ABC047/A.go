package main

import "fmt"

func main() {
	var A, B, C int
	fmt.Scan(&A, &B, &C)
	if A == B + C{
		fmt.Println("Yes")
	}else if B == A+C {
		fmt.Println("Yes")
	}else if C == A+B {
		fmt.Println("Yes")
	}else {
		fmt.Println("No")
	}



}

