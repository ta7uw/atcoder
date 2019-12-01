package A

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

var sc = bufio.NewScanner(os.Stdin)
var rdr = bufio.NewReaderSize(os.Stdin, 1000000)

func main() {
	var a, d int
	fmt.Scan(&a, &d)

	if a > d{
		fmt.Println(a *(d+1))
	}else{
		fmt.Println(d*(a+1))
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

