package A

import (
	"bufio"
	"os"
	"strconv"
	"sort"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	A, _ := strconv.Atoi(readLine())
	B, _ := strconv.Atoi(readLine())
	C, _ := strconv.Atoi(readLine())
	m := make(map[int]int)
	s := []int{A, B, C}
	sort.Sort(sort.Reverse(sort.IntSlice(s)))
	for i, j := range s{
		m[j] = i + 1
	}
	fmt.Println(m[A])
	fmt.Println(m[B])
	fmt.Println(m[C])


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

