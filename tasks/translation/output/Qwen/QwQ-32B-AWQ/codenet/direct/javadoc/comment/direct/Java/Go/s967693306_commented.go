package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	conditions := make(map[int]int)

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scan(&s, &c)
		if existing, ok := conditions[s]; ok {
			if existing != c {
				fmt.Println(-1)
				return
			}
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
			required, exists := conditions[pos]
			currentDigit := int(str[j] - '0')

			if exists {
				if currentDigit != required {
					valid = false
					break
				}
			} else {
				if currentDigit != 0 {
					if j == 0 && currentDigit == 1 {
						continue
					} else {
						valid = false
						break
					}
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
