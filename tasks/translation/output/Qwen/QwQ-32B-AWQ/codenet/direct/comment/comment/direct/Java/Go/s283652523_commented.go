package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	data, err := io.ReadAll(os.Stdin)
	if err != nil {
		panic(err)
	}
	tokens := strings.Fields(string(data))
	ptr := 0
	n, _ := strconv.Atoi(tokens[ptr])
	ptr++
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(tokens[ptr])
		ptr++
	}

	sum := int64(a[n-1])
	ans := int64(0)
	for i := n - 2; i >= 0; i-- {
		ai := int64(a[i])
	.term := (sum * ai) % MOD
	ans = (ans + term) % MOD
	sum = (sum + ai) % MOD
}
	fmt.Println(ans % MOD)
}

// End of Code
