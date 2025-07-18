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
	var t int
	if !scanner.Scan() {
		fmt.Fprintln(os.Stderr, "No input for t")
		return
	}
	tStr := scanner.Text()
	t, _ = strconv.Atoi(tStr)
	for t > 0 {
		t--
		if !scanner.Scan() {
			fmt.Fprintln(os.Stderr, "No n")
			return
		}
		nStr := scanner.Text()
		n, _ := strconv.ParseInt(nStr, 10, 64)
		if !scanner.Scan() {
			fmt.Fprintln(os.Stderr, "No m")
			return
		}
		mStr := scanner.Text()
		m, _ := strconv.ParseInt(mStr, 10, 64)
		if n == 0 {
			fmt.Println(0)
			continue
		}
		if n == m {
			fmt.Println(0)
			continue
		}
		rem := n % m
		ans := rem
		if (m-rem) < rem {
			ans = m - rem
		}
		fmt.Println(ans)
	}
}

// End of Code
