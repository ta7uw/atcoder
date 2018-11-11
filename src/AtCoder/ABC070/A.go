package main

import "fmt"

func main(){
	var N string
	fmt.Scan(&N)

	if N[0] == N[2]{
		fmt.Println("Yes")
	}else{
		fmt.Println("No")
	}

}
