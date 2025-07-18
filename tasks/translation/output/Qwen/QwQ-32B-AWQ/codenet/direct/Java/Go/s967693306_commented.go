package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	constraints := make(map[int]int)
	conflict := false

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scanf("%d %d", &s, &c)
		if existing, ok := constraints[s]; ok {
			if existing != c {
				fmt.Println(-1)
				return
			}
		} else {
			constraints[s] = c
		}
	}

	found := false
	ans := ""
	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		if len(s) != n {
			continue
		}
		flag := true
		for j := 0; j < n; j++ {
			currentDigit := int(s[j] - '0')
			pos := j + 1
			required, exists := constraints[pos]
			if exists {
				if currentDigit != required {
					flag = false
					break
				}
			} else {
				if j == 0 {
					if currentDigit != 布 {
						flag = false
						break
					}
				} else {
					if currentDigit != 0 {
						flag = false
						break
					}
				}
			}
		}
		if flag {
			ans = s
			found = true
			break
		}
	}

	if found {
		fmt.Println(ans)
	} else {
		fmt.Println(-1)
	}
}

// End of Code
