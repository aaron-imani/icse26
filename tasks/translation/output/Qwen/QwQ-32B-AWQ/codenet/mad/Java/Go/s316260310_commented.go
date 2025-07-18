package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Helper struct {
	MOD    int64
	MAXN   int
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		MOD:   mod,
		MAXN:  maxn,
	}
}

func (h *Helper) InitIO(in io.Reader, out io.Writer) {
	h.reader = bufio.NewReader(in)
	h.writer = bufio.NewWriter(out)
}

func (h *Helper) Next() (string, error) {
	var b byte
	for {
		b, err := h.reader.ReadByte()
		if err != nil {
			return "", err
		}
		if b > ' ' {
			break
		}
	}
	str := string(b)
	for {
		b, err := h.reader.ReadByte()
		if err != nil {
			break
		}
		if b <= ' ' {
			break
		}
		str += string(b)
	}
	return str, nil
}

func (h *Helper) NextInt() (int, error) {
	str, err := h.Next()
	if err != nil {
		return 0, err
	}
	n, err := strconv.Atoi(str)
	return n, err
}

func (h *Helper) NextLong() (int64, error) {
	str, err := h.Next()
	if err != nil {
		return 0, err
	}
	n, err := strconv.ParseInt(str, 10, 64)
	return n, err
}

func (h *Helper) GetIntArray(n int) ([]int, error) {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		num, err := h.NextInt()
		if err != nil {
			return nil, err
		}
		arr[i] = num
	}
	return arr, nil
}

func (h *Helper) Println(a ...interface{}) error {
	_, err := fmt.Fprintln(h.writer, a...)
	return err
}

func (h *Helper) Flush() error {
	return h.writer.Flush()
}

type Solver struct {
	hp        *Helper
	TestCases bool
}

func NewSolver() *Solver {
	h := NewHelper(1000000007, 1000006)
	h.InitIO(os.Stdin, os.Stdout)
	return &Solver{hp: h, TestCases: false}
}

func (s *Solver) Solve() {
	tc := 1
	if s.TestCases {
		tc, _ = s.hp.NextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solveOne(tce)
	}
	s.hp.Flush()
}

func (s *Solver) solveOne(tc int) {
	N, _ := s.hp.NextInt()
	K, _ := s.hp.NextLong()
	A, _ := s.hp.GetIntArray(N)

	straight := make([]int, 0)
	cycle := make([]int, 0)
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
		s.hp.Println(straight[K] + 1)
	} else {
		K -= int64(len(straight))
		idx := int(K) % len(cycle)
		s.hp.Println(cycle[idx] + 1)
	}
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
// End of Code
