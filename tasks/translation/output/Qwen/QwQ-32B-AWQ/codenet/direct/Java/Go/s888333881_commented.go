package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	nStr := scanner.Text()
	n, _ := strconv.Atoi(nStr)

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
			surp1++
		}
		surp1 %= mod1
	}

	var surp9 int64 = 0
	mod9 := int64(pop1st - 1)
	if pop1st > 1 {
		for i := 0; i < n; i++ {
			surp9 = (surp9 * 2)
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
			mod := mod9
			dw := surp9
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw -= dif
			dw += mod
			dw %= mod
			ans := 1
			for dw != 0 {
				cnt := bits.OnesCount64(uint64(dw))
				if cnt == 0 {
					panic("invalid count")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := mod1
			dw := surp1
			exponent := int64(n - p - 1)
			dif := powMod(2, exponent, mod)
			dw += dif
			dw %= mod
			ans := 1
			for dw != 0 {
				cnt := bits.OnesCount64(uint64(dw))
				if cnt == 0 {
					panic("invalid count")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		}
	}
}

func powMod(base, exponent, mod int64) int64 {
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

// End of Code
