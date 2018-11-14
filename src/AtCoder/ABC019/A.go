package main

import (
	"bufio"
	"os"
	"strings"
	"strconv"
	"sort"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	S := strings.Split(readLine(), " ")
	a, _ := strconv.Atoi(S[0])
	b, _ := strconv.Atoi(S[1])
	c, _ := strconv.Atoi(S[2])
	s := []int{a, b, c}
	sort.Ints(s)
	fmt.Println(s[1])


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

