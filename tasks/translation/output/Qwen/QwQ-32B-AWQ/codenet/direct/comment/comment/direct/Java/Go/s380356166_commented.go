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
	scanner := bufio.NewScanner(reader)
	scanner.Scan()
	line := scanner.Text()
	fields := strings.Fields(line)
	K, _ := strconv.Atoi(fields[0])
	S, _ := strconv.Atoi(fields[1])

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
