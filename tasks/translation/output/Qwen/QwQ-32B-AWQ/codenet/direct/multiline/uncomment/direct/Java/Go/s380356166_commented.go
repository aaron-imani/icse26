package main

import (
	"fmt"
)

func main() {
	var K, S int
	fmt.Scanf("%d %d", &K, &S)
	var ans int
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			z := S - x - y
			if z >= 0 && z <= K {
				ans++
			}
		}
	}
	fmt.Println(ans)
}
// End of Code
