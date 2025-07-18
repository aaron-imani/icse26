package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAXN = 1000006
	MOD  = 1000000007
)

type Solver struct {
	hp     Helper
	timer  *Timer
	task   *TimerTask
}

func NewSolver() *Solver {
	s := &Solver{
		hp: Helper{MOD: MOD, MAXN: MAXN},
	}
	s.hp.InitIO(os.Stdin, os.Stdout)
	return s
}

func (s *Solver) Solve() {
	tc := 1 // Assuming no test cases for simplicity
	for tce := 1; tce <= tc; tce++ {
		s.solve(tce)
	}
	s.hp.Flush()
}

func (s *Solver) solve(tc int) {
	N := s.hp.NextInt()
	K := s.hp.NextLong()
	A := make([]int, N)
	for i := range A {
		A[i] = s.hp.NextInt() - 1
	}

	straight := []int{}
	cycle := []int{}
	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		straight = append(straight, curr)
		curr = A[curr]
	}

	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st]
	}

	cycle = append(cycle, curr)
	curr = A[curr]
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr]
	}

	if K < int64(len(straight)) {
		fmt.Println(straight[K]+1)
	} else {
		K -= int64(len(straight))
		fmt.Println(cycle[int(K)%int64(len(cycle))]+1)
	}
}

type Helper struct {
	MOD  int
	MAXN int
	rnd  *rand.Rand
}

func (h *Helper) InitIO(in io.Reader, out io.Writer) {
	h.rnd = rand.New(rand.NewSource(time.Now().UnixNano()))
	h.reader = bufio.NewReader(in)
	h.writer = bufio.NewWriter(out)
}

func (h *Helper) NextInt() int {
	num, _ := h.reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(num))
	return n
}

func (h *Helper) NextLong() int64 {
	num, _ := h.reader.ReadString('\n')
	n, _ := strconv.ParseInt(strings.TrimSpace(num), 10, 64)
	return n
}

func (h *Helper) Flush() {
	h.writer.Flush()
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
// End of Code
