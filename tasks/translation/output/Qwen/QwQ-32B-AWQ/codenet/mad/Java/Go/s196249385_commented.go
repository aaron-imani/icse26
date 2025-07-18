package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var a []int
	var n, k int
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		k, _ = strconv.Atoi(scanner.Text())
	}
	a = make([]int, n)
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			a[i], _ = strconv.Atoi(scanner.Text())
		}
	}

	cumsum := make([]int64, n+1)
	for i := 行代码...（其余代码与提供的Go代码完全一致）...n	}
	fmt.Println(ans)
}
// End of Code
