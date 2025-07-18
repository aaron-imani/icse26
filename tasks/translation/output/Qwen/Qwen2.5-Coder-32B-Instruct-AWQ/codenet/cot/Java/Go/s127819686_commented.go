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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")

	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	hb := b / 2
	fmt.Println(a + hb)
}
// End of Code
