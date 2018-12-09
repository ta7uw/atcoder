package B

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
)

func init() {
	nstr = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

func main() {
	defer stdout.Flush()
	n := nint()
	k := nint()
	aList := getIntSlice(n)

	sumList := make([]int, 0)
	for i:=0;i<n ;i++  {
		for j:=i+1;j<n+1 ;j++  {
			sum := 0
			for tmp:=i;tmp<j ;tmp++  {
				sum += aList[tmp]
			}
			sumList = append(sumList, sum)
		}
	}
	var (
		ans int
		count int
	)
	for i:=40; i>=0; i--{
		checkNum := 1 << uint(i)
		tmp := make([]int, 0)
		for j:=0;j<len(sumList) ;j++  {
			logical := checkNum & sumList[j]
			if logical !=0{
				count ++
				tmp = append(tmp, sumList[j])
			}
		}
		if count >= k{
			ans += checkNum
			sumList =  tmp
		}
		count = 0
	}
	fmt.Println(ans)
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

