package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"time"
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
	sieve  []int
	primes []int
	factorial []int64
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		mod:    mod,
		maxn:   maxn,
		rnd:    rand.New(rand.NewSource(time.Now().UnixNano())),
		in:     bufio.NewScanner(os.Stdin),
		out:    bufio.NewWriter(os.Stdout),
		sieve:  make([]int, maxn),
		primes: []int{},
	}
}

func (h *Helper) setSieve() {
	for i := 2; i < h.maxn; i++ {
		if h.sieve[i] == 0 {
			h.primes = append(h.primes, i)
			for j := i; j < h.maxn; j += i {
				h.sieve[j] = i
			}
		}
	}
}

func (h *Helper) setFactorial() {
	h.factorial = make([]int64, h.maxn)
	h.factorial[0] = 1
	for i := 1; i < h.maxn; i++ {
		h.factorial[i] = h.factorial[i-1] * int64(i) % h.mod
	}
}

func (h *Helper) getFactorial(n int) int64 {
	if h.factorial == nil {
		h.setFactorial()
	}
	return h.factorial[n]
}

func (h *Helper) ncr(n, r int) int64 {
	if r > n {
		return 0
	}
	if h.factorial == nil {
		h.setFactorial()
	}
	numerator := h.factorial[n]
	denominator := h.factorial[r] * h.factorial[n-r] % h.mod
	return numerator * h.pow(denominator, h.mod-2, h.mod) % h.mod
}

func (h *Helper) getLongArray(size int) []int64 {
	ar := make([]int64, size)
	for i := 0; i < size; i++ {
		ar[i] = h.nextLong()
	}
	return ar
}

func (h *Helper) getIntArray(size int) []int {
	ar := make([]int, size)
	for i := 0; i < size; i++ {
		ar[i] = h.nextInt()
	}
	return ar
}

func (h *Helper) getStringArray(size int) []string {
	ar := make([]string, size)
	for i := 0; i < size; i++ {
		ar[i] = h.next()
	}
	return ar
}

func (h *Helper) joinElements(ar ...interface{}) string {
	var sb strings.Builder
	for _, itr := range ar {
		sb.WriteString(fmt.Sprintf("%v ", itr))
	}
	return strings.TrimSpace(sb.String())
}

func (h *Helper) gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func (h *Helper) max(ar ...int64) int64 {
	ret := ar[0]
	for _, itr := range ar {
		if itr > ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) min(ar ...int64) int64 {
	ret := ar[0]
	for _, itr := range ar {
		if itr < ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) sum(ar ...int64) int64 {
	var sum int64
	for _, itr := range ar {
		sum += itr
	}
	return sum
}

func (h *Helper) shuffle(ar []int) {
	for i := range ar {
		r := h.rnd.Intn(len(ar))
		if r != i {
			ar[i], ar[r] = ar[r], ar[i]
		}
	}
}

func (h *Helper) reverse(ar []int) {
	for i := 0; i < len(ar)/2; i++ {
		ar[i], ar[len(ar)-1-i] = ar[len(ar)-1-i], ar[i]
	}
}

func (h *Helper) pow(base, exp, MOD int64) int64 {
	base %= MOD
	ret := int64(1)
	for exp > 0 {
		if exp&1 == 1 {
			ret = ret * base % MOD
		}
		base = base * base % MOD
		exp >>= 1
	}
	return ret
}

func (h *Helper) next() string {
	h.in.Scan()
	return h.in.Text()
}

func (h *Helper) nextInt() int {
	str := h.next()
	num, _ := strconv.Atoi(str)
	return num
}

func (h *Helper) nextLong() int64 {
	str := h.next()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
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
	h.print(a)
	h.println()
}

func (h *Helper) flush() {
	h.out.Flush()
}

type Solver struct {
	hp        *Helper
	maxn      int
	mod       int64
	timer     *time.Timer
	task      *time.Timer
	testcases bool
}

func NewSolver() *Solver {
	hp := NewHelper(MOD, MAXN)
	hp.setSieve()
	hp.setFactorial()
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
		s.solveTc(tce)
	}
	s.timer.Stop()
	s.hp.flush()
}

func (s *Solver) solveTc(tc int) {
	var (
		i, j, k int
		N       = s.hp.nextInt()
		K       = s.hp.nextLong()
		A       = s.hp.getIntArray(N)
		straight []int
		cycle    []int
		vis      = make([]bool, N)
		curr     = 0
	)

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
	solver.timer = time.AfterFunc(2*time.Second, func() {
		solver.hp.flush()
		os.Exit(0)
	})
	solver.solve()
}
// End of Code
