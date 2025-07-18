package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const MOD int64 = 1e9 + 7

func compute(a []int64) int64 {
	n := len(a)
	ans := int64(0)
	sum := a[n-1] % MOD
	for i := n - 2; i >= 0; i-- {
		product := (sum * a[i]) % MOD
		ans = (ans + product) % MOD
		sum = (sum + a[i]) % MOD
	}
	return ans
}

func main() {
	data, err := io.ReadAll(os.Stdin)
	if err != nil {
		panic(err)
	}
	tokens := strings.Fields(string(data))
	ptr := 0
	n, _ := strconv.ParseInt(tokens[ptr], 10, 64)
	ptr++
	a := make([]int64, n)
	for i := 0; i < int(n); i++ {
		num, _ := strconv.ParseInt(tokens[ptr], 10, 64)
		a[i] = num
		ptr++
	}
	ans := compute(a)
	fmt.Println(ans)
}

// End of Code
