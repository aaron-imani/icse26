package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &Scanner{sc}
}

func (s *Scanner) Int() int {
	s.sc.Scan()
	n, _ := strconv.Atoi(s.sc.Text())
	return n
}

func (s *Scanner) Int64() int64 {
	s.sc.Scan()
	n, _ := strconv.ParseInt(s.sc.Text(), 10, 64)
	return n
}

func solve(r *Scanner, w *bufio.Writer) {
	N := r.Int()
	K := r.Int64()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = r.Int() - 1 // convert to 痦
	}

	// 找到循环开始的位置
	visited := make([]bool, N)
	curr := 0
	for !visited[curr] {
		visited[curr] = true
		curr = A[curr]
	}

	// 构建直链
	var straight []int
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st]
	}

	// 构建循环
	var cycle []int
	cycle = append(cycle, curr)
	curr = A[curr]
	for curr != cycle[0] {
		cycle = append(cycle, curr)
		curr = A[curr]
	}

	// 确定结果
	if K < int64(len(straight)) {
		fmt.Fprintf(w, "%d\n", straight[int(K)]+1)
	} else {
		remaining := K - int64(len(straight))
		mod := remaining % int64(len(cycle))
		fmt.Fprintf(w, "%d\n", cycle[mod]+1)
	}
}

func main() {
	const TESTCASES = false // 设置为 true 如果需要处理多个测试用例
	r := NewScanner(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var tc int
	if TESTCASES {
		tc = r.Int()
	} else {
		tc = 1
	}
	for i := 0; i < tc; i++ {
		solve(r, w)
	}
}

// End of Code
