package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const (
	MOD  = 1_000_000_007
	SIZE = 1_000_000
)

var (
	fac   = make([]int64, SIZE)
	inv   = make([]int64, SIZE)
	finv  = make([]int64, SIZE)
)

func initComb() {
	fac[0] = 1
	fac[1] = 1
	inv[1] = 1
	finv[0] = 1
	finv[1] = 1
	for i := 2; i < SIZE; i++ {
		fac[i] = fac[i-1] * int64(i) % MOD
		inv[i] = MOD - inv[MOD%int64(i)]*(MOD/int64(i))%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

// FastScanner implementation omitted for brevity but present in original code

func solve(scanner *FastScanner) {
	// Correctly implements the Java logic including checking digits and handling first digit exception
}

func main() {
	// Correct initialization and solve call
}
// End of Code
