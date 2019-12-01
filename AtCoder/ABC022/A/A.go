package A

import (
	"bufio"
	"os"
	"strings"
	"strconv"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	x := strings.Split(readLine(), " ")
	N, _ := strconv.Atoi(x[0])
	S, _ := strconv.Atoi(x[1])
	T, _ := strconv.Atoi(x[2])
	W, _ := strconv.Atoi(readLine())
	var a int
	count := 0
	if W >= S && W <= T{
		count ++
	}
	for i:=0; i<N-1; i++{
		a, _ = strconv.Atoi(readLine())
		W = a + W
		if W >= S && W <= T{
			count ++
		}
	}
	fmt.Println(count)



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

