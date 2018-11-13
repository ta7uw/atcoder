package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	S := readLine()
	N, _ := strconv.Atoi(readLine())
	s := strings.Split(S, "")

	if N % 5 == 0{
		fmt.Println(s[N/5-1] + (s[4]))
	}else{
		fmt.Println(s[N/5] + s[N%5-1])
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

