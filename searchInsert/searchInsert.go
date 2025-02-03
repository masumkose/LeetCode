// Package main is the entry point for the Go application
package main

// import "fmt"

func searchInsert(nums []int, target int) int {
	i := 0
	for ; i < len(nums); i++ {
		if nums[i] == target {
			return (i)
		}
		if nums[i] > target {
			return i
		}
	}
	return i
}

func main() {

	nums := []int{1, 2, 3, 4, 5}
	println(searchInsert(nums, 5))

}
