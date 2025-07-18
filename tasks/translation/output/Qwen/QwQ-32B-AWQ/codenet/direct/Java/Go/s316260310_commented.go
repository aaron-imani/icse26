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
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	idx := 0

	N, _ := strconv.Atoi(tokens[idx])
	idx++
	K, _ := strconv.ParseInt(tokens[idx], 10, 64)
	idx++
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(tokens[idx])
		idx++
	}

	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		curr = A[curr] - 1
	}

	straight := make([]int, 0, N)
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	cycle := make([]int, 0, N)
	cycle = append(cycle, curr)
	curr = A[curr] - 1
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr] - 1
	}

	if K < int64(len(straight)) {
		fmt.Println(straight[int(K)]+1)
	} else {
		K -= int64(len(straight))
		cycleLength := int64(len(cycle))
		cycleIndex := K % cycleLength
		fmt.Println(cycle[cycleIndex] + 1)
	}
}

// End of Code
