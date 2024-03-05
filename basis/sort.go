package main

import "fmt"

// 将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。 时间复杂度稳定O（n^2）
func InsertSort(l []int) []int{
	for x:=1;x < len(l);x++{
		key := l[x]
		y := x - 1
		for y>=0 && l[y] > key{
			l[y+1] = l[y]
			y--
		}
		l[y+1] = key
	}
	return l

}

// 在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止 时间复杂度O（n^2）
func ChooseSort(l []int) []int{
	for x:=0;x<len(l)-1;x++{
		for y:=x+1;y<len(l);y++{
			if l[y] < l[x]{
				tmp := l[x]
				l[x] = l[y]
				l[y] = tmp
			}
		}
	}
	return l
}

func main(){
	l := []int{1,3,5,9,4,2,7,3}
	fmt.Printf("insert sort: %v\n", InsertSort(l))
	fmt.Printf("insert sort: %v\n", InsertSort([]int{}))
	fmt.Printf("insert sort: %v\n", InsertSort([]int{1}))
	fmt.Printf("insert sort: %v\n", InsertSort([]int{2,1}))
	fmt.Println("==================")
	l = []int{1,3,5,9,4,2,7,3}
	fmt.Printf("choose sort: %v\n", ChooseSort(l))
	fmt.Printf("choose sort: %v\n", ChooseSort([]int{}))
	fmt.Printf("choose sort: %v\n", ChooseSort([]int{1}))
	fmt.Printf("choose sort: %v\n", ChooseSort([]int{2,1}))
}
