package main

import (
	"fmt"
)

func getDigit2(x int64) int {
	d := 0
	for (1 << d) <= x {
		d++
	}
	return d
}

func powMod(base, exponent, mod int64) int64 {
	if base == 0 {
		return 0
	}
	if exponent == 0 {
		return 1 % mod
	}
	if exponent == 2 {
		return (base * base) % mod
	}

	d := getDigit2(exponent)
	pow := make([]int64, d)
	pow[0] = base
	for i := 1; i < d; i++ {
		pow[i] = (pow[i-1] * pow[i-1]) % mod
	}

	ans := int64(1)
	for i := d - 1; i >= 0; i-- {
		if exponent >= (1 << i) {
			exponent -= (1 << i)
			ans = (ans * pow[i]) % mod
		}
	}
	return ans % mod
}

func countFlaged(bit int64) int {
	cnt := 0
	for bit != 0 {
		if bit&1 != 0 {
			cnt++
		}
		bit >>= 1
	}
	return cnt
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)

	pop1st := 0
	for _, c := range s {
		if c == '1' {
			pop1st++
		}
	}

	mod1 := pop1st + 1
	surp1 := int64(0)
	for i := 0; i < n; i++ {
		surp1 *= 2
		if s[i] == '1' {
			surp1 += 1
		}
		surp1 %= int64(mod1)
	}

	var surp9 int64 = 0
	mod9 := int64(0)
	if pop1st > 1 {
		mod9 = int64(pop1st - 1)
		surp9 = 0
		for i := 0; i < n; i++ {
			surp9 *= 2
			if s[i] == '1' {
				surp9 += 1
			}
			surp9 %= mod9
		}
	}

	for p := 0; p < n; p++ {
		if s[p] == '1' {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			mod := mod9
			dw := surp9
			exponent := n - p - 1
			dif := powMod(2, int64(exponent), mod)
			dw = (dw - dif) % mod
			if dw < 0 {
				dw += mod
			}
			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				if cnt == 0 {
					panic("cnt is zero")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := int64(mod1)
			dw := surp1
			exponent := n - p - 1
			dif := powMod(2, int64(exponent), mod)
			dw = (dw + dif) % mod
			ans := 1
			for dw != 0 {
				cnt := countFlaged(dw)
				if cnt == 0 {
					panic("cnt is zero")
				}
				dw %= cnt
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
