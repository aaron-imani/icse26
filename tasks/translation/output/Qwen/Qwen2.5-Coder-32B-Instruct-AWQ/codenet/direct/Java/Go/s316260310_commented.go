package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MAXN = 1000006
	MOD  = 1000000007
)

type Helper struct {
	mod    int64
	maxn   int
	rnd    *rand.Rand
	in     *bufio.Scanner
	out    *bufio.Writer
	buf    []byte
	index  int
	total  int
}

func NewHelper(mod int64, maxn int) *Helper {
	h := &Helper{
		mod:  mod,
		maxn: maxn,
		rnd:  rand.New(rand.NewSource(time.Now().UnixNano())),
		buf:  make([]byte, 1<<20),
	}
	h.in = bufio.NewScanner(os.Stdin)
	h.in.Buffer(h.buf, h.maxn)
	h.out = bufio.NewWriter(os.Stdout)
	return h
}

func (h *Helper) initIO(in *bufio.Scanner, out *bufio.Writer) {
	h.in = in
	h.out = out
}

func (h *Helper) next() string {
	h.in.Scan()
	return h.in.Text()
}

func (h *Helper) nextInt() int {
	s := h.next()
	i, _ := strconv.Atoi(s)
	return i
}

func (h *Helper) nextLong() int64 {
	s := h.next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func (h *Helper) getIntArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = h.nextInt()
	}
	return arr
}

func (h *Helper) println(a ...interface{}) {
	fmt.Fprintln(h.out, a...)
}

func (h *Helper) flush() {
	h.out.Flush()
}

type Solver struct {
	hp        *Helper
	maxn      int
	mod       int64
	testcases bool
}

func NewSolver() *Solver {
	hp := NewHelper(MOD, MAXN)
	hp.initIO(bufio.NewScanner(os.Stdin), bufio.NewWriter(os.Stdout))
	return &Solver{
		hp:        hp,
		maxn:      MAXN,
		mod:       MOD,
		testcases: false,
	}
}

func (s *Solver) solve() {
	tc := 1
	if s.testcases {
		tc = s.hp.nextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solveCase(tce)
	}
	s.hp.flush()
}

func (s *Solver) solveCase(tc int) {
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

func main() {
	solver := NewSolver()
	solver.solve()
}

// End of Code
