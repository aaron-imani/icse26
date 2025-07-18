type Pair struct {
	L int
	R int
}

var a [2][]int
var n int
var memo [][][]int

func dp(flip int, idx int, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ans := 1000000000
	ff := 0
	for i := 0; i < n; i++ {
		if (msk&(1<<i)) == 0 {
			nf := x % 2
			if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
				newFlip := (nf + (ff%2)) % 2
				res := ff + dp(newFlip, i, msk|(1<<i))
				if res < ans {
					ans = res
				}
			}
			ff++
		} else {
			x--
		}
	}
	memo[flip][idx][msk] = ans
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	a[0] = make([]int, n)
	a[1] = make([]int, n)

	scanner.Scan()
	parts := strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		a[0][i], _ = strconv.Atoi(parts[i])
	}

	scanner.Scan()
	parts = strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		a[1][i], _ = strconv.Atoi(parts[i])
	}

	memo = make([][][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([][]int, n+1)
		for j := 0; j <= n; j++ {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}

	ans := dp(0, n, 0)
	if ans >= 1e9 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// End of Code
