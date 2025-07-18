package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"container/heap"
)

type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i] < pq[j] }

func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	pq := &PriorityQueue{}
	heap.Init(pq)
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(strings.Fields(scanner.Text())[0])
		heap.Push(pq, num)
	}

	sum := 0
	for i := 0; i < n-1; i++ {
		sum += heap.Pop(pq).(int)
	}

	if (*pq)[0] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
