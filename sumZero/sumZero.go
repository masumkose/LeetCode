package main

import "fmt"

func sumZero(n int) []int {
	var nums = []int{}

	for n > 1 {
		nums = append(nums, n)
		nums = append(nums, n*-1)
		n -= 2
	}
	if n == 1 {
		nums = append(nums, 0)
	}
	return nums
}

func main() {
	fmt.Println(sumZero(5))
	fmt.Println(sumZero(6))
}
