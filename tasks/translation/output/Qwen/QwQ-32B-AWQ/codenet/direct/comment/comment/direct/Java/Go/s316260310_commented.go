package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var buf []string
	get := func() string {
		if len(buf) == 0 {
			sc.Scan()
		}
		ret := buf[0]
		buf = buf[1:]
		return ret
	}
	getInt := func() int {
		s := get()
		v, _ := strconv.Atoi(s)
		return v
	}
	getLong := func() int64 {
		s := get()
		v, _ := strconv.ParseInt(s, 10, 64)
		return v
	}

	N := getInt()
	K := getLong()
	A := make([]int, N)
	for i := range A {
		A[i] = getInt()
	}

	// Find cycle entry point
	var visited = make([]bool, N)
	curr := 0
	for !visited[curr] {
		visited[curr] = true
		curr = A[curr] - 1
	}

	// Build straight path
	straight := []int{}
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	// Build cycle
	cycle := []int{curr}
	curr = A[curr] - 1
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr] - 1
	}

	// Determine the answer
	if K < int64(len(straight)) {
		fmt.Println(straight[int(K)] + 1)
	} else {
		K -= int64(len(straight))
		lenC := len(cycle)
		pos := int(K) % lenC
		fmt.Println(cycle[pos] + 1)
	}
}
// End of Code
