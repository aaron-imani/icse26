import (
	"bufio"
	"fmt"
	"os"
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
	var n int
	fmt.Scanf("%d", &n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &data[i])
	}
	h := &IntHeap(data)
	heap.Init(h)

	sum := 0
	for i := 0; i < n-1; i++ {
		val := heap.Pop(h).(int)
		sum += val
	}

	last := (*h)[0]
	if last < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
