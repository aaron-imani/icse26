package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var a, b, c int
	if scanner.Scan() {
		a, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		b, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		c, _ = strconv.Atoi(scanner.Text())
	}
	if a < b && b < c && a < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
