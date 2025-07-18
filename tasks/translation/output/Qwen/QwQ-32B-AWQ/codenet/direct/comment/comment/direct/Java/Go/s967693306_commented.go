package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	required := make(map[int]int)
	conflict := false

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scan(&s, &c)
		if existing, ok := required[s]; ok {
			if existing != c {
				conflict = true
			}
		}
		required[s] = c
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
			pos := j + 1
			currentDigit := int(s[j] - '0')
			req, exists := required[pos]
			if exists {
				if currentDigit != req {
					valid = false
					break
				}
			} else {
				if j == 0 {
					if currentDigit != 1 {
						valid = false
						break
					}
				} else {
					if currentDigit != 0 {
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
