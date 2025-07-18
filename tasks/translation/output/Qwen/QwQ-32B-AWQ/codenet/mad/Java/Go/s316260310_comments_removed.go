package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const BUFSIZE = 1 << 20

type Helper struct {
	MOD          int64
	MAXN         int
	buf          []byte
	index        int
	total        int
	in           *bufio.Reader
	out          *bufio.Writer
}

func (h *Helper) InitIO(r io.Reader, w io.Writer) {
	h.in = bufio.NewReader(r)
	h.out = bufio.NewWriter(w)
	h.buf = make([]byte, BUFSIZE)
	h.index = 0
	h.total = 0
}

func (h *Helper) scan() (byte, error) {
	for h.index >= h.total {
		h.index = 0
		h.total, _ = h.in.Read(h.buf)
		if h.total == 0 {
			return 0, io.EOF
		}
	}
	b := h.buf[h.index]
	h.index++
	return b, nil
}

func (h *Helper) next() (string, error) {
	var b byte
	for {
		var err error
		b, err = h.scan()
		if err != nil {
			return "", err
		}
		if b == ' ' || b == '\n' || b == '\r' || b == '\t' {
			continue
		}
		break
	}
	var str strings.Builder
	str.WriteByte(b)
	for {
		var err error
		b, err = h.scan()
		if err != nil {
			break
		}
		if b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == 0 {
			break
		}
		str.WriteByte(b)
	}
	return str.String(), nil
}

func (h *Helper) NextInt() (int, error) {
	s, err := h.next()
	if err != nil {
		return 0, err
	}
	n, err := strconv.Atoi(s)
	return n, err
}

func (h *Helper) NextLong() (int64, error) {
	s, err := h.next()
	if err != nil {
		return 0, err
	}
	n, err := strconv.ParseInt(s, 10, 64)
	return n, err
}

func (h *Helper) GetIntArray(size int) ([]int, error) {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		n, err := h.NextInt()
		if err != nil {
			return nil, err
		}
		arr[i] = n
	}
	return arr, nil
}

func (h *Helper) Println(a interface{}) error {
	_, err := fmt.Fprintln(h.out, a)
	return err
}

func (h *Helper) Flush() error {
	return h.out.Flush()
}

type Solver struct {
	hp   Helper
	MAXN int
	MOD  int64
}

func NewSolver() *Solver {
	maxn := 1000006
	mod := int64(1e9 + 7)
	hp := Helper{
		MOD:  mod,
		MAXN: maxn,
	}
	hp.InitIO(os.Stdin, os.Stdout)
	return &Solver{
		hp:   hp,
		MAXN: maxn,
		MOD:  mod,
	}
}

func (s *Solver) Solve() {
	tc, _ := s.hp.NextInt()
	for tce := 1; tce <= tc; tce++ {
		s.solve()
	}
	s.hp.Flush()
}

func (s *Solver) solve() {
	N, _ := s.hp.NextInt()
	K, _ := s.hp.NextLong()
	A, _ := s.hp.GetIntArray(N)

	var straight, cycle []int
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

	cycleLength := int64(len(cycle))
	if K < int64(len(straight)) {
		s.hp.Println(straight[int(K)] + 1)
	} else {
		K -= int64(len(straight))
		idx := int(K % cycleLength)
		s.hp.Println(cycle[idx]+1)
	}
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
// End of Code
