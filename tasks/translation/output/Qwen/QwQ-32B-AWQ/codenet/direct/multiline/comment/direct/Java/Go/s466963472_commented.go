package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		d, err := strconv.Atoi(line)
		if err != nil {
			continue
		}
		ans := 0
		for i := 1; ; i++ {
			x := i * d
			if x >= 600 {
				break
			}
			ans += x * x * d
		}
		fmt.Println(ans)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}

// End of Code
