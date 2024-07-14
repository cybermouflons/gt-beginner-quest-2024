 casual-conversation


**Category**: reverse

**Author**: christoss

## Description

GNU makes a pretty good debugger. Go ahead use that to find my secure message.

## Solution

The description prompts the user to look into the GNU debugger, or GDB. This is a tool that can be used to dynamically debug software. Read memory, modify memory, follow the execution of the code and a lot more.

Running the program, it appears that the flag is placed at address `0x13370000` and then after 5 seconds removed. GDB can be used to stop the execution of the program at the right point to read the memory and retrieve the flag.

1. Run the program in gdb. `gdb ./casual-conversation`
2. GDB is a command line based debugger. The command `run` can be used to start the program.
3. When the program is running wait until the flag is placed at the memory address, and press `Control+c` to stop the execution of the program
4. Finally read the flag from the address indicated by using the examine command (`x`) to read a string (`s`) at address 0x13370000. `x/s 0x13370000`
