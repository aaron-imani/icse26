package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	if sc.Scan() {
		a, _ := strconv.Atoi(sc.Text())
		if sc.Scan() {
			b, _ := strconv.Atoi(sc.Text())
			hb := b / 2
			fmt.Println(a + hb)
		}
	}
}
// End of Code
