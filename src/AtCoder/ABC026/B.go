package main

import (
	"bufio"
	"os"
	"fmt"
	"sort"
	"math"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {

	const PI  = 3.14159265358979323846264338327950288419716939937510582097494459

	var x int
	fmt.Scan(&x)
	nums := make([]int, x)
	for i := 0; i < x; i++{
		fmt.Scan(&nums[i])
	}
	sort.Ints(nums)
	length := len(nums)

	var area float64
	for i:=0;i<x ;i++  {
		if length % 2 == 0{
			if i % 2 == 0{
				area -= math.Pow(float64(nums[i]), 2)
			}else{
				area += math.Pow(float64(nums[i]), 2)
			}
		}else{
			if i % 2 == 0{
				area += math.Pow(float64(nums[i]), 2)
			}else{
				area -= math.Pow(float64(nums[i]), 2)
			}
		}


	}
	fmt.Println(area * PI)
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




