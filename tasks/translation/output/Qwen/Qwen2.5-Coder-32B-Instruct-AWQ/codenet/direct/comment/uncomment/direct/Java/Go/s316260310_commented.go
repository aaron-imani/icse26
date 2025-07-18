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
	mod   int64
	maxn  int
	rnd   *rand.Rand
	in    *bufio.Scanner
	out   *bufio.Writer
	buf   []byte
	index int
	total int
}

func NewHelper(mod int64, maxn int) *Helper {
	h := &Helper{
		mod:  mod,
		maxn: maxn,
		rnd:  rand.New(rand.NewSource(time.Now().UnixNano())),
	}
	h.buf = make([]byte, 1<<20)
	return h
}

func (h *Helper) initIO(in *os.File, out *os.File) {
	h.in = bufio.NewScanner(in)
	h.in.Buffer(h.buf, len(h.buf))
	h.out = bufio.NewWriter(out)
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
	hp         *Helper
	TESTCASES  bool
	timer      *time.Timer
	task       *time.Timer
	straight   []int
	cycle      []int
	vis        []bool
	curr       int
	st         int
	N          int
	K          int64
	A          []int
}

func NewSolver(hp *Helper) *Solver {
	s := &Solver{
		hp:        hp,
		TESTCASES: false,
	}
	return s
}

func (s *Solver) solve() {
	tc := 1
	if s.TESTCASES {
		tc = s.hp.nextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solveTc(tce)
	}
	s.timer.Stop()
	s.hp.flush()
}

func (s *Solver) solveTc(tc int) {
	s.N = s.hp.nextInt()
	s.K = s.hp.nextLong()
	s.A = s.hp.getIntArray(s.N)

	s.straight = []int{}
	s.cycle = []int{}
	s.vis = make([]bool, s.N)
	s.curr = 0
	for !s.vis[s.curr] {
		s.vis[s.curr] = true
		s.curr = s.A[s.curr] - 1
	}

	s.st = 0
	for s.st != s.curr {
		s.straight = append(s.straight, s.st)
		s.st = s.A[s.st] - 1
	}

	s.cycle = append(s.cycle, s.curr)
	s.curr = s.A[s.curr] - 1
	for s.curr != s.cycle[0] {
		s.cycle = append(s.cycle, s.curr)
		s.curr = s.A[s.curr] - 1
	}

	if s.K < int64(len(s.straight)) {
		s.hp.println(s.straight[s.K] + 1)
	} else {
		s.K -= int64(len(s.straight))
		s.hp.println(s.cycle[s.K%int64(len(s.cycle))] + 1)
	}
}

func main() {
	hp := NewHelper(MOD, MAXN)
	hp.initIO(os.Stdin, os.Stdout)
	solver := NewSolver(hp)
	solver.solve()
}

// End of Code
