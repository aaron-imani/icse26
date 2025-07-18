package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD int64 = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.ParseInt(strings.TrimSpace(nStr), 10, 64)
	aStr, _ := reader.ReadString('\n')
	aStr = strings.TrimSpace(aStr)
	aList := strings.Split(aStr, " ")
	a := make([]int64, len(aList))
	for i := range aList {
		num, _ := strconv.ParseInt(aList[i], 10, 64)
		a[i] = num
	}

	ans := int64(0)
	sum := a[len(a)-1]
	for i := len(a) - 2; i >= 0; i-- {
		term := (sum * a[i]) % MOD
		ans += term
		ans %= MOD
		sum += a[i]
		sum %= MOD
	}
	fmt.Println(ans % MOD)
}

// End of Code
