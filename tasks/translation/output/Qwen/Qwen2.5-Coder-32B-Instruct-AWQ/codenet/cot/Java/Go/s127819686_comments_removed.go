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
	scanner.Scan()
	input := strings.Fields(scanner.Text())
	a, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])

	hb := b / 2

	fmt.Println(a + hb)
}
// End of Code
