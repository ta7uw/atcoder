package A

import "fmt"

func main() {
	var A, B, C int
	fmt.Scan(&A, &B, &C)

	if B-A == C-B {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

}

