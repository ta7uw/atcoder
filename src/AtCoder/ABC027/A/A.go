package A

import (
	"bufio"
	"os"
	"strings"
	"fmt"
)

var sc = bufio.NewScanner(os.Stdin)
var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	l := strings.Split(readLine(), " ")
	l1, l2, l3 := l[0], l[1], l[2]

	if l1 == l2 {
		fmt.Println(l3)
	}else if l2 == l3{
		fmt.Println(l1)
	}else{
		fmt.Println(l2)
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

