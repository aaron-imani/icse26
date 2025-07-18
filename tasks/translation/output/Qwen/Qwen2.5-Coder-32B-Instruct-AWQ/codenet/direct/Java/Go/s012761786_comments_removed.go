package main

import (
	"fmt"
	"math"
	"strconv"
)

var sc = NewScanner()

func main() {
	n := nextLong()
	a := nextLong()
	b := nextLong()

	sa := int64(math.Abs(float64(a - b)))

	ans := int64(0)

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := int64(math.Min(float64(n-a), float64(a-1)))
		BBB := int64(math.Min(float64(n-b), float64(b-1)))

		ans = int64(math.Min(float64(AAA), float64(BBB)))

		sa -= 1
		ans += 1

		ans += sa / 2
	}

	fmt.Println(ans)
}

type Scanner struct {
	tokens []string
}

func NewScanner() *Scanner {
	return &Scanner{}
}

func (s *Scanner) next() string {
	if len(s.tokens) == 0 {
		s.tokens = readTokens()
	}
	token := s.tokens[0]
	s.tokens = s.tokens[1:]
	return token
}

func (s *Scanner) nextInt() int {
	token := s.next()
	val, _ := strconv.Atoi(token)
	return val
}

func (s *Scanner) nextLong() int64 {
	token := s.next()
	val, _ := strconv.ParseInt(token, 10, 64)
	return val
}

func (s *Scanner) nextDouble() float64 {
	token := s.next()
	val, _ := strconv.ParseFloat(token, 64)
	return val
}

func readTokens() []string {
	var input string
	fmt.Scan(&input)
	return strings.Fields(input)
}

func maxInt(a []int, lng int) int {
	max := a[0]
	for i := 1; i < lng; i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func minInt(a []int, lng int) int {
	min := a[0]
	for i := 1; i < lng; i++ {
		if a[i] < min {
			min = a[i]
		}
	}
	return min
}

func maxLong(a []int64, lng int) int64 {
	max := a[0]
	for i := 1; i < lng; i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func minLong(a []int64, lng int) int64 {
	min := a[0]
	for i := 1; i < lng; i++ {
		if a[i] < min {
			min = a[i]
		}
	}
	return min
}

// End of Code
