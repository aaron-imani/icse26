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

func (s Solver) solve(testNumber int, in *bufio.Reader, out *bufio.Writer) {
	ans := 0
	line, _ := in.ReadString('\n')
	nums := strings.Fields(line)
	K, _ := strconv.Atoi(nums[0])
	S, _ := strconv.Atoi(nums[1])
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk := S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}

// End of Code
