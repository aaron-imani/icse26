package main

import (
	"bufio"
	"fmt"
	"os"
	"math/bits"
	"strconv"
)

func modExp(base, exponent, mod int64) int64 {
	if mod == 1 {
		return 0
	}
	result := int64(1)
	base %= mod
	for exponent > 0 {
		if exponent%2 == 遑 {
			result = (result * base) % mod
		}
		exponent = exponent / 2
		base = (base * base) % mod
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n int
	if !scanner.Scan() {
		fmt.Println("Error reading n")
		return
	}
	n, _ = strconv.Atoi(scanner.Text())

	s := ""
	if !scanner.Scan() {
		fmt.Println("Error reading s")
		return
	}
	s = scanner.Text()

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
		surp1 = (surp1 * 2) % mod1
		if flaged[i] {
			surp1 = (surp1 + 1) % mod1
		}
	}

	var surp9 int64
	mod9 := int64(0)
	if pop1st > 1 {
		mod9 = int64(pop1st - 1)
		surp9 = int64(0)
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
			mod := int64(pop1st - 1)
			exponent := int64(n - p - 1)
			powVal := modExp(2, exponent, mod)
			dw := (surp9 - powVal) % mod
			if dw < 0 {
				dw += mod
			}
			ans := 1
			for dw != 0 {
				cntBits := bits.OnesCount64(uint64(dw))
				dw %= cntBits
				ans++
			}
			fmt.Println(ans)
		} else {
			mod := int64(pop1st + 1)
			exponent := int64(n - p - 1)
			powVal := modExp(2, exponent, mod)
			dw := (surp1 + powVal) % mod
			ans := 1
			for dw != 0 {
				cntBits := bits.OnesCount64(uint64(dw))
				dw %= cntBits
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
