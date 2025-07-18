package main

import (
	"container/heap"
	"fmt"
)

type IntHeap []int

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
	h := &IntHeap{}
	heap.Init(h)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		heap.Push(h, x)
	}
	sum := 0
	for i := 0; i < n-1; i++ {
		sum += heap.Pop(h).(int)
	}
	if heap.Pop(h).(int) < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
	// End of Code
}
