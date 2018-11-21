package main

import (
	"bufio"
	"os"
	"fmt"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)
var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	var n, t int
	tmp := strings.Split(nextLine(), " ")
	n, _ = strconv.Atoi(tmp[0])
	t, _ = strconv.Atoi(tmp[1])

	aList := make([]int, n)
	for i:=0;i<n ;i++  {
		a, _ := strconv.Atoi(nextLine())
		aList[i] = a
	}
	var count int
	var before = 0
	for i:=0;i<n ;i++  {
		a := aList[i]
		if i != 0 {
			margin := a - before
			if margin >= t {
				count += t
			} else {
				count += margin
			}
		}
		before = a
	}
	count+=t
	fmt.Println(count)

}

func nextLine() string {
	sc.Scan()
	return sc.Text()
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


func gcd(x, y int) int {
	if y == 0{
		return x
	}
	return gcd(y, x % y)
}

func lcm(x, y int) int {
	return x*y / gcd(x, y)
}




