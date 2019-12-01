package B
 
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
	aList := getIntSlice(n)
 
	var m  = make(map[int]int)
	var a int
	var count int
	for i:=0;i<n ;i++  {
		a = aList[i]
		b, ok := m[a]
		if ok{
			b ++
			m[a] = b
			count ++
		}else{
			m[a] = 1
		}
 
	}
 
	fmt.Println(count)
 
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

