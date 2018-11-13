package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	N, _ := strconv.Atoi(readLine())
	k := 0
	for {
		if N / 2 > 0{
			k+=1
			N -= 2
		}else{
			break
		}
	}

	if N % 2 == 0{
		fmt.Println(k)
		for i:= 0; i < k; i ++{
			fmt.Println(2)
		}
	}else{
		fmt.Println(k+1)
		fmt.Println(1)
		for i:= 0; i < k; i ++{
			fmt.Println(2)
		}
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

