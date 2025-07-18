package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	pop1st := 0
	flaged := make([]bool, n)
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	mod1 := pop1st + 1
	surp1 := 0
	for i := 0; i < n; i++ {
		surp1 = (surp1 * 2) % mod1
		if flaged[i] {
			surp1 = (surp1 + 1) % mod1
		}
	}

	var surp9 int
	mod9 := pop1st - 1
	if pop1st > 1 {
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 = (surp9 * 2) % mod9
			if flaged[i] {
				surp9 = (surp9 + 1) % mod9
			}
		}
	}

	for p := 0; p < n; p++ {
		if flaged[p] {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			dw := surp9
			exponent := n - p - 1
			mod := mod9
			dif := powMod(2, exponent, mod)
			dw = (dw - dif) % mod
			ans := 1
			for dw != 0 {
				count := bits.OnesCount64(uint64(dw))
				dw %= count
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			exponent := n - p - 1
			mod := mod1
			dif := powMod(2, exponent, mod)
			dw = (dw + dif) % mod
			ans := 1
			for dw != 0 {
				count := bits.OnesCount64(uint64(dw))
				dw %= count
				ans++
			}
			fmt.Println(ans)
		}
	}
}

func powMod(base, exponent, mod int) int {
	result := 1
	baseMod := base % mod
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * baseMod) % mod
		}
		baseMod = (baseMod * baseMod) % mod
		exponent /= 2
	}
	return result
}

// End of Code
