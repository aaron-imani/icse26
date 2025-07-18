package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MOD  = 1000000007
	MAXN = 1000006
)

type Helper struct {
	mod  int64
	maxn int
	rnd  *rand.Rand
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		mod:  mod,
		maxn: maxn,
		rnd:  rand.New(rand.NewSource(1)),
	}
}

func (h *Helper) setSieve() {
	primes := make([]int, 0)
	sieve := make([]int, h.maxn)
	for i := 2; i < h.maxn; i++ {
		if sieve[i] == 0 {
			primes = append(primes, i)
			for j := i; j < h.maxn; j += i {
				sieve[j] = i
			}
		}
	}
}

func (h *Helper) setFactorial() {
	factorial := make([]int64, h.maxn)
	factorial[0] = 1
	for i := 1; i < h.maxn; i++ {
		factorial[i] = factorial[i-1] * int64(i) % h.mod
	}
	h.factorial = factorial
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

func (h *Helper) getLongArray(size int) ([]int64, error) {
	ar := make([]int64, size)
	for i := 0; i < size; i++ {
		ar[i] = h.nextLong()
	}
	return ar, nil
}

func (h *Helper) getIntArray(size int) ([]int, error) {
	ar := make([]int, size)
	for i := 0; i < size; i++ {
		ar[i] = h.nextInt()
	}
	return ar, nil
}

func (h *Helper) getStringArray(size int) ([]string, error) {
	ar := make([]string, size)
	for i := 0; i < size; i++ {
		ar[i] = h.next()
	}
	return ar, nil
}

func (h *Helper) joinElements(ar ...interface{}) string {
	var sb strings.Builder
	for _, itr := range ar {
		sb.WriteString(fmt.Sprintf("%v ", itr))
	}
	return strings.TrimSpace(sb.String())
}

func (h *Helper) gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return h.gcd(b, a%b)
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
	sum := int64(0)
	for _, itr := range ar {
		sum += itr
	}
	return sum
}

func (h *Helper) shuffle(ar []int) {
	for i := 0; i < len(ar); i++ {
		r := h.rnd.Intn(len(ar))
		if r != i {
			ar[i], ar[r] = ar[r], ar[i]
		}
	}
}

func (h *Helper) reverse(ar []int) {
	for i := 0; i < len(ar); i++ {
		r := len(ar) - 1 - i
		if r > i {
			ar[i], ar[r] = ar[r], ar[i]
		}
	}
}

func (h *Helper) pow(base, exp, mod int64) int64 {
	base %= mod
	ret := int64(1)
	for exp > 0 {
		if exp&1 == 1 {
			ret = ret * base % mod
		}
		base = base * base % mod
		exp >>= 1
	}
	return ret
}

func (h *Helper) initIO(is io.Reader, os io.Writer) {
	h.in = bufio.NewReader(is)
	h.bw = bufio.NewWriter(os)
}

func (h *Helper) initIOFile(inputFile, outputFile string) error {
	fin, err := os.Open(inputFile)
	if err != nil {
		return err
	}
	h.in = bufio.NewReader(fin)
	fout, err := os.Create(outputFile)
	if err != nil {
		return err
	}
	h.bw = bufio.NewWriter(fout)
	return nil
}

func (h *Helper) scan() (int, error) {
	if h.index >= h.total {
		h.index = 0
		h.total, err := h.in.Read(h.buf)
		if h.total <= 0 {
			return -1, nil
		}
	}
	c := h.buf[h.index]
	h.index++
	return int(c), nil
}

func (h *Helper) next() (string, error) {
	var c int
	for c, _ = h.scan(); c <= 32; c, _ = h.scan() {
	}
	var sb strings.Builder
	for c > 32 {
		sb.WriteByte(byte(c))
		c, _ = h.scan()
	}
	return sb.String(), nil
}

func (h *Helper) nextInt() (int, error) {
	var c int
	var val int
	for c, _ = h.scan(); c <= 32; c, _ = h.scan() {
	}
	neg := c == '-'
	if c == '-' || c == '+' {
		c, _ = h.scan()
	}
	for c >= '0' && c <= '9' {
		val = (val << 3) + (val << 1) + (c & 15)
		c, _ = h.scan()
	}
	if neg {
		return -val, nil
	}
	return val, nil
}

func (h *Helper) nextLong() (int64, error) {
	var c int
	var val int64
	for c, _ = h.scan(); c <= 32; c, _ = h.scan() {
	}
	neg := c == '-'
	if c == '-' || c == '+' {
		c, _ = h.scan()
	}
	for c >= '0' && c <= '9' {
		val = (val << 3) + (val << 1) + int64(c&15)
		c, _ = h.scan()
	}
	if neg {
		return -val, nil
	}
	return val, nil
}

func (h *Helper) print(a interface{}) error {
	_, err := h.bw.WriteString(fmt.Sprintf("%v", a))
	return err
}

func (h *Helper) printsp(a interface{}) error {
	err := h.print(a)
	if err != nil {
		return err
	}
	return h.print(" ")
}

func (h *Helper) println() error {
	_, err := h.bw.WriteString("\n")
	return err
}

func (h *Helper) println(a interface{}) error {
	err := h.print(a)
	if err != nil {
		return err
	}
	return h.println()
}

func (h *Helper) flush() error {
	return h.bw.Flush()
}

type Solver struct {
	hp        *Helper
	MAXN      int
	MOD       int64
	TESTCASES bool
}

func NewSolver(mod int64, maxn int) *Solver {
	hp := NewHelper(mod, maxn)
	hp.initIO(os.Stdin, os.Stdout)
	return &Solver{
		hp:    hp,
		MAXN:  maxn,
		MOD:   mod,
	}
}

func (s *Solver) solve() error {
	tc := 1
	if s.TESTCASES {
		tc = s.hp.nextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		err := s.solve(tce)
		if err != nil {
			return err
		}
	}
	s.hp.flush()
	return nil
}

func (s *Solver) solve(tc int) error {
	N := s.hp.nextInt()
	K := s.hp.nextLong()
	A, err := s.hp.getIntArray(N)
	if err != nil {
		return err
	}

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
		s.hp.println(straight[K]+1)
	} else {
		K -= int64(len(straight))
		s.hp.println(cycle[K%int64(len(cycle))]+1)
	}
	return nil
}

func main() {
	solver := NewSolver(MOD, MAXN)
	err := solver.solve()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}
	os.Exit(0)
}
// End of Code
