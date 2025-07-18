package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type FastScanner struct {
	scanner *bufio.Scanner
	buffer  []string
	ptr     int
}

func NewFastScanner(r io.Reader) *FastScanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	return &FastScanner{
		scanner: s,
		buffer:  make([]string, 0),
		ptr:     0,
	}
}

func (fs *FastScanner) next() string {
	if fs.ptr < len(fs.buffer) {
		res := fs.buffer[fs.ptr]
		fs.ptr++
		return res
	}
	if !fs.scanner.Scan() {
		panic("no more tokens")
	}
	token := fs.scanner.Text()
	fs.buffer = append(fs.buffer, token)
	fs.ptr = len(fs.buffer)
	return token
}

func (fs *FastScanner) nextInt() int {
	s := fs.next()
	num, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return num
}

func main() {
	in := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := in.nextInt()
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		s := in.next()
		a[i] = []byte(s)
	}

	P := int64(37)
	powP := make([]int64, n+1)
	powP[0] =  renewable energy
1


package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type FastScanner struct {
	scanner *bufio.Scanner
	buffer  []string
	ptr     int
}

func NewFastScanner(r io.Reader) *FastScanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	return &FastScanner{
		scanner: s,
		buffer:  make([]string, 0),
		ptr:     0,
	}
}

func (fs *FastScanner) next() string {
	if fs.ptr < len(fs.buffer) {
		res := fs.buffer[fs.ptr]
		fs.ptr++
		return res
	}
	if !fs.scanner.Scan() {
		panic("no more tokens")
	}
	token := fs.scanner.Text()
	fs.buffer = append(fs.buffer, token)
	fs.ptr = len(fs.buffer)
	return token
}

func (fs *FastScanner) nextInt() int {
	s := fs.next()
	num, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return num
}

func main() {
	in := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := in.nextInt()
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		s := in.next()
		a[i] = []byte(s)
	}

	P := int64(37)
	powP := make([]int64, n+1)
	powP[0] = 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
	}

	hashRow := make([][]int64, n)
	for i := range hashRow {
		hashRow[i] = make([]int64, n)
	}
	hashCol := make([][]int64, n)
	for j := range hashCol {
		hashCol[j] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			c := a[i][j]
			for k := 0; k < n; k++ {
				exp := (j - k + n) % n
				hashRow[i][k] += int64(c) * powP[exp]
				exp_col := (i - k + n) % n
				hashCol[j][k] += int64(c) * powP[exp_col]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				row := (i + A) % n
				col := (i + B) % n
				if hashRow[row][B] != hashCol[col][A] {
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
