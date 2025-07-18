package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

func powMod(base, exponent, mod int64) int64 {
	if base == 0 {
		return 0
	}
	if exponent == 0 {
		return 1 % mod
	}
	result := int64(1)
	baseMod := base % mod
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * baseMod) % mod
		}
		baseMod = (baseMod * baseMod) % mod
		exponent = exponent / 2
	}
	return result % mod
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Fields(line)
	n, _ := strconv.Atoi(parts[0])
	s := parts[1]

	flaged := make([]bool, n)
	pop1st := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	var surp1 int64 = 0
	mod1 := pop1st + 1
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1++
		}
		surp1 %= mod1
	}

	var surp9 int64 = 0
	mod9 := int64(0)
	if pop1st > 1 {
		mod9 = int64(pop1st - 1)
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 *= 2
			if flaged[i] {
				surp9++
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
			mod := int64(pop1st - 1)
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw := (surp9 - dif + mod) % mod
			ans := 1
			for dw != 0 {
				count := bits.OnesCount64(uint64(dw))
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := int64(pop1st + 1)
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw := (surp1 + dif) % mod
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
