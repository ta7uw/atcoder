package main

import "fmt"

func main(){
	var a, b, c ,d int
	fmt.Scan(&a, &b, &c, &d)
	first := a*b
	second := c*d
	if first == second{
		fmt.Println(first)
	}else if first > second{
		fmt.Println(first)
	}else {
		fmt.Println(second)
	}
}
