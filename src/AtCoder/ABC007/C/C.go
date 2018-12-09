package C

import (
	"bufio"
	"io"
	"os"
	"strconv"
	"strings"
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
	r := nint()
	c := nint()
	sx := nint()
	sy := nint()
	gx := nint()
	gy := nint()

	start := yx{sx-1,sy-1,}
	goal := yx{gx-1, gy-1,}
	nodes := make(map[yx]string)

	for i:=0;i < r ;i++ {
		line := strings.Split(nstr(), "")
		for j:=0;j <c ;j++ {
			tmp := yx{i, j,}
			nodes[tmp] = line[j]
		}

	}
	fmt.Println(BFS(start, goal, nodes))
}

type yx struct{
	y int
	x int
}

func BFS(start yx, goal yx, nodes map[yx]string) int{
	next := []yx{start}
	visited := make(map[yx]bool)
	route := make(map[yx]int)
	route[start] = 0
	visited[start] = true
	for len(next) > 0 {
		node := next[0]
		next = next[1:]
		if node.x == goal.x && node.y == goal.y {
			return route[node]
		}
		up := yx{node.y -1, node.x }
		down := yx{node.y + 1 , node.x}
		left := yx{node.y , node.x-1}
		right := yx{node.y , node.x+1}
		if !visited[up] && nodes[up] == "." {
			next = append(next, up)
			route[up] = route[node] +  1
			visited[up] = true
		}
		if !visited[down] && nodes[down] == "." {
			next = append(next, down)
			route[down] = route[node]+  1
			visited[down] = true
		}
		if !visited[right] && nodes[right] == "." {
			next = append(next, right)
			route[right] = route[node] + 1
			visited[right] = true
		}
		if !visited[left] && nodes[left] == "." {
			next = append(next, left)
			route[left] = route[node] +1
			visited[left] = true
		}

	}
	return route[goal]

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

