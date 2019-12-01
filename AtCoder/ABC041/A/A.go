package A

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
	s := readLine()
	i := nextInt()

	str := strings.Split(s, "")
	fmt.Println(str[i-1])

}

func nextInt() int {
	nextI, err := strconv.Atoi(readLine())
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

