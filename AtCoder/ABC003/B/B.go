package B

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

var (
	nstr   func() string
	stdout *bufio.Writer
)

func init() {
	nstr = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func main() {
	defer stdout.Flush()

	s := nstr()
	t := nstr()

	sArray := make([]rune, len(s))
	tArray := make([]rune, len(t))
	for i, v := range s {
		sArray[i] = v
	}
	for i, v := range t {
		tArray[i] = v
	}

	var r = true
	for i := 0; i < len(s); i++ {
		S := sArray[i]
		T := tArray[i]
		if S == T {
			continue
		} else if S == '@' && (T == 'a' || T == 't' || T == 'c' || T == 'o' || T == 'd' || T == 'e' || T == 'r' || T == '@') {
			continue
		} else if T == '@' && (S == 'a' || S == 't' || S == 'c' || S == 'o' || S == 'd' || S == 'e' || S == 'r' || S == '@') {
			continue
		}
		r = false
	}
	if r {
		fmt.Println("You can win")
	} else {
		fmt.Println("You will lose")
	}

}

func newReadString(ior io.Reader) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+11))
	r.Split(bufio.ScanWords)

	return func() string {
		if !r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}
}

func nint64() int64 {
	i, err := strconv.ParseInt(nstr(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

func nint() int {
	return int(nint64())
}

func getIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = nint()
	}
	return b
}

func getStringSlice(n int) []string {
	b := make([]string, n)
	for i := 0; i < n; i++ {
		b[i] = nstr()
	}
	return b
}

func gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func bin(i int, prefix bool) string {
	i64 := int64(i)

	if prefix {
		return "0b" + strconv.FormatInt(i64, 2)
	} else {
		return strconv.FormatInt(i64, 2)
	}
}

