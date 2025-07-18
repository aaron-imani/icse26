package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := Solver{}
	solver.solve(1, in, out)
}

type Solver struct{}

func (s *Solver) solve(testNumber int, in *bufio.Reader, out *bufio.Writer) {
	var K, S int
	fmt.Fscan(in, &K, &S)

	ans := 0
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			z := S - x - y
			if z >= 0 && z <= K {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}

type Pair struct {
	Key   interface{}
	Value interface{}
}

func (p *Pair) GetString() string {
	return fmt.Sprintf("[%v] [%v]", p.Key, p.Value)
}

func readInt(in *bufio.Reader) int {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	num, _ := strconv.Atoi(line)
	return num
}

func readString(in *bufio.Reader) string {
	line, _ := in.ReadString('\n')
	return strings.TrimSpace(line)
}

// End of Code
