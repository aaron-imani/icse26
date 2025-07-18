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
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	input = strings.TrimSpace(input)
	s := strings.Split(input, " ")
	if len(s) != 2 {
		fmt.Println("Invalid input: expected two integers")
		return
	}
	a, err1 := strconv.Atoi(s[0])
	b, err2 := strconv.Atoi(s[1])
	if err1 != nil || err2 != nil {
		fmt.Println("Error converting input to integers:", err1, err2)
		return
	}
	if b%a == 0 {
		fmt.Println(a + b)
	} else {
		fmt.Println(b - a)
	}
}

// End of Code
