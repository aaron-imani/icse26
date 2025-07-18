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

	flaged := make([]bool, n)
	pop1st := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	mod1 := int64(pop1st + 1)
	surp1 := int64(0)
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1 += 1
		}
		surp1 %= mod1
	}

	var surp9 int64
	var mod9 int64
	if pop1st > 1 {
		mod9 = int64(pop1st - 1)
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 *= 2
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
			exp := int64(n - p - 1)
			mod := mod9
			dif := powMod(2, exp, mod)
			dw -= dif
			dw += mod
			dw %= mod

			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				if cnt == 0 {
					fmt.Println("Error: cnt is zero but dw is not")
					return
				}
				dw %= int64(cnt)
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			exp := int64(n - p - 1)
			mod := mod1
			dif := powMod(2, exp, mod)
			dw += dif
			dw %= mod

			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				if cnt == 0 {
					fmt.Println("Error: cnt is zero but dw is not")
					return
				}
				dw %= int64(cnt)
				ans++
			}
			fmt.Println(ans)
		}
	}
}

func powMod(base, exponent, mod int64) int64 {
	if mod == 1 {
		return 0
	}
	result := int64(1)
	base %= mod
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % mod
		}
		exponent /= 2
		base = (base * base) % mod
	}
	return result
}

func countFlaged(bit int64) int {
	return bits.OnesCount64(uint64(bit))
}
// End of Code
