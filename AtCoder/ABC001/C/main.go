package main

import (
	"bufio"
	"io"
	"os"
	"strconv"
	"fmt"
	"math"
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
	Deg := nint()
	Dis := nint()

	var dir = float64(Deg) / float64(10)
	r1 := ""
	if  11.25 <= dir && dir < 33.75{
		r1 = "NNE"
	}else if 33.75 <= dir && dir < 56.25{
		r1 = "NE"
	}else if 56.25 <= dir && dir < 78.75{
		r1 = "ENE"
	}else if 78.75 <= dir && dir < 101.25{
		r1 = "E"
	}else if 101.25 <= dir && dir < 123.75{
		r1 = "ESE"
	}else if 123.75 <= dir && dir < 146.25{
		r1 = "SE"
	}else if 146.25 <= dir && dir < 168.75{
		r1 = "SSE"
	}else if 168.75 <= dir && dir <191.25{
		r1 = "S"
	}else if 191.25 <= dir && dir < 213.75{
		r1 = "SSW"
	}else if 213.75 <= dir && dir < 236.25{
		r1 = "SW"
	}else if 236.25 <= dir && dir < 258.75{
		r1 = "WSW"
	}else if 258.75 <= dir && dir < 281.25{
		r1 = "W"
	}else if 281.25 <= dir && dir < 303.75{
		r1 = "WNW"
	}else if 303.75 <= dir && dir < 326.25{
		r1 = "NW"
	}else if 326.25 <= dir && dir < 348.75{
		r1 = "NNW"
	}else{
		r1 = "N"
	}

	r2 := 0
	var speed = float64(Dis) / float64(60)
	speed = RoundPlus(speed,  1)
	if 0 <= speed && speed <= 0.2{
		r1 = "C"
		r2 = 0
	}else if 0.3 <= speed && speed <= 1.5{
		r2 = 1
	}else if 1.6 <= speed && speed <= 3.3{
		r2 = 2
	}else if 3.4 <= speed && speed <= 5.4{
		r2 = 3
	}else if 5.5 <= speed && speed <= 7.9{
		r2 = 4
	}else if 8.0 <= speed && speed <= 10.7{
		r2 = 5
	}else if 10.8 <= speed && speed <= 13.8{
		r2 = 6
	}else if 13.9 <= speed && speed <= 17.1{
		r2 = 7
	}else if 17.2 <= speed && speed <= 20.7{
		r2 = 8
	}else if 20.8 <= speed && speed <= 24.4{
		r2 = 9
	}else if 24.5 <= speed && speed <= 28.4{
		r2 = 10
	}else if 28.5 <= speed && speed <= 32.6{
		r2 = 11
	}else {
		r2 = 12
	}

	fmt.Print(r1)
	fmt.Print(" ")
	fmt.Println(r2)
}

type Point struct {
	x int
	y int
}

type highAndlow struct {
	high int
	low  int
}
func Round(f float64) float64 {
	return math.Floor(f + .5)
}

func RoundPlus(f float64, places int) (float64) {
	shift := math.Pow(10, float64(places))
	return Round(f * shift) / shift;
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
