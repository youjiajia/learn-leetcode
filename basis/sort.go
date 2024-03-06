package main

import (
	"errors"
	"fmt"
)

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

type Heap struct{
	l []int
}

func (h *Heap) exchange(i int){
	minIndex := i
	if i*2+1 < len(h.l) && h.l[i*2+1] < h.l[minIndex]{
		minIndex = i*2+1
	}
	if i*2+2 < len(h.l) && h.l[i*2+2] < h.l[minIndex]{
		minIndex = i*2+2
	}
	if minIndex != i{
		tmp := h.l[i]
		h.l[i] = h.l[minIndex]
		h.l[minIndex] = tmp
		h.exchange(minIndex)
	}
}

// 初始时把要排序的n个数的序列看作是一棵顺序存储的二叉树（一维数组存储二叉树），调整它们的存储序，使之成为一个堆，将堆顶元素输出，得到n 个元素中最小(或最大)的元素，这时堆的根节点的数最小（或者最大）。然后对前面(n-1)个元素重新调整使之成为堆，输出堆顶元素，得到n 个元素中次小(或次大)的元素。依此类推，直到只有两个节点的堆，并对它们作交换，最后得到有n个节点的有序序列。称这个过程为堆排序。算法复杂度是不稳定的nlogn

// 因此，实现堆排序需解决两个问题：
// 1. 如何将n 个待排序的数建成堆；从n/2个节点开始，依次构建堆
// 2. 输出堆顶元素后，怎样调整剩余n-1 个元素，使其成为一个新堆：把堆顶元素和最后一个元素交换，然后对堆顶构建堆
func NewHeap(l []int) *Heap {
	h := &Heap{l: l}
	h.l = l
	beginIndex := len(h.l) / 2 - 1
	for i:=beginIndex;i>=0;i--{
		h.exchange(i)
	}
	return h
}

func (h *Heap) Push(l []int){
	h.l = l
	beginIndex := len(h.l) / 2 - 1
	for i:=beginIndex;i>=0;{
		h.exchange(i)
		i = i / 2 -1
	}
}

func (h *Heap) Pop() (int, error){
	if len(h.l) == 0{
		return 0, errors.New("heap empty")
	}
	value := h.l[0]
	h.l[0] = h.l[len(h.l)-1]
	h.l = h.l[:len(h.l)-1]
	if len(h.l) > 0{
		h.exchange(0)
	}
	return value, nil
}

func HeapSort(l []int)[]int {
	heap := NewHeap(l)
	newl := []int{}
	for {
		v, err := heap.Pop()
		if err != nil{
			break
		}
		newl = append(newl, v)
	}
	return newl
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
	fmt.Println("==================")
	l = []int{1,3,5,9,4,2,7,3}
	fmt.Printf("heap sort: %v\n", HeapSort(l))
	fmt.Printf("heap sort: %v\n", HeapSort([]int{}))
	fmt.Printf("heap sort: %v\n", HeapSort([]int{1}))
	fmt.Printf("heap sort: %v\n", HeapSort([]int{2,1}))
}
