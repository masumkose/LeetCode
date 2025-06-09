package main

import (
	"fmt"
	"unicode"
)

func trimLeadingZeros(s string) string {
	i := 0
	for i < len(s)-1 && s[i] == '0' {
		i++
	}
	return s[i:]
}

func numDifferentIntegers(word string) int {
	set := make(map[string]struct{})
	numStr := ""
	for _, ch := range word {
		if unicode.IsDigit(ch) {
			numStr += string(ch)
		} else {
			if numStr != "" {
				numStr = trimLeadingZeros(numStr)
				set[numStr] = struct{}{}
				numStr = ""
			}
		}
	}
	if numStr != "" {
		numStr = trimLeadingZeros(numStr)
		set[numStr] = struct{}{}
	}
	fmt.Println(set)
	return len(set)
}

func main() {
	fmt.Println(numDifferentIntegers("123adsf123sdf5d1"))
}
