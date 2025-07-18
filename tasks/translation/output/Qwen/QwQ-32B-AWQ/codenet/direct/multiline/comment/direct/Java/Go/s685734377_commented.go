import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i] = []byte(scanner.Text())
	}

	const P = 37
	const Q = 47
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0] = 1
	powQ[0] = 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	hashRow := make([][]int64, n)
	for i := 0; i < n; i++ {
		hashRow[i] = make([]int64, n)
	}
	hashCol := make([][]int64, n)
	for j := 0; j < n; j++ {
		hashCol[j] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				exponent := (j - k + n) % n
				hashRow[i][k] += int64(a[i][j]) * powP[exponent]

				exponent2 := (i - k + n) % n
				hashCol[j][k] += int64(a[i][j]) * powP[exponent2]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				rowShift := (i + A) % n
				colShift := (i + B) % n
				if hashRow[rowShift][B] != hashCol[colShift][A] {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}

	fmt.Println(ans)
}

// End of Code
