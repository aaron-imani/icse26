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
	hp *Helper
}

func NewSolver() *Solver {
	return &Solver{
		hp: NewHelper(MOD, MAXN),
	}
}

func (s *Solver) Solve() {
	tc := 1 // Assuming single test case for simplicity
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
		s.hp.Println(straight[K]+1)
	} else {
		K -= int64(len(straight))
		s.hp.Println(cycle[int(K)%int64(len(cycle))]+1)
	}
}

type Helper struct {
	mod  int64
	maxn int
	rnd  *rand.Rand
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		mod:  mod,
		maxn: maxn,
		rnd:  rand.New(rand.NewSource(time.Now().UnixNano())),
	}
}

func (h *Helper) NextInt() int {
	scanner.Scan()
	return parseInt(scanner.Text())
}

func (h *Helper) NextLong() int64 {
	scanner.Scan()
	return parseLong(scanner.Text())
}

func (h *Helper) Println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

func (h *Helper) Flush() {
	writer.Flush()
}

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func parseInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func parseLong(s string) int64 {
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
// End of Code
