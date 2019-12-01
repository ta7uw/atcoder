package A

import (
	"fmt"
)

func main(){
	var a, b int
	var op string
	fmt.Scan(&a)
	fmt.Scan(&op)
	fmt.Scan(&b)
	
	if op == "+"{
		fmt.Println(a+b)
	}else {
		fmt.Println(a-b)
	}
}
