package A

import "fmt"

func main() {
	var A, B, C string
	fmt.Scan(&A, &B, &C)

	tmp := string(A[0]) + string(B[0]) + string(C[0])
	fmt.Println(tmp)

}

