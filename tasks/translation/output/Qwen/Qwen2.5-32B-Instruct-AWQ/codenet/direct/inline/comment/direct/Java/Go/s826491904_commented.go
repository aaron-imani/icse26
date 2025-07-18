package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readLine(reader))
	max, min, _ := strconv.Atoi(readLine(reader))
	for i := 1; i < N; i++ {
		num, _ := strconv.Atoi(readLine(reader))
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	fmt.Println(max - min)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// End of Code
