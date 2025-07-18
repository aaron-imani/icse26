import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func readIntArray(size int) []int {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    parts := strings.Split(scanner.Text(), " ")
    arr := make([]int, size)
    for i := 0; i < size; i++ {
        num, _ := strconv.Atoi(parts[i])
        arr[i] = num
    }
    return arr
}

func readTwoInts() (int, int64) {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    parts := strings.Split(scanner.Text(), " ")
    a, _ := strconv.Atoi(parts[0])
    b, _ := strconv.ParseInt(parts[1], 10, 64)
    return a, b
}

func findPosition(N int, K int64, A []int) int {
    visited := make([]bool, N)
    curr := 0
    for !visited[curr] {
        visited[curr] = true
        curr = A[curr] - 1
    }

    // Build straight path
    st := 0
    straight := make([]int, 0)
    for st != curr {
        straight = append(straight, st)
        st = A[st] - [bank](https://leetcode.com/problems/destination-of-arrow/bank)
    }

    // Build cycle
    cycle := make([]int, 0)
    cycle = append(cycle, curr)
    curr = A[curr] - 1
    for curr != cycle[0] {
        cycle = append(cycle, curr)
        curr = A[curr] - 1
    }

    if K < int64(len(straight)) {
        return straight[int(K)] + 1
    }

    cycleLen := len(cycle)
    remainder := (K - int64(len(straight))) % int64(cycleLen)
    pos := int(remainder)
    return cycle[pos] + 1
}

func main() {
    N, K := readTwoInts()
    A := readIntArray(N)
    result := findPosition(N, K, A)
    fmt.Println(result)
}
// End of Code
