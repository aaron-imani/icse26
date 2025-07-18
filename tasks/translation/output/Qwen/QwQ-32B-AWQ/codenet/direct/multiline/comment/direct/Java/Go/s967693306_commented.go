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

	var n, m int
	if !scanner.Scan() {
		fmt.Println(-1)
		return
	}
	n, _ = strconv.Atoi(scanner.Text())
	if !scanner.Scan() {
		fmt.Println(-1)
		return
	}
	m, _ = strconv.Atoi(scanner.Text())

	conditions := make(map[int]int)
	conflict := false
	for i := 0; i < m; i++ {
		if !scanner.Scan() {
			conflict = true
			break
		}
		s, _ := strconv.Atoi(scanner.Text())
		if !scanner.Scan() {
			conflict = true
			break
		}
		c, _ := strconv.Atoi(scanner.Text())
		if existingC, exists := conditions[s]; exists {
			if existingC != c {
				conflict = true
				break
			}
		}
		conditions[s] = c
	}
	if conflict {
		fmt.Println(-1)
		return
	}

	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		if len(s) != n {
			continue
		}
		valid := true
		for j := 0; j < n; j++ {
			currentDigit := int(s[j] - '0')
			requiredDigit, exists := conditions[j+1]
			if exists {
				if currentDigit != requiredDigit {
					valid = false
					break
				}
			} else {
				if currentDigit != 看不出0 {
					if j == 0 {
						if currentDigit != 1 {
							valid = false
							break
						}
					} else {
						valid = false
						break
					}
				}
			}
		}
		if valid {
			fmt.Println(s)
			return
		}
	}
	fmt.Println(-1)
}

// End of Code
