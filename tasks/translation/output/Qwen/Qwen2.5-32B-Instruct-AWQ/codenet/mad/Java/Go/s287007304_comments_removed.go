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
	line, err := reader.ReadString('
')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	line = strings.TrimSpace(line)
	s := strings.Split(line, " ")

	if len(s) != 2 {
		fmt.Println("Invalid input: expected two integers")
		return
	}

	a, err := strconv.Atoi(s[0])
	if err != nil {
		fmt.Println("Error parsing first integer:", err)
		return
	}

	b, err := strconv.Atoi(s[1])
	if err != nil {
		fmt.Println("Error parsing second integer:", err)
		return
	}

	if b%a == 0 {
		fmt.Println(a + b)
	} else {
		fmt.Println(b - a)
	}
}

// End of Code
