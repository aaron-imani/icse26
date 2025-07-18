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

	conditions := make(map[int]int)
	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		fields := strings.Fields(line)
		s, _ := strconv.Atoi(fields[0])
		c, _ := strconv.Atoi(fields[1])
		if existing, ok := conditions[s]; ok && existing != c {
			fmt.Println(-1)
			return
		}
		conditions[s] = c
	}

	for i := 0; i < 1000; i++ {
		str := strconv.Itoa(i)
		if len(str) != n {
			continue
		}
		valid := true
		for j := 0; j < n; j++ {
			pos := j + 1
			digit := int(str[j] - '0')
			req, ok := conditions[pos]
			if ok {
				if digit != req {
					valid = false
					break
				}
			} else {
				if j == 0 && digit == 1 {
					continue // allowed
				}
				if digit != 0 {
					valid = false
					break
				}
			}
		}
		if valid {
			fmt.Println(str)
			return
		}
	}
	fmt.Println(-1)
}

// End of Code
