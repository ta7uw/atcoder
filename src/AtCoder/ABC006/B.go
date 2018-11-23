package main
 
import (
	"bufio"
	"os"
	"io"
	"strconv"
	"fmt"
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
 
	n := nint()
 
	a := make([]int, n)
 
	if n == 1{
		fmt.Println(0)
	}else if n == 2{
		fmt.Println(0)
	}else if n == 3{
		fmt.Println(1)
	}else{
		a[0] = 0
		a[1] = 0
		a[2] = 1
		for i:= 3; i < n;i++{
			a[i] = (a[i-1] + a[i-2] + a[i-3]) % 10007
		}
		fmt.Println(a[n-1] % 10007)
	}
 
 
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
