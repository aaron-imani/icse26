package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var N int
	var K int64
	fmt.Fscan(r, &N)
	fmt.Fscan(r, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(r, &A[i])
	}

	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		curr = A[curr] - 1
	}

	straight := []int{}
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	cycle := []int{curr}
	curr = A[curr] - 1
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr] - 1
	}

	lenStraight := len(straight)
	lenCycle := len(cycle)
	if K < int64(lenStraight) {
		fmt.Fprintln(w, straight[K]+1)
	} else {
		rem := (K - int64(lenStraight)) % int64(lenCycle)
		if rem < 0 {
			rem += int64(lenCycle)
		}
		fmt.Fprintln(w, cycle[rem]+1)
	}
}

// End of Code
