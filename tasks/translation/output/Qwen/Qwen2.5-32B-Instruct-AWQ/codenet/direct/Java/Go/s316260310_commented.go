package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MOD = 1e9 + 7
	MAXN = 1000006
)

type Solver struct {
	hp Helper
}

func NewSolver() *Solver {
	return &Solver{
		hp: Helper{
			mod: MOD,
			maxn: MAXN,
		},
	}
}

func (s *Solver) solve() {
	tc := 1 // Assuming no test cases for simplicity
	for tce := 1; tce <= tc; tce++ {
		s.solveForCase(tce)
	}
}

func (s *Solver) solveForCase(tc int) {
	N := s.hp.nextInt()
	K := s.hp.nextLong()
	A := s.hp.getIntArray(N)

	straight := []int{}
	cycle := []int{}
	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		curr = A[curr] - 1
	}

	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	cycle = append(cycle, curr)
	curr = A[curr] - 1
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr] - 1
	}

	if K < int64(len(straight)) {
		s.hp.println(straight[K] + 1)
	} else {
		K -= int64(len(straight))
		s.hp.println(cycle[K % int64(len(cycle))] + 1)
	}
}

type Helper struct {
	mod int64
	maxn int
}

func (h *Helper) initIO() {
	h.hp = bufio.NewScanner(os.Stdin)
	h.bw = bufio.NewWriter(os.Stdout)
}

func (h *Helper) nextInt() int {
	h.hp.Scan()
	return h.hp.Int()
}

func (h *Helper) nextLong() int64 {
	h.hp.Scan()
	return h.hp.Int64()
}

func (h *Helper) getIntArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = h.nextInt()
	}
	return arr
}

func (h *Helper) println(a interface{}) {
	fmt.Fprintln(h.bw, a)
}

func (h *Helper) flush() {
	h.bw.Flush()
}

func main() {
	solver := NewSolver()
	solver.hp.initIO()
	solver.solve()
	solver.hp.flush()
}
// End of Code
