//go 1.10.4

package main

import "fmt"

func mini(a int, b int) int {

  if a<b{

    return a

  }else {return b}

}

func main() {

  var x, y, w, h, val int

  fmt.Scanln(&x, &y, &w, &h)

  val = mini(mini(x, w-x),mini(y,h-y))

  

  fmt.Println(val)

}

