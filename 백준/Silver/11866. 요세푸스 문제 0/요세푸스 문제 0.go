package main

import "fmt"

func main() {
	var N, K int

	fmt.Scan(&N, &K)
	queue := make([]int, N)
	var res []int

	for i := 0; i < N; i++ {
		queue[i] = i + 1
	}

	var idx int = 0

	for len(queue) > 0 {
		idx += K - 1

		if idx >= len(queue) {
			idx %= len(queue)
		}
		res = append(res, queue[idx])
		queue = append(queue[:idx], queue[idx+1:]...)
	}

	fmt.Print("<")
	for i := 0; i < len(res); i++ {
		fmt.Print(res[i])

		if i == len(res)-1 {
			fmt.Println(">")
		} else {
			fmt.Print(", ")
		}
	}
}
