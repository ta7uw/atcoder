package main

import (
	"bufio"
	"os"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	var X string
	fmt.Scan(&X)
	m := map[string]int{
		"A" : 1,
		"B" : 2,
		"C" : 3,
		"D" : 4,
		"E" : 5,
	}
	fmt.Println(m[X])

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

