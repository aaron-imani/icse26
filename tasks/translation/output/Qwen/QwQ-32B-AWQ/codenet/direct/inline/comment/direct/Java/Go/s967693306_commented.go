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
	parts := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	constraints := make(map[int]int)
	conflict := false
	for i := 0; i < m; i++ {
		scanner.Scan()
		parts = strings.Fields(scanner.Text())
		s, _ := strconv.Atoi(parts[0])
		c, _ := strconv.Atoi(parts[1])

		existing, exists := constraints[s]
		if exists && existing != c {
			conflict = true
		}
		constraints[s] = c
	}

	if conflict {
		fmt.Println(-1)
		return
	}

	found := false
	var result string
	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		if len(s) != n {
			continue
		}

		valid := true
		for j := 0; j < n; j++ {
			pos := j + 1
			currentDigit := int(s[j] - '0')

			requiredDigit, exists := constraints[pos]
			if exists {
				if currentDigit != requiredDigit {
					valid = false
					break
				}
			} else {
				if j == 0 && currentDigit == 1 {
					continue
				}
				if currentDigit != 0 {
					valid = false
					break
				}
			}
		}

		if valid {
			result = s
			found = true
			break
		}
	}

	if found {
		fmt.Println(result)
	} else {
		fmt.Println(-1)
	}
}

// End of Code
