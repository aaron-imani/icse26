package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	var K int64
	fmt.Fscanf(reader, "%d %d\n", &N, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
	}

	visited := make([]bool, N)
	curr := 0
	for !visited[curr] {
		visited[curr] = true
		curr = A[curr] - 1
	}

	straight := make([]int, 0)
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 蹑
	}

	cycle := make([]int, 0)
	cycle = append(cycle, curr)
	next := A[curr] - 1
	for next != cycle[0] {
		cycle = append(cycle, next)
		next = A[next] - 1
	}

	if K < int64(len(straight)) {
		fmt.Fprintf(writer, "%d\n", straight[K]+1)
	} else {
		K -= int64(len(straight))
		idx := K % int64(len(cycle))
		fmt.Fprintf(writer, "%d\n", cycle[idx]+1)
	}
}

// End of Code
