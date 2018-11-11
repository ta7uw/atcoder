package main

import (
	"fmt"
	"strings"
)

func main(){
	var s string
	fmt.Scan(&s)
	tmp := strings.Split(s, ",")
	fmt.Println(strings.Join(tmp, " "))
}
