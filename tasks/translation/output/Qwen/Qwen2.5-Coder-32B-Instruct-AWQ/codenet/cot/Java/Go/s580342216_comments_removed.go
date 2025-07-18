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

	for scanner.Scan() {
		runCase(scanner.Text())
	}
}

func runCase(line string) {
	parts := strings.Split(line, " ")
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	len := 0
	for N > 0 {
		N /= K
		len++
	}

	fmt.Println(len)
}

func strToIntArray(str string) []int {
	vals := strings.Split(str, " ")
	sz := len(vals)
	res := make([]int, sz)
	for i := 0; i < sz; i++ {
		res[i], _ = strconv.Atoi(vals[i])
	}
	return res
}

// End of Code
