package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
)

type IntMinHeap []int

func (h IntMinHeap) Len() int           { return len(h) }
func (h IntMinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntMinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntMinHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *IntMinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	h := make(IntMinHeap, 0, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		h = append(h, num)
	}

	heap.Init(&h)

	sum := 0
	for i := 0; i < n-1; i++ {
		val := heap.Pop(&h).(int)
		sum += val
	}

	last := heap.Pop(&h).(int)
	if last < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
