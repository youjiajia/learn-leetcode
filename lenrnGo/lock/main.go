package main

import (
	"fmt"
	"sync"
	"time"
)

type Queue struct{
	q []int
	cond *sync.Cond
}

func (q *Queue) put(i int){
	q.cond.L.Lock()
	defer q.cond.L.Unlock()
	q.q = append(q.q, i)
	q.cond.Broadcast()
}

func (q *Queue) get() int{
	q.cond.L.Lock()
	defer q.cond.L.Unlock()
	if len(q.q) == 0 {
		q.cond.Wait()
	}
	i := q.q[0]
	q.q = q.q[1:]
	return i
}

func main(){
	queue := Queue{q: []int{}, cond: sync.NewCond(&sync.Mutex{})}
	go func(){
		t := time.NewTicker(time.Second)
		for range t.C{
			queue.put(0)
		}
	}()
	t := time.NewTicker(100*time.Microsecond)
	for range t.C{
		i := queue.get()
		fmt.Println("get ", i)
	}
}
