package main

import (
	"context"
	"fmt"
	"time"
)

func case1(){
	ch := make(chan int)
	go func(){
		fmt.Println("child process 1")
		ch <- 1
	}()
	<-ch
}

func case2(){
	ch := make(chan int, 10)
	// producer
	go func(){
		for i := 0; i < 10; i++ {
			ch <- i
			time.Sleep(1 * time.Second)
		}
		close(ch)
	}()
	// customer
	for i := range ch {
		fmt.Println(i)
	}
}

func case3(){
	ch := make(chan int, 10)
	timeout := time.NewTimer(20 * time.Second)
	tracer := time.NewTicker(1 * time.Second)
	defer func(){
		close(ch)
		timeout.Stop()
		tracer.Stop()
	}()
	go func(){
		// 生产者
		for i:=0;i<10000;i++{
			ch <- i
			fmt.Printf("Push: %d\n", i);
			time.Sleep(1*time.Second)
		}
	}()
	// 消费者
	for range tracer.C{
		select {
			case v := <- ch:
				fmt.Printf("Received: %d\n", v);
			case <-timeout.C:
				fmt.Print("Close Customer\n");
				return
			default:
				fmt.Print("default\n");
		}
	}
}

func main(){
	ctx := context.Background()
	// ctx = context.WithValue(ctx, "a", "a")
	ch := make(chan int, 10)
	timeoutCtx, cancel := context.WithTimeout(ctx, 3*time.Second)
	defer cancel()
	for x:=1;x<=10;x++{
		go func(c context.Context, p int){
			// fmt.Println(c.Value("a"))
			// 生产者
			producerTracer := time.NewTicker(time.Second)
			for range producerTracer.C{
				fmt.Println("put ", p)
				ch <- p
				select{
					case <-c.Done():
						fmt.Println("producer done")
						return
					default:
				}
			}
		}(timeoutCtx, x)
	}
	// 消费者
	for c:=1;c<=10;c++{
		customerTracer := time.NewTicker(time.Second)
		for range customerTracer.C{
			select{
				case i:=<-ch:
					fmt.Println("get ", i)
				case <-timeoutCtx.Done():
					time.Sleep(3*time.Second)
					fmt.Println("customer done")
					return
			}
		}
	}
}
