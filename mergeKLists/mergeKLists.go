package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {

	ListNode newlist = lists[0]

	return (newlist)
}

func arrayToList(arr []int) *ListNode {
	if len(arr) == 0 {
		return nil
	}
	head := &ListNode{Val: arr[0]}
	current := head
	for _, val := range arr[1:] {
		current.Next = &ListNode{Val: val}
		current = current.Next
	}
	return head
}

func main() {
	// Arrays to be converted to linked lists.
	arrays := [][]int{
		{1, 4, 5},
		{1, 3, 4},
		{2, 6},
	}

	// Create a slice of linked lists.
	var lists []*ListNode
	for _, arr := range arrays {
		lists = append(lists, arrayToList(arr))
	}

	// Function to print the linked lists.
	printLists(lists)

	ListNode = mergeKLists(lists)

	printLists(lists)
}

// printLists prints the linked lists.
func printLists(lists []*ListNode) {
	for i, list := range lists {
		fmt.Printf("List %d: ", i+1)
		for list != nil {
			fmt.Printf("%d ", list.Val)
			list = list.Next
		}
		fmt.Println()
	}
}
