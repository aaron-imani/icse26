package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
	"container/heap"
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
	scanner.Scan()
	nStr := scanner.Text()
	n, _ := strconv.Atoi(nStr)
	scanner.Scan()
	numbersStr := scanner.Text()
	numbers := strings.Fields(numbersStr)
	nums := make([]int, len(numbers))
	for i, s := range numbers {
		num, _ := strconv.Atoi(s)
		nums[i] = num
	}
	h := IntHeap(nums)
	heap.Init(&h)

	sum := 0
	for i := 0; i < n-1; i++ {
		val := heap.Pop(&h).(int)
		sum += val
	}
	remaining := heap.Pop(&h).(int)

	if remaining < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
