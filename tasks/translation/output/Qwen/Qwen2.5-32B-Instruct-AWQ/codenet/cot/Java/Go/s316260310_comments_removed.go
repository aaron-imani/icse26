package main

import (
	"fmt"
	"os"
	"time"
)

type Solver struct {
	hp    Helper
	MAXN  int
	MOD   int64
	timer *time.Timer
	task  *time.Timer
}

func (s *Solver) solve() {
	tc := 1
	if s.hp.TESTCASES {
		tc = s.hp.nextInt()
	}
	for tce := 1; tce <= tc; tce++ {
		s.solve(tce)
	}
	s.timer.Stop()
	s.hp.flush()
}

func (s *Solver) solve(tc int) {
	N := s.hp.nextInt()
	K := s.hp.nextLong()
	A := s.hp.getIntArray(N)

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
		fmt.Println(straight[K] + 1)
	} else {
		K -= int64(len(straight))
		fmt.Println(cycle[K%int64(len(cycle))] + 1)
	}
}

type Helper struct {
	MOD         int64
	MAXN        int
	rnd         *time.Time
	sieve       []int
	primes      []int
	factorial   []int64
	TESTCASES   bool
	inputReader *os.File
	outputWriter *os.File
}

func NewHelper(mod int64, maxn int) *Helper {
	return &Helper{
		MOD:   mod,
		MAXN:  maxn,
		rnd:   time.Now(),
		sieve: make([]int, maxn),
		primes: make([]int, 0),
		factorial: make([]int64, maxn),
	}
}

func (h *Helper) setSieve() {
	for i := 2; i < h.MAXN; i++ {
		if h.sieve[i] == 0 {
			h.primes = append(h.primes, i)
			for j := i; j < h.MAXN; j += i {
				h.sieve[j] = i
			}
		}
	}
}

func (h *Helper) setFactorial() {
	h.factorial[0] = 1
	for i := 1; i < h.MAXN; i++ {
		h.factorial[i] = h.factorial[i-1] * int64(i) % h.MOD
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
	denominator := h.factorial[r] * h.factorial[n-r] % h.MOD
	return numerator * h.pow(denominator, h.MOD-2, h.MOD) % h.MOD
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

func (h *Helper) joinElements(ar []int64) string {
	var sb strings.Builder
	for _, itr := range ar {
		sb.WriteString(fmt.Sprintf("%d ", itr))
	}
	return strings.TrimSpace(sb.String())
}

func (h *Helper) joinElements(ar []int) string {
	var sb strings.Builder
	for _, itr := range ar {
		sb.WriteString(fmt.Sprintf("%d ", itr))
	}
	return strings.TrimSpace(sb.String())
}

func (h *Helper) joinElements(ar []string) string {
	var sb strings.Builder
	for _, itr := range ar {
		sb.WriteString(fmt.Sprintf("%s ", itr))
	}
	return strings.TrimSpace(sb.String())
}

func (h *Helper) joinElements(ar []interface{}) string {
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

func (h *Helper) gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return h.gcd(b, a%b)
}

func (h *Helper) max(ar []int64) int64 {
	ret := ar[0]
	for _, itr := range ar {
		if itr > ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) max(ar []int) int {
	ret := ar[0]
	for _, itr := range ar {
		if itr > ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) min(ar []int64) int64 {
	ret := ar[0]
	for _, itr := range ar {
		if itr < ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) min(ar []int) int {
	ret := ar[0]
	for _, itr := range ar {
		if itr < ret {
			ret = itr
		}
	}
	return ret
}

func (h *Helper) sum(ar []int64) int64 {
	sum := int64(0)
	for _, itr := range ar {
		sum += itr
	}
	return sum
}

func (h *Helper) sum(ar []int) int64 {
	sum := int64(0)
	for _, itr := range ar {
		sum += int64(itr)
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

func (h *Helper) shuffle(ar []int64) {
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

func (h *Helper) reverse(ar []int64) {
	for i := 0; i < len(ar); i++ {
		r := len(ar) - 1 - i
		if r > i {
			ar[i], ar[r] = ar[r], ar[i]
		}
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

func (h *Helper) initIO(is *os.File, os *os.File) {
	h.inputReader = is
	h.outputWriter = os
}

func (h *Helper) initIO(inputFile, outputFile string) {
	var err error
	h.inputReader, err = os.Open(inputFile)
	if err != nil {
		panic(err)
	}
	h.outputWriter, err = os.Create(outputFile)
	if err != nil {
		panic(err)
	}
}

func (h *Helper) next() string {
	var c byte
	for c = h.scan(); c <= 32; c = h.scan() {
	}
	var sb strings.Builder
	for ; c > 32; c = h.scan() {
		sb.WriteByte(c)
	}
	return sb.String()
}

func (h *Helper) nextInt() int {
	var c byte
	var val int
	for c = h.scan(); c <= 32; c = h.scan() {
	}
	var neg bool
	if c == '-' || c == '+' {
		neg = c == '-'
		c = h.scan()
	}
	for ; c >= '0' && c <= '9'; c = h.scan() {
		val = (val << 3) + (val << 1) + int(c-'0')
	}
	if neg {
		return -val
	}
	return val
}

func (h *Helper) nextLong() int64 {
	var c byte
	var val int64
	for c = h.scan(); c <= 32; c = h.scan() {
	}
	var neg bool
	if c == '-' || c == '+' {
		neg = c == '-'
		c = h.scan()
	}
	for ; c >= '0' && c <= '9'; c = h.scan() {
		val = (val << 3) + (val << 1) + int64(c-'0')
	}
	if neg {
		return -val
	}
	return val
}

func (h *Helper) print(a interface{}) {
	fmt.Fprint(h.outputWriter, a)
}

func (h *Helper) printsp(a interface{}) {
	h.print(a)
	h.print(" ")
}

func (h *Helper) println() {
	fmt.Fprintln(h.outputWriter)
}

func (h *Helper) println(a interface{}) {
	h.print(a)
	h.println()
}

func (h *Helper) flush() {
	h.outputWriter.Flush()
}

func (h *Helper) scan() byte {
	if h.index >= h.total {
		h.index = 0
		h.total, _ = h.inputReader.Read(h.buf)
		if h.total <= 0 {
			return -1
		}
	}
	c := h.buf[h.index]
	h.index++
	return c
}

func main() {
	hp := NewHelper(1000000007, 1000006)
	solver := Solver{
		hp:    *hp,
		MAXN:  1000006,
		MOD:   1000000007,
		timer: time.NewTimer(time.Second),
		task:  time.NewTimer(time.Second),
	}
	hp.initIO(os.Stdin, os.Stdout)
	go func() {
		<-solver.timer.C
		hp.flush()
		os.Exit(0)
	}()
	solver.solve()
	hp.flush()
	os.Exit(0)
}

// End of Code
