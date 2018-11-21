package main

import (
	"bufio"
	"os"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	sList := make([]string, n)
	dList := make([]int, n)
	for i:=0;i<n ; i++ {
		fmt.Scan(&sList[i])
		fmt.Scan(&dList[i])
	}
	var where int
	var distance int
	for i:=0;i<n ;i++  {
		s := sList[i]
		d := dList[i]
		if d < a{
			distance = a
		}else if a <= d && d <= b{
			distance = d
		}else{
			distance = b
		}


		if s == "East"{
			where += distance
		}else {
			where -= distance
		}
	}
	if where ==0 {
		fmt.Println(0)
	}else if where >0{
		fmt.Println("East", where)
	}else{
		fmt.Println("West", -where)
	}

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




