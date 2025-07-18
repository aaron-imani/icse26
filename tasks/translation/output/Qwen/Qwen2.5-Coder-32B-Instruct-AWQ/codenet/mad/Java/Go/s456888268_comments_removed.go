package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	tmp := readString(in)
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
	fmt.Fprintf(out, "%d\n", n-2*ans)
}

func readString(in *bufio.Reader) string {
	var buf []byte
	for {
		l, isPrefix, err := in.ReadLine()
		if err != nil {
			break
		}
		buf = append(buf, l...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}
// End of Code
