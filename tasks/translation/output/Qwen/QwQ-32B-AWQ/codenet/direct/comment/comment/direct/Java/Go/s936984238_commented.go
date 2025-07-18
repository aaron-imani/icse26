import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var numbers []int
	for sc.Scan() {
		txt := sc.Text()
		num, _ := strconv.Atoi(txt)
		numbers = append(numbers, num)
	}
	index := 0
	for {
		if index >= len(numbers) {
			break
		}
		count := numbers[index]
		index++
		if count == 0 {
			break
		}
		if index+count > len(numbers) {
			break
		}
		scores := append([]int{}, numbers[index:index+count]...)
		index += count
		sort.Ints(scores)
		sum := 0
		for i := 1; i < len(scores)-1; i++ {
			sum += scores[i]
		}
		fmt.Println(sum / (count - 2))
	}
}

// End of Code
