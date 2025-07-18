import (
	"bufio"
	"os"
	"strconv"
	"container/heap"
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

// Main function to read input and process
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read elements
	elements := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		elements[i] = num
	}

	// Initialize the heap
	h := &IntHeap(elements)
	heap.Init(h)

	sum := 0
	// Sum all except the largest
	for i := 0; i < n-1; i++ {
		v := heap.Pop(h).(int)
		sum += v
	}

	// Check the condition
	maxElement := heap.Pop(h).(int)
	if maxElement < sum {
		println("Yes")
	} else {
		println("No")
	}
}
// End of Code
