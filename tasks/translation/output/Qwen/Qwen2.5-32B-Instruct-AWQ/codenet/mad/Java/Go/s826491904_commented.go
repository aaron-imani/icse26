package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())

	sc.Scan()
	max, _ := strconv.Atoi(sc.Text())
	min := max

	for i := 1; i < N; i++ {
		sc.Scan()
		in, _ := strconv.Atoi(sc.Text())
		if in > max {
			max = in
		}
		if in < min {
			min = in
		}
	}
	fmt.Println(max - min)
}

// End of Code
