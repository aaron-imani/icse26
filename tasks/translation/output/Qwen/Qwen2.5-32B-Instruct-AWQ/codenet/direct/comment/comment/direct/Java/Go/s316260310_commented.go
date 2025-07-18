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
	tc := 1 // Assuming no test cases
	for tce := 1; tce <= tc; tce++ {
		s.solve(tce)
	}
	s.hp.Flush()
}

func (s *Solver) solve(tc int) {
	N := s.hp.NextInt()
	K := s.hp.NextLong()
	A := s.hp.GetIntArray(N)

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
		s.hp.Println(straight[K]+1)
	} else {
		K -= int64(len(straight))
		s.hp.Println(cycle[int(K)%int64(len(cycle))]+1)
	}
}

type Helper struct {
	mod  int
	maxn int
	rnd  *rand.Rand
}

func NewHelper(mod int, maxn int) *Helper {
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

func (h *Helper) GetIntArray(size int) []int {
	ar := make([]int, size)
	for i := 0; i < size; i++ {
		ar[i] = h.NextInt()
	}
	return ar
}

func (h *Helper) Println(a interface{}) {
	fmt.Println(a)
}

func (h *Helper) Flush() {
	os.Stdout.Sync()
}

var scanner = bufio.NewScanner(os.Stdin)

func parseInt(s string) int {
	v, _ := strconv.Atoi(s)
	return v
}

func parseLong(s string) int64 {
	v, _ := strconv.ParseInt(s, 10, 64)
	return v
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
// End of Code
