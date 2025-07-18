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
		N, _ := strconv.Atoi(fields[0])
		K, _ := strconv.Atoi(fields[1])
		len := 0
		n := N
		for n > 0 {
			n /= K
			len++
		}
		fmt.Println(len)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}
}
// End of Code
