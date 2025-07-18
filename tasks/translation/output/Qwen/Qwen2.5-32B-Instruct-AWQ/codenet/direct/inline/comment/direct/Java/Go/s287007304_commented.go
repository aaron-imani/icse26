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
	line, _ := reader.ReadString('\n')
	s := strings.Split(strings.TrimSpace(line), " ")
	a, _ := strconv.Atoi(s[0])
	b, _ := strconv.Atoi(s[1])

	if b%a == 0 {
		fmt.Println(a + b)
	} else {
		fmt.Println(b - a)
	}
}

// End of Code
