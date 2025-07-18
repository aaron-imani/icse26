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
	in     *bufio.Reader
	out    *bufio.Writer
	buf    []byte
	index  int
	total  int
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		mod:  mod,
		maxn: maxn,
		buf:  make([]byte, 1<<20),
	}
}

func (h *Helper) initIO(in *os.File, out *os.File) {
	h.in = bufio.NewReader(in)
	h.out = bufio.NewWriter(out)
}

func (h *Helper) scan() (int, error) {
	if h.index >= h.total {
		h.index = 0
		var err error
		h.total, err = h.in.Read(h.buf)
		if err != nil {
			return -1, err
		}
		if h.total <= 0 {
			return -1, nil
		}
	}
	c := h.buf[h.index]
	h.index++
	return int(c), nil
}

func (h *Helper) next() (string, error) {
	c, err := h.scan()
	if err != nil {
		return "", err
	}
	for c <= 32 {
		c, err = h.scan()
		if err != nil {
			return "", err
		}
	}
	var sb strings.Builder
	for c > 32 {
		sb.WriteByte(byte(c))
		c, err = h.scan()
		if err != nil {
			break
		}
	}
	return sb.String(), nil
}

func (h *Helper) nextInt() (int, error) {
	c, err := h.scan()
	if err != nil {
		return 0, err
	}
	for c <= 32 {
		c, err = h.scan()
		if err != nil {
			return 0, err
		}
	}
	neg := c == '-'
	if c == '-' || c == '+' {
		c, err = h.scan()
		if err != nil {
			return 0, err
		}
	}
	var val int
	for c >= '0' && c <= '9' {
		val = (val << 3) + (val << 1) + int(c-'0')
		c, err = h.scan()
		if err != nil {
			break
		}
	}
	if neg {
		return -val, nil
	}
	return val, nil
}

func (h *Helper) nextLong() (int64, error) {
	c, err := h.scan()
	if err != nil {
		return 0, err
	}
	for c <= 32 {
		c, err = h.scan()
		if err != nil {
			return 0, err
		}
	}
	neg := c == '-'
	if c == '-' || c == '+' {
		c, err = h.scan()
		if err != nil {
			return 0, err
		}
	}
	var val int64
	for c >= '0' && c <= '9' {
		val = (val << 3) + (val << 1) + int64(c-'0')
		c, err = h.scan()
		if err != nil {
			break
		}
	}
	if neg {
		return -val, nil
	}
	return val, nil
}

func (h *Helper) getIntArray(size int) ([]int, error) {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		var err error
		arr[i], err = h.nextInt()
		if err != nil {
			return nil, err
		}
	}
	return arr, nil
}

func (h *Helper) print(a interface{}) {
	fmt.Fprintf(h.out, "%v", a)
}

func (h *Helper) printsp(a interface{}) {
	h.print(a)
	h.print(" ")
}

func (h *Helper) println() {
	h.print("\n")
}

func (h *Helper) printlnsp(a interface{}) {
	h.printsp(a)
	h.println()
}

func (h *Helper) flush() error {
	return h.out.Flush()
}

type Solver struct {
	hp         *Helper
	maxn       int
	mod        int64
	testCases  bool
	straight   []int
	cycle      []int
	visited    []bool
	current    int
	start      int
}

func NewSolver(mod int64, maxn int) *Solver {
	return &Solver{
		hp:     NewHelper(mod, maxn),
		maxn:   maxn,
		mod:    mod,
		testCases: false,
		straight:  []int{},
		cycle:     []int{},
		visited:   make([]bool, maxn),
		current:   0,
		start:     0,
	}
}

func (s *Solver) solve() error {
	var err error
	var tc int
	if s.testCases {
		tc, err = s.hp.nextInt()
		if err != nil {
			return err
		}
	} else {
		tc = 1
	}
	for tce := 1; tce <= tc; tce++ {
		err = s.solveTestCase(tce)
		if err != nil {
			return err
		}
	}
	err = s.hp.flush()
	if err != nil {
		return err
	}
	return nil
}

func (s *Solver) solveTestCase(tc int) error {
	var err error
	N, err := s.hp.nextInt()
	if err != nil {
		return err
	}
	K, err := s.hp.nextLong()
	if err != nil {
		return err
	}
	A, err := s.hp.getIntArray(N)
	if err != nil {
		return err
	}

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
		s.hp.println(s.straight[K] + 1)
	} else {
		K -= int64(len(s.straight))
		s.hp.println(s.cycle[K%int64(len(s.cycle))] + 1)
	}
	return nil
}

func main() {
	solver := NewSolver(MOD, MAXN)
	solver.hp.initIO(os.Stdin, os.Stdout)
	err := solver.solve()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}
	solver.hp.flush()
	os.Exit(0)
}

// End of Code
