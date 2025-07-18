package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod int64 = 1e9 + 7

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tmp := scanner.Text()
	s := []rune(tmp)
	n := len(s)
	ans := 0
	cnt := 0
	for i := 0; i < n; i++ {
		if s[i] == 'S' {
			cnt++
		} else {
			if cnt == 0 {
				continue
			}
			ans++
			cnt--
		}
	}
	fmt.Println(n - 2*ans)
}

func main() {
	solve()
}

// End of Code
