package main

import (
	"bufio"
	"os"
	"strings"
	"strconv"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	x := strings.Split(readLine(), " ")
	A, _ := strconv.Atoi(x[0])
	B, _ := strconv.Atoi(x[1])
	C, _ := strconv.Atoi(x[2])
	K, _ := strconv.Atoi(x[3])
	y := strings.Split(readLine(), " ")
	S, _ := strconv.Atoi(y[0])
	T, _ := strconv.Atoi(y[1])

	if S + T >= K {
		fmt.Println(A*S + B*T -C*(S + T))
	}else{
		fmt.Println(A*S + B*T)
	}

}

func gcd(x, y int) int {
	if y == 0{
		return x
	}
	return gcd(y, x % y)
}

func lcm(x, y int) int {
	return x*y / gcd(x, y)
}

func readLine() string {
	buf := make([]byte, 0, 1000000)
	for {
		line, isPrefix, err := rdr.ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}

