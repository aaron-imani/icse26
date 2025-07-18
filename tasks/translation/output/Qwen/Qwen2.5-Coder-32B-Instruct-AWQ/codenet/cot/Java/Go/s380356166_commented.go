package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewMyInput(inputStream)
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	solver := Solver{}
	solver.solve(1, in, out)
}

type Solver struct{}

func (s Solver) solve(testNumber int, in *MyInput, out *bufio.Writer) {
	ans := 0
	K := in.nextInt()
	S := in.nextInt()
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk := S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}

type Pair struct {
	Key   interface{}
	Value interface{}
}

func NewPair(key, value interface{}) *Pair {
	return &Pair{Key: key, Value: value}
}

func (p *Pair) GetString() string {
	return fmt.Sprintf("[%v] [%v]", p.Key, p.Value)
}

type MyInput struct {
	in     *bufio.Reader
	buffer []byte
	pos    int
	len    int
}

func NewMyInput(r *os.File) *MyInput {
	return &MyInput{in: bufio.NewReader(r), buffer: make([]byte, 1024*8)}
}

func (m *MyInput) read() byte {
	if m.pos >= m.len {
		m.pos = 0
		var err error
		m.len, err = m.in.Read(m.buffer)
		if err != nil {
			panic("End of file")
		}
		if m.len <= 0 {
			panic("End of file")
		}
	}
	m.pos++
	return m.buffer[m.pos-1]
}

func (m *MyInput) nextInt() int {
	var len int
	m.buffer[len] = m.read()
	len = m.reads(len, isSpace)
	i := 0
	ret := 0
	if m.buffer[0] == '-' {
		i = 1
	}
	for ; i < len; i++ {
		ret = ret*10 + int(m.buffer[i]-'0')
	}
	if m.buffer[0] == '-' {
		ret = -ret
	}
	return ret
}

func (m *MyInput) nextLong() int64 {
	var len int
	m.buffer[len] = m.read()
	len = m.reads(len, isSpace)
	i := 0
	ret := int64(0)
	if m.buffer[0] == '-' {
		i = 1
	}
	for ; i < len; i++ {
		ret = ret*10 + int64(m.buffer[i]-'0')
	}
	if m.buffer[0] == '-' {
		ret = -ret
	}
	return ret
}

func (m *MyInput) nextString() string {
	return strings.TrimSpace(string(m.nextDChar()))
}

func (m *MyInput) nextDChar() []byte {
	var len int
	len = m.reads(len, isSpace)
	ret := make([]byte, len+1)
	for i := 0; i < len; i++ {
		ret[i] = m.buffer[i]
	}
	ret[len] = 0x00
	return ret
}

func (m *MyInput) nextChar() byte {
	for {
		c := m.read()
		if !isSpace[c] {
			return c
		}
	}
}

func (m *MyInput) reads(len int, accept []bool) int {
	for {
		c := m.read()
		if accept[c] {
			break
		}
		if len == len(m.buffer) {
			newBuffer := make([]byte, len*3/2)
			copy(newBuffer, m.buffer)
			m.buffer = newBuffer
		}
		m.buffer[len] = c
		len++
	}
	return len
}

var isSpace = [256]bool{
	' ':  true,
	'\r': true,
	'\n': true,
	'\t': true,
}

// End of Code
