package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)


type Solver struct{}

func (s *Solver) solve(testNumber int, in *bufio.Reader, out *bufio.Writer) {
	ans := 0
	K, err := strconv.Atoi(readLine(in))
	if err != nil {
		fmt.Fprintf(out, "Error parsing K: %v\n", err)
		return
	}
	S, err := strconv.Atoi(readLine(in))
	if err != nil {
		fmt.Fprintf(out, "Error parsing S: %v\n", err)
		return
	}
	wk := 0
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk = S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

func readLine(r *bufio.Reader) string {
	line, _ := r.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	solver := &Solver{}
	solver.solve(1, reader, writer)
}

// End of Code
