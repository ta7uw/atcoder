package main

import (
	"bufio"
	"io"
	"os"
	"strconv"
	"fmt"
)

var (
	nstr   func() string
	stdout *bufio.Writer
	MOD    = 1000000007
)

func init() {
	nstr = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func main() {
	defer stdout.Flush()
	n := nint()
	bList := getIntSlice(n-1)

	subordinate := make(map[int][]int)
	for i := 0; i < n-1; i++ {
		b := bList[i]

		c, ok := subordinate[b-1]
		if ok {
			c = append(c, i+1)
			subordinate[b-1] = c
		}else{
			tmp := make([]int, 0)
			tmp = append(tmp, i+1)
			subordinate[b-1] = tmp
		}
	}

	salaries := make([]int, n)

	for i := n - 1; i >= 0; i-- {
		sub, ok := subordinate[i]
		if ok{
			maxS :=0
			minS :=0
			for j := 0; j < len(sub); j++ {
				if j==0{
					minS = salaries[sub[j]]
					maxS = salaries[sub[j]]
				}else{
					//fmt.Println(len(sub), sub,j, salaries)
					S := salaries[sub[j]]
					if S > maxS{
						maxS = S
					}
					if S < minS{
						minS = S
					}
				}
			}
			salaries[i] = minS +maxS + 1
		}else{
			salaries[i] = 1
		}
	}
	fmt.Println(salaries[0])

}

type Point struct {
	x int
	y int
}

type highAndlow struct {
	high int
	low  int
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

func exponentMod(a, b, p int) int {
	if b == 0 {
		return 1
	}
	if b&1 == 0 {
		d := exponentMod(a, b/2, p)
		return (d * d) % p
	} else {
		return (a * exponentMod(a, b-1, p)) % p
	}
}