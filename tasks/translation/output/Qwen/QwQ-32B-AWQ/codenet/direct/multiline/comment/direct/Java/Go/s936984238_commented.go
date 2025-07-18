package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	var tokens []string
	for sc.Scan() {
		line := sc.Text()
		for _, tok := range strings.Fields(line) {
			tokens = append(tokens, tok)
		}
	}
	nums := make([]int, len(tokens))
	for i, tok := range tokens {
		num, _ := strconv.Atoi(tok)
		nums[i] = num
	}
	ptr := 0
	for ptr < len(nums) {
		n := nums[ptr]
		ptr++
		if n == 0 {
			break
		}
		if ptr+n > len(nums) {
			break
		}
		scores := make([]int, n)
		copy(scores, nums[ptr:ptr+n])
		ptr += n
		sort.Ints(scores)
		sum := 0
		for i := 1; i < n-1; i++ {
			sum += scores[i]
		}
		fmt.Println(sum / (n-2))
	}
}

// End of Code
