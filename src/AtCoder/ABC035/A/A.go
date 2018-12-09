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
	var w, h int
	fmt.Scan(&w, &h)
	if w % 16 == 0 && h % 9 == 0{
		fmt.Println("16:9")
	}else {
		fmt.Println("4:3")
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

