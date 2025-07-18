package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var nums []int
	for scanner.Scan() {
		text := scanner.Text()
		num, _ := strconv.Atoi(text)
		nums = append(nums, num)
	}
	n := nums[0]
	h := make(IntHeap, 0, n)
	for _, num := range nums[1 : 1+n] {
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
