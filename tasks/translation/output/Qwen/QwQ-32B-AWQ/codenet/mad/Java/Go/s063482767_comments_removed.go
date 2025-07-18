package main

import (
	"container/heap"
	"fmt"
)

// Define the IntHeap type

type IntHeap []int

// Implement heap.Interface methods
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var n int
	fmt.Scan(&n)
	h := make(IntHeap, 0, n)

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		heap.Push(&h, num)
	}

	sum := 0
	for i := 0; i < n-1; i++ {
		smallest := heap.Pop(&h).(int)
		sum += smallest
	}

	if h[0] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
