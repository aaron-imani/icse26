package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		a, _ := strconv.Atoi(scanner.Text())
		if scanner.Scan() {
			b, _ := strconv.Atoi(scanner.Text())
			hb := b / 2
			fmt.Println(a + hb)
		}
	}
}
// End of Code
