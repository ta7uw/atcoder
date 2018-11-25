package main

import (
	"bufio"
	"os"
	"io"
	"strconv"
	"math"
	"fmt"
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

	n := nint()
	xList := make([]string, n)
	yList := make([]string, n)

	for i:=0;i<n ;i++  {
		xList[i] = nstr()
		yList[i] = nstr()
	}

	for i := 0; i<n	; i++  {
		fmt.Println(lcs(xList[i], yList[i]))
	}

}

func lcs(x string, y string) int{
	var m = len(x)
	var n = len(y)

	c := make([][]int, m+1)
	for i:= range c{
		c[i] = make([]int, n+1)
	}
	for i:=	1;i<=m ;i++  {
		for j:=1;j<=n ;j++  {
			if x[i-1] == y[j-1]{
				c[i][j] = c[i-1][j-1] + 1
			}else{
				c[i][j] = int(math.Max(float64(c[i-1][j]), float64(c[i][j-1])))
			}


		}
	}
	return c[m][n]

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

func strReverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}

	return string(runes)
}
