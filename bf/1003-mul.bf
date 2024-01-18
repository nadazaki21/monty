,>,
>++++++++[<------>-]         delete 48 from number
++++++++[<<------>>-]<<      delete 48 from number
[>[->+>+<<]>[-<+>]<<-]>>>    multiplication

[                            start loop
  >>>>++++++++++<<<<         create a bit with value 10

  [->+>>+>-[<-]<[<<[->>      divide number by 10
  >+<<<]>>>>+<<-<]<<]

  ++++++++[->++++++<]>       add 48 to remainder
  [-<+>]                     move remainder at num location
  >>>>[-<<<<+>>>>]           put quotient at new num location
  <[-]<<<                    reset bits
]                            end loop
<[.<]                        print number backwards
++++++++++.                  print new line