package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

const (
	MAXN = 1000006
	MOD  = 1000000007
)

type Solver struct {
	hp       *Helper
	TESTCASES bool
}

func (s *Solver) solve() error {
	tc := 1
	if s.TESTCASES {
		var err error
		tc, err = s.hp.nextInt()
		if err != nil {
			return err
		}
	}
	for tce := 1; tce <= tc; tce++ {
		if err := s.solveTc(tce); err != nil {
			return err
		}
	}
	s.hp.flush()
	return nil
}

func (s *Solver) solveTc(tc int) error {
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
	return nil
}

type Helper struct {
	MOD  int64
	MAXN int
	rnd  *rand.Rand
	in   *bufio.Scanner
	out  *bufio.Writer
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		MOD:  mod,
		MAXN: maxn,
		rnd:  rand.New(rand.NewSource(time.Now().UnixNano())),
	}
}

func (h *Helper) initIO(in *os.File, out *os.File) {
	h.in = bufio.NewScanner(in)
	h.in.Buffer(make([]byte, 1<<20), 1<<20)
	h.out = bufio.NewWriter(out)
}

func (h *Helper) next() (string, error) {
	if !h.in.Scan() {
		return "", h.in.Err()
	}
	return h.in.Text(), nil
}

func (h *Helper) nextInt() (int, error) {
	s, err := h.next()
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(s)
}

func (h *Helper) nextLong() (int64, error) {
	s, err := h.next()
	if err != nil {
		return 0, err
	}
	return strconv.ParseInt(s, 10, 64)
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
	fmt.Fprint(h.out, a)
}

func (h *Helper) println(a interface{}) {
	fmt.Fprintln(h.out, a)
}

func (h *Helper) flush() error {
	return h.out.Flush()
}

func main() {
	hp := NewHelper(MOD, MAXN)
	hp.initIO(os.Stdin, os.Stdout)
	solver := &Solver{
		hp:        hp,
		TESTCASES: false,
	}
	if err := solver.solve(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
	os.Exit(0)
}
// End of Code
