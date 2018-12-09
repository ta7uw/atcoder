package main

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
	MOD    = 1000000007
)

func init() {
	nstr = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func main() {
	defer stdout.Flush()
	n := nint()
	ngList := getIntSlice(3)
	check := true
	lower := make([]int, 0, n)
	for _, v := range ngList {
		if v == n {
			check = false
			break
		} else if v < n {
			lower = append(lower, v)
		}
	}
	if !check {
		fmt.Println("NO")
		os.Exit(0)
	}
	dp := make([]int, 301)

	for i := 0; i < len(dp); i++ {
		dp[i] = 101
	}
	dp[n] = 0
	for i := n; i >= 0; i-- {
		if i == ngList[0] || i == ngList[1] || i == ngList[2] {
			continue
		}
		for j := 1; j <= 3; j++ {
			if i-j == ngList[0] || i-j == ngList[1] || i-j == ngList[2] {
				continue
			}
			if i-j < 0 {
				continue
			}
			if dp[i]+1 >= dp[i-j] {
				dp[i-j] = dp[i-j]
			} else {
				dp[i-j] = dp[i] + 1
			}
		}
	}
	if dp[0] <= 100 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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
