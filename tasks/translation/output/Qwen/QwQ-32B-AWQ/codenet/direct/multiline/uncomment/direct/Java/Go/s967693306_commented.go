package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)

	constraints := make(map[int]int)

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scanf("%d %d", &s, &c)
		if existing, exists := constraints[s]; exists {
			if existing != c {
				fmt.Println(-1)
				return
			}
		}
		constraints[s] = c
	}

	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		if len(s) != n {
			continue
		}
		valid := true
		for j := 0; j < n; j++ {
			digit := int(s[j] - '0')
			pos := j + 1
			if val, ok := constraints[pos]; ok {
				if digit != val {
					valid = false
					break
				}
			} else {
				if j == 0 {
					if digit != 1 {
						valid = false
						break
					}
				} else {
					if digit != 0 {
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
