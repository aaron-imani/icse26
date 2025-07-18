package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
)

func powMod(base, exponent, mod int64) int64 {
	result := int64(1)
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exponent = exponent / 2
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	nInt := int64(n)
	flaged := make([]bool, n)
	pop1st := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	pop1stInt := int64(pop1st)
	var surp1, surp9 int64
	surp1 = 0
	modSurp1 := pop1stInt + 1
	for i := 0; i < n; i++ {
		add := 0
		if flaged[i] {
			add = 1
		}
		surp1 = (surp1*2 + int64(add)) % modSurp1
	}

	if pop1st > 1 {
		surp9 = 0
		modSurp9 := pop1stInt - 1
		for i := 0; i < n; i++ {
			add := 0
			if flaged[i] {
				add = 1
			}
			surp9 = (surp9*2 + int64(add)) % modSurp9
		}
	}

	for p := 0; p < n; p++ {
		if flaged[p] {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			mod := pop1stInt - 1
			dw := surp9
			exponent := int64(n-p-1)
			dif := powMod(2, exponent, mod)
			dw = (dw - dif) % mod
			if dw < 0 {
				dw += mod
			}
			ans := 1
			for dw != 0 {
				cnt := bits.OnesCount64(uint64(dw))
				if cnt == 0 {
					panic("unexpected")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := pop1stInt + 1
			dw := surp1
			exponent := int64(n-p-1)
			dif := powMod(2, exponent, mod)
			dw = (dw + dif) % mod
			ans := 1
			for dw != 0 {
				cnt := bits.OnesCount64(uint64(dw))
				if cnt == 0 {
					panic("unexpected")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
