package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func nextLine() string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func nextInt() int {
	line := nextLine()
	num, _ := strconv.Atoi(line)
	return num
}

func nextIntArray() []int {
	line := nextLine()
	strs := strings.Split(line, " ")
	ints := make([]int, len(strs))
	for i, str := range strs {
		ints[i], _ = strconv.Atoi(str)
	}
	return ints
}

func main() {
	N := nextInt()
	list := nextIntArray()
	max := 0
	output := 0
	for _, num := range list {
		if max <= num {
			max = num
			output++
		}
	}
	fmt.Println(output)
}

// End of Code
