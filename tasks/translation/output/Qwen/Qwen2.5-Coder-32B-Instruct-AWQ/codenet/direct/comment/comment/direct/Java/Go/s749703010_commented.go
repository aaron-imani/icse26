package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Pair struct {
	l, r int
}

func (p Pair) String() string {
	return fmt.Sprintf("%d %d", p.l, p.r)
}

var memo [][][]int
var a [][]int
var n int

func dp(fliped, idx, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[fliped][idx][msk] != -1 {
		return memo[fliped][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ff := 0
	ans := 1e9
	for i := 0; i < n; i++ {
		if msk&(1<<i) == 0 {
			nf := x % 2
			if idx == n || a[fliped][idx] <= a[(nf+(ff%2))%2][i] {
				ans = min(ans, ff+dp((nf+(ff%2))%2, i, msk|1<<i))
			}
			ff++
		} else {
			x--
		}
	}
	memo[fliped][idx][msk] = ans
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := NewScanner(os.Stdin)
	n = sc.nextInt()
	a = make([][]int, 2)
	for i := range a {
		a[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		a[0][i] = sc.nextInt()
	}
	for i := 0; i < n; i++ {
		a[1][i] = sc.nextInt()
	}
	memo = make([][][]int, 2)
	for i := range memo {
		memo[i] = make([][]int, n+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}
	ans := dp(0, n, 0)
	if ans >= int(1e8) {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

type Scanner struct {
	r *bufio.Reader
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewReader(r)}
}

func (s *Scanner) next() string {
	var buf strings.Builder
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			break
		}
		if b > ' ' {
			buf.WriteByte(b)
		} else if buf.Len() > 0 {
			break
		}
	}
	return buf.String()
}

func (s *Scanner) nextInt() int {
	i, _ := strconv.Atoi(s.next())
	return i
}

func (s *Scanner) nextFloat64() float64 {
	f, _ := strconv.ParseFloat(s.next(), 64)
	return f
}

// End of Code
