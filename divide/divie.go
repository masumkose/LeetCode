package main

import (
	"fmt"
	"math"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}


func divide(dividend int, divisor int) int {

	if divisor == 0 {
		panic("division by zero")
	}
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}
	sign := 1
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		sign = -1
	}
	dividend = abs(dividend)
	divisor = abs(divisor)

	quotient := 0
	for dividend >= divisor {
		tempdivisor, multiple := divisor, 1
		for dividend >= (tempdivisor << 1){
			tempdivisor <<= 1
			multiple <<= 1
		}
		dividend -= tempdivisor
		quotient += multiple
	}


	return sign * quotient;
}

func main() {
	fmt.Println(divide(10, 3))  // Output: 3
	fmt.Println(divide(7, -3))  // Output: -2
	fmt.Println(divide(0, 1))   // Output: 0
	fmt.Println(divide(-1, -1)) // Output: 1
}