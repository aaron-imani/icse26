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
	aStr, _, err := reader.ReadLine()
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	bStr, _, err := reader.ReadLine()
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	cStr, _, err := reader.ReadLine()
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	a, err := strconv.Atoi(strings.TrimSpace(string(aStr)))
	if err != nil {
		fmt.Println("Error converting input to integer:", err)
		return
	}
	b, err := strconv.Atoi(strings.TrimSpace(string(bStr)))
	if err != nil {
		fmt.Println("Error converting input to integer:", err)
		return
	}
	c, err := strconv.Atoi(strings.TrimSpace(string(cStr)))
	if err != nil {
		fmt.Println("Error converting input to integer:", err)
		return
	}

	if a < b && b < c && a < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
