package C

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
	R := nint()
	C := nint()
	K := nint()
	sList := getStringSlice(R)
	search := make(map[Point]highAndlow)
	for i := 0; i < C; i++ {
		for j := 0; j < R; j++ {
			hPoint := 0
			lPoint := 0
			for h := j; h >= 0; h-- {
				p := sList[h][i]
				if p == 111 {
					hPoint ++
				} else {
					break
				}
			}
			for l := j; l < R; l++ {
				p := sList[l][i]
				if p == 111 {
					lPoint ++
				} else {
					break
				}
			}

			p := Point{x: i, y: j}
			search[p] = highAndlow{high: hPoint, low: lPoint}
		}
	}
	count := 0
	for i := K-1; i <= R-K; i++ {
		for j := K-1; j <= C-K; j++ {
			flag := true
			for k := 0; k < K; k++ {
				sub := K-k
				left := Point{x:j-k,y:i}
				right := Point{x:j+k, y:i}
				if !(search[left].low >= sub && search[left].high >= sub){
					flag = false
					break
				}
				if !(search[right].low >= sub && search[right].high >= sub){
					flag = false
					break
				}
			}
			if flag{
				count ++
			}
		}
	}
	fmt.Println(count)

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
