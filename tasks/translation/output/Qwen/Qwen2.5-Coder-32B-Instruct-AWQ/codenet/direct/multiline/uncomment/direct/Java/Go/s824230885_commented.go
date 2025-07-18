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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	CONVSTR := map[int]string{8: " ", 9: "\n", 0: ""}
	N, _ := strconv.Atoi(readLine(reader))
	list := stringToIntArray(readLine(reader), CONVSTR[8])
	max := 0
	output := 0
	for _, num := range list {
		if max <= num {
			max = num
			output++
		}
	}
	fmt.Fprintln(writer, output)
}

func readLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return strings.TrimSpace(string(line))
}

func stringToIntArray(s string, delimiter string) []int {
	parts := strings.Split(s, delimiter)
	result := make([]int, len(parts))
	for i, part := range parts {
		result[i], _ = strconv.Atoi(part)
	}
	return result
}

// End of Code
