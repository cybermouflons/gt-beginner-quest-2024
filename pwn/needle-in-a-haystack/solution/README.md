# needle-in-a-haystack
> category: pwn; difficulty: easy; author: k4rt0fl3r
## Solution
The player ideally should follow this train of thought:
- Run the executable using `./challenge` and see that we need to stop by and search a haystack
- Load executable in GDB using `gdb challenge`
- Investigate the functions of the file using `info functions`
- See that there is a function called `haystack`
- Set a breakpoint on the specific function using `b haystack`
- Run the executable within GDB using `r`
- Once the process breaks, execute one-by-one the instructions using `ni`
- Notice that there are many instructions from `0x401620` to `0x4016f8` that load data in the stack, starting from the address `$rsp+0x70` onwards.
- Once the process reaches the instruction at `0x4016f8` (after all of the loads), check the stack in GDB using `stack 20`
- The flag will be visible, wrapped in this format `GTBQ{}`.
