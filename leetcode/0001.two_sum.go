package main

import "fmt"
import "sort"

func two_func(nums []int, target int) []int {
    n := len(nums)

    var snums [][2]int
    for i, v := range nums {
        snums = append(snums, [2]int{v,i})
    }

    sort.Slice(snums, func(i, j int) bool {
        return snums[i][0] < snums[j][0]
    })

    l, r := 0, n-1
    for l < r {
        if snums[l][0] + snums[r][0] == target {
            return []int{snums[l][1], snums[r][1]}
        } else if snums[l][0] + snums[r][0] > target {
            r--
        } else {
            l++
        }
    }
    return nil
}

func _two_func(nums []int, target int) []int {
    hashtable := map[int]int{}
    for i, x := range nums {
        if p, ok := hashtable[target-x]; ok {
            return []int{p,i}
        }
        hashtable[x] = i
    }
    return nil
}

func __two_func(nums []int, target int) []int {
    for i, x := range nums {
        for j := i + 1; j < len(nums); j++ {
            if x + nums[j] == target {
                return []int{i,j}
            }
        }
    }
    return nil
}

func main() {
    var case1 []int = []int{2,7,11,15}
    res1 := two_func(case1, 9)
    fmt.Println(res1)
}
