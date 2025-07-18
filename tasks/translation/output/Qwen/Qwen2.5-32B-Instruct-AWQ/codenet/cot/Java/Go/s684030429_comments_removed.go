package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	a, _ := strconv.Atoi(sc.Text())
	return a
}

func solve() {
	a := nextInt()
	b := nextInt()

	fmt.Println(max(0, a-2*b))
}

func main() {
	sc.Split(bufio.ScanWords)
	solve()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func nextLong() int64 {
	sc.Scan()
	a, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return a
}

func nextFloat() float32 {
	sc.Scan()
	a, _ := strconv.ParseFloat(sc.Text(), 32)
	return float32(a)
}

func nextDouble() float64 {
	sc.Scan()
	a, _ := strconv.ParseFloat(sc.Text(), 64)
	return a
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextStringTokenizer(s string) []string {
	return strings.Split(s, " ")
}

func inputArrayInt(a []int) {
	for i := 0; i < len(a); i++ {
		a[i] = nextInt()
	}
}

func inputArrayLong(a []int64) {
	for i := 0; i < len(a); i++ {
		a[i] = nextLong()
	}
}

func inputArrayFloat(a []float32) {
	for i := 0; i < len(a); i++ {
		a[i] = nextFloat()
	}
}

func inputArrayDouble(a []float64) {
	for i := 0; i < len(a); i++ {
		a[i] = nextDouble()
	}
}

func inputArrayString(a []string, empty bool) {
	if empty {
		for i := 0; i < len(a); i++ {
			a[i] = ""
		}
	} else {
		for i := 0; i < len(a); i++ {
			a[i] = nextString()
		}
	}
}

func input2DArrayInt(a [][]int, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = nextInt()
		}
	}
}

func input2DArrayLong(a [][]int64, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = nextLong()
		}
	}
}

func input2DArrayDouble(a [][]float64, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = nextDouble()
		}
	}
}

func stringToInt(s string) int {
	a, _ := strconv.Atoi(s)
	return a
}

func stringToDouble(s string) float64 {
	a, _ := strconv.ParseFloat(s, 64)
	return a
}

func minLong(a []int64) int64 {
	min := int64(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if min > a[i] {
			min = a[i]
		}
	}
	return min
}

func minInt(a []int) int {
	min := int(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if min > a[i] {
			min = a[i]
		}
	}
	return min
}

func maxLong(a []int64) int64 {
	max := int64(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if max < a[i] {
			max = a[i]
		}
	}
	return max
}

func maxInt(a []int) int {
	max := int(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if max < a[i] {
			max = a[i]
		}
	}
	return max
}

func binarySearchInt(a []int, toFind int) bool {
	sort.Ints(a)
	min := 0
	max := len(a) - 1
	found := false

	for min <= max && !found {
		mid := min + (max-min)/2
		if a[mid] == toFind {
			found = true
		} else if toFind > a[mid] {
			min = mid + 1
		} else {
			max = mid - 1
		}
	}
	return found
}

func binarySearchLong(a []int64, toFind int64) bool {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	min := 0
	max := len(a) - 1
	found := false

	for min <= max && !found {
		mid := min + (max-min)/2
		if a[mid] == toFind {
			found = true
		} else if toFind > a[mid] {
			min = mid + 1
		} else {
			max = mid - 1
		}
	}
	return found
}

func stringToBinary(s string) int {
	sum := 0
	k := 0
	for i := len(s) - 1; i >= 0; i-- {
		sum += stringToInt(string(s[i])) * int(math.Pow(2, float64(k)))
		k++
	}
	return sum
}

// End of Code
