package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var nums []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		nums = append(nums, num)
	}
	n := nums[0]
	arr := nums[1 : 1+n]
	cnt := 0
	for {
		allEven := true
		for _, v := range arr {
			if v%2 != 0 {
				allEven = false
				break
			}
		}
		if !allEven {
			break
		}
		for i := range arr {
			arr[i] /= 2
		}
		cnt++
	}
	fmt.Println(cnt)
}

// End of Code
