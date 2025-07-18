package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	N, err := strconv.Atoi(sc.Text())
	if err != nil {
		fmt.Println("Error reading N:", err)
		return
	}
	sc.Scan()
	max, err := strconv.Atoi(sc.Text())
	if err != nil {
		fmt.Println("Error reading max:", err)
		return
	}
	min := max

	for i := 1; i < N; i++ {
		sc.Scan()
		in, err := strconv.Atoi(sc.Text())
		if err != nil {
			fmt.Println("Error reading input:", err)
			return
		}
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
