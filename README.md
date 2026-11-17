# Comp211-Checkoff3-StackOverflow
Details, research, and coding examples for Comp 211 checkoff 3. Presentation is on stack buffer overflow.
Stack buffer overflow: A stack buffer overflow happens when your program writes more data into a fixed-size buffer on the call stack than the buffer can hold, so the extra data spills into whatever sits next to it in memory. 
Exploration: I explored what causes a stack overflow, methods to detect stack overflows, and real life examples where a stack overflow occurred in industry.
Interesting discoveries: Facts about stack overflows I found interesting were...
  1. when a stack overflow occurs, your program can either crash or continue running (incorrectly). Both outcomes have drastic impacts on the expected output of the program. If the overflow causes the program to crash, you will probably get errors and have to debug. If it runs incorrectly, you may not notice the overflow until you get a corrupted output.
  2. I also found it interesting that compilers use "canaries" to detect if a stack overflow occurred. Compilers place a secret “canary” value between the buffer and the return address, then check it before the function returns. Any overflow long enough to reach the return address has to pass through the canary first. Before returning, the function compares the canary to its original value. If it changed, the program aborts with
