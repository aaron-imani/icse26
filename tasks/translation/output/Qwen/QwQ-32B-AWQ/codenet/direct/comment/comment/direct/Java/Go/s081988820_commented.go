package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var allInput strings.Builder
	for scanner.Scan() {
		allInput.WriteString(scanner.Text() + " ")
	}
	inputStr := allInput.String()
	tokens := strings.Fields(inputStr)
	numbers := make([]int, len(tokens))
	for i, s := range tokens {
		n, _ := strconv.Atoi(s)
		numbers[i] = n
	}
	idx := 0

	H := numbers[idx]
	idx++
	W := numbers[idx]
	idx++

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 驅0; j < 10; j++ {
			c[i][j] = numbers[idx]
			idx++
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				if c[i][j]+min[j] < min[i] {
					min[i] = c[i][j] + min[j]
				}
			}
		}
	}

	ans := 0
	for h := 0; h < H; h++ {
		for w := 0; w < W; w++ {
			A := numbers[idx]
			idx++
			ans += min[A]
		}
	}

	fmt.Println(ans)
}
// End of Code
