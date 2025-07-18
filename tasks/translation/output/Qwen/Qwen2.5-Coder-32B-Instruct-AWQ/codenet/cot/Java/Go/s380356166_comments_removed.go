package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Pair struct {
	Key   interface{}
	Value interface{}
}

func (p *Pair) GetString() string {
	return fmt.Sprintf("[%v] [%v]", p.Key, p.Value)
}

type MyInput struct {
	in     *bufio.Reader
	buffer []byte
	pos    int
	readLen int
	str    []byte
	isDigit [256]bool
	isSpace [256]bool
	isLineSep [256]bool
}

func NewMyInput(is *os.File) *MyInput {
	input := &MyInput{
		in:     bufio.NewReader(is),
		buffer: make([]byte, 1024*8),
		str:    make([]byte, 500*8*2),
	}
	for i := 0; i < 10; i++ {
		input.isDigit['0'+byte(i)] = true
	}
	input.isDigit['-'] = true
	input.isSpace[' '] = true
	input.isSpace['\r'] = true
	input.isSpace['\n'] = true
	input.isSpace['\t'] = true
	input.isLineSep['\r'] = true
	input.isLineSep['\n'] = true
	return input
}

func (input *MyInput) read() byte {
	if input.pos >= input.readLen {
		input.pos = 0
		var err error
		input.readLen, err = input.in.Read(input.buffer)
		if err != nil {
			panic("End of file")
		}
		if input.readLen <= 0 {
			panic("End of file")
		}
	}
	input.pos++
	return input.buffer[input.pos-1]
}

func (input *MyInput) nextInt() int {
	len := 0
	input.str[len] = input.nextChar()
	len = input.reads(len, input.isSpace[:])
	i := 0
	ret := 0
	if input.str[0] == '-' {
		i = 1
	}
	for ; i < len; i++ {
		ret = ret*10 + int(input.str[i]-'0')
	}
	if input.str[0] == '-' {
		ret = -ret
	}
	return ret
}

func (input *MyInput) nextLong() int64 {
	len := 0
	input.str[len] = input.nextChar()
	len = input.reads(len, input.isSpace[:])
	i := 0
	ret := int64(0)
	if input.str[0] == '-' {
		i = 1
	}
	for ; i < len; i++ {
		ret = ret*10 + int64(input.str[i]-'0')
	}
	if input.str[0] == '-' {
		ret = -ret
	}
	return ret
}

func (input *MyInput) nextString() string {
	ret := string(input.nextDChar())
	return ret
}

func (input *MyInput) nextDChar() []byte {
	len := 0
	len = input.reads(len, input.isSpace[:])
	ret := make([]byte, len+1)
	for i := 0; i < len; i++ {
		ret[i] = input.str[i]
	}
	ret[len] = 0x00
	return ret
}

func (input *MyInput) nextChar() byte {
	for {
		c := input.read()
		if !input.isSpace[c] {
			return c
		}
	}
}

func (input *MyInput) reads(len int, accept []bool) int {
	for {
		c := input.read()
		if accept[c] {
			break
		}
		if len == len(input.str) {
			rep := make([]byte, len(input.str)*3/2)
			copy(rep, input.str)
			input.str = rep
		}
		input.str[len] = c
		len++
	}
	return len
}

type Solver struct{}

func (solver *Solver) solve(testNumber int, in *MyInput, out *os.File) {
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
	fmt.Fprintf(out, "%d\n", ans)
}

func main() {
	in := NewMyInput(os.Stdin)
	out := os.Stdout

	solver := &Solver{}
	solver.solve(1, in, out)
}
// End of Code
