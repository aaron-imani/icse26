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
	fmt.Print("Enter two integers separated by space: ")
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")

	if len(parts) != 2 {
		fmt.Println("Error: Please enter exactly two integers separated by a space.")
		return
	}

	a, err := strconv.Atoi(parts[0])
	if err != nil {
		fmt.Println("Error: First input is not a valid integer.")
		return
	}

	b, err := strconv.Atoi(parts[1])
	if err != nil {
		fmt.Println("Error: Second input is not a valid integer.")
		return
	}

	if a%2 == 0 || b%2 == 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}
// End of Code
