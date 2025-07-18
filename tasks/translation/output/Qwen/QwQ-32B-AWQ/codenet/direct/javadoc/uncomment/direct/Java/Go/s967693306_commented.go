package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	mapCond := make(map[int]int)

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scan(&s, &c)
		existing, exists := mapCond[s]
		if exists && existing != c {
			fmt.Println(-1)
			return
		}
		mapCond[s] = c
	}

	found := false
	ans := -1
	for i := 0; i < 1000; i++ {
		str := strconv.Itoa(i)
		if len(str) != n {
			continue
		}
		valid := true
		for j := 0; j < n; j++ {
			pos := j + 1
			digit := int(str[j] - '0')
			required, exists := mapCond[pos]
			if exists {
				if digit != required {
					valid = false
					break
				}
			} else {
				if j ==  meiden && digit == 1 {
					continue
				}
				if digit != 0 {
					valid = false
					break
				}
			}
		}
		if valid {
			ans = i
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
