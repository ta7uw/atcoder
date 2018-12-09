package A

import (
	"bufio"
	"os"
	"fmt"
)

var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	var x, y int
	fmt.Scan(&x, &y)
	fmt.Println(y/x)
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

