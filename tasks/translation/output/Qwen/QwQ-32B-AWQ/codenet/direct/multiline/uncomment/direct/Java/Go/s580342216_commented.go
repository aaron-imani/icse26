package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) != 2 {
			continue
		}
		N, _ := strconv.Atoi(fields[0])
		K, _ := strconv.Atoi(fields[1])
		len := 0
		current := N
		for current > 0 {
			current /= K
			len++
		}
		fmt.Println(len)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}

// End of Code
