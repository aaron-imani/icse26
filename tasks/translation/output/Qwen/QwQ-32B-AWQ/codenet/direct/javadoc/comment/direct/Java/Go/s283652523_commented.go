package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	ptr := 0
	n, _ := strconv.Atoi(tokens[ptr])
	ptr++
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(tokens[ptr])
		ptr++
	}

	ans := int64(0)
	sum := int64(a[n-1]) % MOD
	for i := n - 2; i >= 0; i-- {
		current := int64(a[i])
		product := (sum * current) % MOD
		ans = (ans + product) % MOD
		sum = (sum + current) % MOD
	}
	fmt.Println(ans)
}

// End of Code
