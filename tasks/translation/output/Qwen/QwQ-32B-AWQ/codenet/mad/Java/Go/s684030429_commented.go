package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

var max = 0
var cur = 0

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	solve(sc)
}

func solve(sc *bufio.Scanner) {
	a := ReadInt(sc)
	b := ReadInt(sc)
	diff := a - 2*b
	if diff < 0 {
		diff = 0
	}
	fmt.Println(diff)
	/* Uncomment the following code to handle the roads problem
	n := ReadInt(sc)
	m := ReadInt(sc)
	s := make([]int, n)
	ReadIntArray(s, sc)

	roads := make([][]int, n)
	for i := range roads {
		roads[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		p := ReadInt(sc)
		q := ReadInt(sc)
		p--
		q--
		roads[p][q] = 1
		roads[q][p] = 1
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", roads[i][j])
		}
		fmt.Println()
	}
	start := ReadInt(sc) - 1

	findRoads(roads[start], roads, start, s)
	fmt.Println(max)
	*/
}

func ReadInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return n
}

func ReadLong(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, err := strconv.ParseInt(sc.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return n
}

func ReadFloat(sc *bufio.Scanner) float32 {
	sc.Scan()
	n, err := strconv.ParseFloat(sc.Text(), 32)
	if err != nil {
		panic(err)
	}
	return float32(n)
}

func ReadDouble(sc *bufio.Scanner) float64 {
	sc.Scan()
	n, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}
	return n
}

func ReadString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func ReadIntArray(a []int, sc *bufio.Scanner) {
	for i := range a {
		a[i] = ReadInt(sc)
	}
}

func ReadLongArray(a []int64, sc *bufio.Scanner) {
	for i := range a {
		a[i] = ReadLong(sc)
	}
}

func ReadFloatArray(a []float32, sc *bufio.Scanner) {
	for i := range a {
		a[i] = ReadFloat(sc)
	}
}

func ReadDoubleArray(a []float64, sc *bufio.Scanner) {
	for i := range a {
		a[i] = ReadDouble(sc)
	}
}

func ReadStringArray(a []string, empty bool, sc *bufio.Scanner) {
	if empty {
		for i := range a {
			a[i] = ""
		}
	} else {
		for i := range a {
			a[i] = ReadString(sc)
		}
	}
}

func Read2DIntArray(a [][]int, sc *bufio.Scanner) {
	for i := range a {
		for j := range a[i] {
			a[i][j] = ReadInt(sc)
		}
	}
}

func imin(a []int) int {
	min := math.MaxInt
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func imax(a []int) int {
	max := math.MinInt
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func lmin(a []int64) int64 {
	min := math.MaxInt64
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func lmax(a []int64) int64 {
	max := math.MinInt64
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func ibs(a []int, toFind int) bool {
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

func lbs(a []int64, toFind int64) bool {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
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

func stb(s string) int {
	sum := 0
	k := 0
	for i := len(s)-1; i >=0; i-- {
		digit, _ := strconv.Atoi(string(s[i]))
		sum += digit * int(math.Pow(2, float64(k)))
		k++
	}
	return sum
}

func findRoads(a []int, roads [][]int, j int, s []int) {
	for i := range a {
		if a[i] == 1 {
			fmt.Println(i)
			roads[i][j] = 0
			roads[j][i] = 0
			cur += s[j]
			temp := s[j]
			s[j] = 0
			findRoads(roads[i], roads, i, s)
			if cur > max {
				max = cur
			}
			cur -= s[j]
			roads[i][j] = 1
			roads[j][i] = 1
			s[j] = temp
		}
	}
}
// End of Code
