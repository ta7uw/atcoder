package B

import (
	"bufio"
	"os"
	"io"
	"strconv"
	"fmt"
	"math"
)

var (
	nstr func() string
	stdout 	*bufio.Writer
)

func init()  {
	nstr = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}


func main() {
	defer stdout.Flush()

	m := nint()
	km := float64(m) / math.Pow10(3.0)

	var vv int

	switch {
	case km < 0.1:
		vv = 0
	case km <= 5.0:
		vv = int(km * 10)
	case 6 <= km && km <= 30:
		vv = int(km) + 50
	case 35 <= km && km <= 70:
		vv = (int(km)-30)/5 + 80
	default:
		vv = 89
	}

	s := fmt.Sprintf("%02d", vv)
	fmt.Println(s)
}

func newReadString(ior io.Reader) func() string{
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+11))
	r.Split(bufio.ScanWords)

	return func() string {
		if !r.Scan(){
			panic("Scan failed")
		}
		return r.Text()
	}
}

func nint64() int64{
	i, err := strconv.ParseInt(nstr(), 0, 64)
	if err != nil{
		panic(err.Error())
	}
	return i
}

func nint() int{
	return int(nint64())
}

func getIntSlice(n int) []int{
	b := make([]int, n)
	for i:=0;i<n ;i++  {
		b[i] = nint()
	}
	return b
}

func getStringSlice(n int) []string{
	b := make([]string, n)
	for i:=0; i<n; i++{
		b[i] = nstr()
	}
	return b
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

func contains(s []int, e int) bool{
	for _, a := range s{
		if a == e{
			return true
		}
	}
	return false
}

func bin(i int, prefix bool) string{
	i64 := int64(i)

	if prefix {
		return "0b" + strconv.FormatInt(i64, 2)
	}else{
		return strconv.FormatInt(i64, 2)
	}
}
