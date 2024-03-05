package main

import (
	"fmt"
	"reflect"
)
type test struct{
	Name string
}
func changeP(a *test, b string){
	fmt.Println(reflect.TypeOf(a))
	fmt.Println(reflect.TypeOf(*a))
}

func main() {
	p := test{Name: "asdf"}
	fmt.Println(p)
	fmt.Println(reflect.TypeOf(p))
	fmt.Println(reflect.TypeOf(&p))
	changeP(&p, "haha")
	fmt.Println(p)

    a := make([]int, 10)
	b := new([]int)
	a = append(a, 1)
	*b = append(*b, 1)
	fmt.Println(a)
	fmt.Println(b)

}

