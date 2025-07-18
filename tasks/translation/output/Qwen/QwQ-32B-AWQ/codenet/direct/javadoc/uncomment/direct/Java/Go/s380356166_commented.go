package main

import (
	"fmt"
	"os"
	bufio
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")

	K, _ := strconv.Atoi(parts[0])
	S, _ := strconv.Atoi(parts[1])

	ans := 0
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			z := S - x - y
			if z >= 0 && z <= K {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

// End of Code
