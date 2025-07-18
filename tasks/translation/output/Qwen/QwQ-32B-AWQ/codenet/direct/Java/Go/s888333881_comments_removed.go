package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math/bits"
)

func modExp(base, exponent, mod int64) int64 {
	result := int64(1)
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	flaged := make([]bool, n)
	pop1st := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	var surp1 int64 = 0
	mod1 := int64(pop1st + 1)
	for i := 0; i < n; i++ {
		surp1 = (surp1 * 2)
		if flaged[i] {
			surp1 += 1
		}
		surp1 %= mod1
	}

	var surp9 int64 = 0
	mod9 := int64(pop1st - 1)
	if pop1st > 1 {
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 = (surp9 * 2)
			if flaged[i] {
				surp9 += 1
			}
			surp9 %= mod9
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
			dif := modExp(2, int64(exponent), mod)
			dw = (dw - dif + mod) % mod
			ans := 1
			for dw != 0 {
				count := bits.OnesCount64(uint64(dw))
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			exponent := n - p - 1
			mod := mod1
			dif := modExp(2, int64(exponent), mod)
			dw = (dw + dif) % mod
			ans := 1
			for dw != 0 {
				count := bits.OnesCount64(uint64(dw))
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
