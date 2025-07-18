package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var numbers []int
	for scanner.Scan() {
		line := scanner.Text()
		for _, s := range strings.Fields(line) {
			num, _ := strconv.Atoi(s)
			numbers = append(numbers, num)
		}
	}
	N := numbers[0]
	A := numbers[1 : 1+N]
	const MOD = 1e9 + 7
	var ans int64
	sum := int64(A[len(A)-1])
	ans = 0
	for i := len(A) - 2; i >= 0; i-- {
		term := (sum * int64(A[i])) % MOD
		ans = (ans + term) % MOD
		sum = (sum + int64(A[i])) % MOD
	}
	fmt.Println(ans)
}

// End of Code
