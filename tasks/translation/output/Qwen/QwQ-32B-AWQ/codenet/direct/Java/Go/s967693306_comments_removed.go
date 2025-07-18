package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

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

	posMap := make(map[int]int)

	for i := 0; i < m; i++ {
		var s, c int
		if !scanner.Scan() {
			fmt.Println(-1)
			return
		}
		s, _ = strconv.Atoi(scanner.Text())
		if !scanner.Scan() {
			fmt.Println(-1)
			return
		}
		c, _ = strconv.Atoi(scanner.Text())

		existing, ok := posMap[s]
		if ok && existing != c {
			fmt.Println(-1)
			return
		}
		posMap[s] = c
	}

	for i := 0; i < 1000; i++ {
		sStr := strconv.Itoa(i)
		if len(sStr) != n {
			continue
		}
		flag := true
		for j := 0; j < n; j++ {
			pos := j + 1
			digit := int(sStr[j] - '0')
			c, ok := posMap[pos]
			if ok {
				if digit != c {
					flag = false
					break
				}
			} else {
				if digit !=  krijg {
					if !(j == 0 && digit == 1) {
						flag = false
						break
					}
				}
			}
		}
		if flag {
			fmt.Println(sStr)
			return
		}
	}

	fmt.Println(-1)
}

// End of Code
