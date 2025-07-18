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
	N := readInt(scanner)
	K := readInt64(scanner)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt(scanner)
	}

	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		curr = A[curr] - 1
	}

	straight := make([]int, 0)
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	cycle := make([]int, 0)
	cycle = append(cycle, curr)
	currCycle := A[curr] - 1
	for currCycle != cycle[0] {
		cycle = append(cycle, currCycle)
		currCycle = A[currCycle] - 1
	}

	if int(K) < len(straight) {
		fmt.Println(straight[int(K)]+1)
	} else {
		remaining := K - int64(len(straight))
		cycleLen := int64(len(cycle))
		idx := int(remaining % cycleLen)
		fmt.Println(cycle[idx]+1)
	}
}

func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func readInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	num, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return num
}

// End of Code
