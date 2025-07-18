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
	for i := 0; i < N; i++ {
		if max <= list[i] {
			max = list[i]
			output++
		}
	}
	fmt.Fprintln(writer, output)
}

func readLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return strings.TrimSpace(string(line))
}

func stringToIntArray(s, sep string) []int {
	strs := strings.Split(s, sep)
	result := make([]int, len(strs))
	for i, str := range strs {
		result[i], _ = strconv.Atoi(str)
	}
	return result
}
// End of Code
