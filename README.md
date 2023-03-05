# brainfuck
Here is a brainfuck interpreter I made using c++ as small challenge since getting into using c++

About Brainfuck
Brainfuck is a Turing Complete esoteric programming language (esolang) designed by Urban Müller in 1993. As an esolang, it has little practical purpose in programming however is a good langauge to challenge programmers to think of their programs in different ways. Brainfuck has an infinitely long tape with cells that can hold values from 0 - 255 however in practice the tape will not be infinitely long and the tape used in this interpretor is 256 cells long. The language consists of 8 characters which are used to manipulate the tape.

The commands are + - < > , . [ ]

+ : Increments the cell that the pointer is currently at
- : Decrements the cell that the pointer is currently at
< : Shifts the pointer to the left by 1
> : Shifts the pointer to the right by 1
, : Get's a user input and stores it into the cell that the pointer is currently at
. : Outputs the value stored in the cell that the pointer is currently at
[ : Starts a while loop when the current cell is empty (0), loop what is between the brackets
] : End of the loop
