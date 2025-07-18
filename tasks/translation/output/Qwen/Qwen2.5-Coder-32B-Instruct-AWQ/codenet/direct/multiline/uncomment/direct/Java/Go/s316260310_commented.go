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
		buf:  make([]byte, 1<<20),
	}
	h.in = bufio.NewScanner(os.Stdin)
	h.in.Buffer(h.buf, h.maxn)
	h.out = bufio.NewWriter(os.Stdout)
	return h
}

func (h *Helper) InitIO(in *os.File, out *os.File) {
	h.in = bufio.NewScanner(in)
	h.in.Buffer(h.buf, h.maxn)
	h.out = bufio.NewWriter(out)
}

func (h *Helper) Next() string {
	h.in.Scan()
	return h.in.Text()
}

func (h *Helper) NextInt() int {
	s := h.Next()
	i, _ := strconv.Atoi(s)
	return i
}

func (h *Helper) NextLong() int64 {
	s := h.Next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func (h *Helper) GetIntArray(size int) []int {
	ar := make([]int, size)
	for i := 0; i < size; i++ {
		ar[i] = h.NextInt()
	}
	return ar
}

func (h *Helper) Print(a interface{}) {
	fmt.Fprint(h.out, a)
}

func (h *Helper) Println(a interface{}) {
	fmt.Fprintln(h.out, a)
}

func (h *Helper) Flush() {
	h.out.Flush()
}

type Solver struct {
	hp         *Helper
	testCases  bool
	straight   []int
	cycle      []int
	visited    []bool
	current    int
	start      int
}

func NewSolver() *Solver {
	hp := NewHelper(MOD, MAXN)
	hp.InitIO(os.Stdin, os.Stdout)
	return &Solver{
		hp:        hp,
		testCases: false,
	}
}

func (s *Solver) Solve() {
	tc := 1
	if s.testCases {
		tc = s.hp.NextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solve(tce)
	}
	s.hp.Flush()
}

func (s *Solver) solve(tc int) {
	N := s.hp.NextInt()
	K := s.hp.NextLong()
	A := s.hp.GetIntArray(N)

	s.straight = []int{}
	s.cycle = []int{}
	s.visited = make([]bool, N)
	s.current = 0

	for !s.visited[s.current] {
		s.visited[s.current] = true
		s.current = A[s.current] - 1
	}

	s.start = 0
	for s.start != s.current {
		s.straight = append(s.straight, s.start)
		s.start = A[s.start] - 1
	}

	s.cycle = append(s.cycle, s.current)
	s.current = A[s.current] - 1
	for s.current != s.cycle[0] {
		s.cycle = append(s.cycle, s.current)
		s.current = A[s.current] - 1
	}

	if K < int64(len(s.straight)) {
		s.hp.Println(s.straight[K] + 1)
	} else {
		K -= int64(len(s.straight))
		s.hp.Println(s.cycle[K%int64(len(s.cycle))] + 1)
	}
}

func main() {
	solver := NewSolver()
	solver.Solve()
}

// End of Code
