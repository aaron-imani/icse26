package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math/bits"
)

func powMod(base, exponent, mod int64) int64 {
	if base == 0 {
		return 0
	}
	result := int64(1)
	base %= mod
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exponent /= 2
	}
	return result
}

func countFlaged(num int64) int {
	return bits.OnesCount64(uint64(num))
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	scanner.Scan()
	s := scanner.Text()

	flaged := make([]bool, n)
	pop1st := int64(0)
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	var surp1, surp9 int64
	mod1 := pop1st + 1
	surp1 = 0
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1 += 1
		}
		surp1 %= mod1
	}

	if pop1st > 1 {
		mod9 := pop1st - 1
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 *= 2
			if flaged[i] {
				surp9 += 1
			}
			surp9 %= mod9
		}
	} else {
		surp9 = 0
	}

	for p := 0; p < n; p++ {
		if s[p] == '1' {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			mod := pop1st - 1
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw := surp9 - dif
			dw += mod
			dw %= mod
			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := pop1st + 1
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw := surp1 + dif
			dw %= mod
			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
