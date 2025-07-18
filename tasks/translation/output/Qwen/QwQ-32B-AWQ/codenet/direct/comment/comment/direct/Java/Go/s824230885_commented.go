package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	tokens []string
	index  int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var allTokens []string
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		allTokens = append(allTokens, fields...)
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	tokens = allTokens
	index = 0
	solve()
}

func next() string {
	s := tokens[index]
	index++
	return s
}

func nextInt() int {
	s := next()
	n, _ := strconv.Atoi(s)
	return n
}

func solve() {
	N := nextInt()
	list := make([]int, N)
	for i := 0; i < N; i++ {
		list[i] = nextInt()
	}
	max := 0
	output := 0
	for _, num := range list {
		if num >= max {
			max = num
			output++
		}
	}
	println(output)
}

// End of Code
