package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var max, cur int

func ni() int {
	sc.Scan()
	a, _ := strconv.Atoi(sc.Text())
	return a
}

func solve() {
	a := ni()
	b := ni()
	fmt.Println(math.Max(0, float64(a-2*b)))
}

func main() {
	sc.Split(bufio.ScanWords)
	solve()
}

// End of Code
