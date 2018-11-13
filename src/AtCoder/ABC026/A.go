package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	A, _ := strconv.Atoi(readLine())
	maxValue := -1
	for i:= 0; i <=A; i++{
		j := A -i
		if i * j >= maxValue{
			maxValue = i * j
		}
	}
	fmt.Println(maxValue)

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

