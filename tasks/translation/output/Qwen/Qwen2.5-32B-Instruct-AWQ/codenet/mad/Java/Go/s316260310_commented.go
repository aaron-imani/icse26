package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"math/rand"
)

const (
	MOD  = 1000000007
	MAXN = 1000006
)

type Solver struct {
	hp *Helper
}

func NewSolver() *Solver {
	return &Solver{
		hp: NewHelper(MOD, MAXN),
	}
}

func (s *Solver) solve() {
	tc := 1
	if s.hp.TESTCASES {
		tc = s.hp.nextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solveForCase(tce)
	}
	s.hp.flush()
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
		s.hp.println(cycle[K%int64(len(cycle))] + 1)
	}
}

type Helper struct {
	MOD      int64
	MAXN     int
	rnd      *rand.Rand
	TESTCASES bool
	r        *bufio.Reader
	w        *bufio.Writer
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		MOD:      mod,
		MAXN:     maxn,
		rnd:      rand.New(rand.NewSource(1)),
		TESTCASES: false,
	}
}

func (h *Helper) initIO() {
	h.r = bufio.NewReader(os.Stdin)
	h.w = bufio.NewWriter(os.Stdout)
}

func (h *Helper) next() string {
	line, _ := h.r.ReadString('
')
	return strings.TrimSpace(line)
}

func (h *Helper) nextInt() int {
	line := h.next()
	n, _ := strconv.Atoi(line)
	return n
}

func (h *Helper) nextLong() int64 {
	line := h.next()
	n, _ := strconv.ParseInt(line, 10, 64)
	return n
}

func (h *Helper) getIntArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = h.nextInt()
	}
	return arr
}

func (h *Helper) println(a interface{}) {
	fmt.Fprintf(h.w, "%v\n", a)
}

func (h *Helper) flush() {
	h.w.Flush()
}

func main() {
	s := NewSolver()
	s.hp.initIO()
	s.solve()
}
// End of Code
