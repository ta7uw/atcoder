package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
	"fmt"
)

var sc = bufio.NewScanner(os.Stdin)
var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	n := readLine()
	N := strings.Split(n, "")
	if strings.Count(n, N[0]) == 4{
		fmt.Println("SAME")
	}else{
		fmt.Println("DIFFERENT")
	}


}

func nextInt() int {
	sc.Scan()
	nextI, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return nextI
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

