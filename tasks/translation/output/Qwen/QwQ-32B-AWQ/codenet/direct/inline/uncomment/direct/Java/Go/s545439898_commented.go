import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var nums []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		token := scanner.Text()
		num, _ := strconv.Atoi(token)
		nums = append(nums, num)
	}
	if scanner.Err() != nil {
		panic(scanner.Err())
	}
	count := nums[0]
	for i := count; i >= 1; i-- {
		fmt.Print(nums[i])
		if i > 1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
// End of Code
