package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF  = 100000000
	INFL = 1000000000000000000
	E97  = 1000000007
)

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minN(ins ...int) int {
	min := ins[0]
	for _, v := range ins[1:] {
		if v < min {
			min = v
		}
	}
	return min
}

func maxN(ins ...int) int {
	max := ins[0]
	for _, v := range ins[1:] {
		if v > max {
			max = v
		}
	}
	return max
}

func pow(n, k int) int {
	ans := 1
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow2(in int) int {
	return in * in
}

func getDigit2(num int64) int {
	cf := int64(1)
	d := 0
	for num >= cf {
		d++
		cf = (1 << d)
	}
	return d
}

func isINF(in int) bool {
	if int64(in)*20 > INF {
		return true
	}
	return false
}

func pow10E97(ob, soeji, p int64) int64 {
	if ob == 0 {
		return 0
	}
	if soeji == 0 {
		return 1
	}
	if soeji == 2 {
		return (ob * ob) % p
	}
	d := getDigit2(soeji)
	opPow2Pow := make([]int64, d)
	opPow2Pow[0] = ob
	for i := 1; i < d; i++ {
		opPow2Pow[i] = (opPow2Pow[i-1] * opPow2Pow[i-1]) % p
	}
	ans := int64(1)
	for i := d - 1; i >= 0; i-- {
		if soeji >= (1 << i) {
			soeji -= (1 << i)
			ans = (ans * opPow2Pow[i]) % p
		}
	}
	return ans % p
}

func flag(pos int64) int64 {
	return (1 << pos)
}

func isFlaged(bit int, pos int) bool {
	if (bit&(1<<pos)) > 0 {
		return true
	}
	return false
}

func countFlaged(bit int64) int {
	ans := 0
	for i := 0; i < getDigit2(bit); i++ {
		if (bit&(1<<i)) > 0 {
			ans++
		}
	}
	return ans
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	s := sc.Text()
	flaged := make([]bool, n)
	for i := range flaged {
		flaged[i] = false
	}

	pop1st := int64(0)
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	surp1 := int64(0)
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1++
		}
		surp1 %= (pop1st + 1)
	}

	surp9 := int64(0)
	if pop1st > 1 {
		for i := 0; i < n; i++ {
			surp9 *= 2
			if flaged[i] {
				surp9++
			}
			surp9 %= (pop1st - 1)
		}
	}

	for p := 0; p < n; p++ {
		if flaged[p] {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			dw := surp9
			dif := pow10E97(2, n-p-1, pop1st-1)
			dw -= dif
			dw += (pop1st - 1)
			dw %= (pop1st - 1)
			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countFlaged(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			dif := pow10E97(2, n-p-1, pop1st+1)
			dw += dif
			dw %= (pop1st + 1)
			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countFlaged(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		}
	}
}

// End of Code
