package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

type FastScanner struct {
	reader *bufio.Reader
}

func NewFastScanner(reader *bufio.Reader) *FastScanner {
	return &FastScanner{reader: reader}
}

func (fs *FastScanner) Close() {
	// Close the reader if necessary
}

func (fs *FastScanner) NextInt() int {
	nl := fs.NextLong()
	if nl < int64(^uint(0)>>1) || nl > int64(^uint(0)>>1) {
		panic("nextInt: value out of range")
	}
	return int(nl)
}

func (fs *FastScanner) NextLong() int64 {
	var sign int64 = 1
	var ret int64
	b, _ := fs.reader.ReadByte()
	for b < '0' || b > '9' {
		if b == '-' {
			sign = -1
		}
		b, _ = fs.reader.ReadByte()
	}
	ret = int64(b - '0')
	for {
		b, _ = fs.reader.ReadByte()
		if b < '0' || b > '9' {
			break
		}
		ret *= 10
		ret += int64(b - '0')
	}
	return ret * sign
}

func (fs *FastScanner) NextDouble() float64 {
	var sign float64 = 1
	var ret float64
	b, _ := fs.reader.ReadByte()
	for b < '0' || b > '9' {
		if b == '-' {
			sign = -1
		}
		b, _ = fs.reader.ReadByte()
	}
	ret = float64(b - '0')
	for {
		b, _ = fs.reader.ReadByte()
		if b < '0' || b > '9' {
			break
		}
		ret *= 10
		ret += float64(b - '0')
	}
	return ret * sign
}

func (fs *FastScanner) NextChar() byte {
	b, _ := fs.reader.ReadByte()
	for b == ' ' || b == '\t' || b == '\n' || b == '\r' {
		b, _ = fs.reader.ReadByte()
	}
	return b
}

func (fs *FastScanner) NextStr() string {
	var sb strings.Builder
	b, _ := fs.reader.ReadByte()
	for b == ' ' || b == '\t' || b == '\n' || b == '\r' {
		b, _ = fs.reader.ReadByte()
	}
	for b != ' ' && b != '\t' && b != '\n' && b != '\r' && b != -1 {
		sb.WriteByte(b)
		b, _ = fs.reader.ReadByte()
	}
	return sb.String()
}

func (fs *FastScanner) NextLine() string {
	var sb strings.Builder
	b, _ := fs.reader.ReadByte()
	for b != '\n' && b != -1 {
		sb.WriteByte(b)
		b, _ = fs.reader.ReadByte()
	}
	return sb.String()
}

func (fs *FastScanner) NextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = fs.NextInt()
	}
	return res
}

func solve(fs *FastScanner, w *bufio.Writer) {
	N := fs.NextInt()
	A := fs.NextIntArray(N)

	ans, sum := int64(0), int64(A[N-1])
	for i := N - 2; i >= 0; i-- {
		ans += (sum * int64(A[i])) % MOD
		ans %= MOD
		sum += int64(A[i])
		sum %= MOD
	}
	fmt.Fprintf(w, "%d\n", ans)
}

func main() {
	fs := NewFastScanner(bufio.NewReader(os.Stdin))
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()
	solve(fs, w)
}
// End of Code
