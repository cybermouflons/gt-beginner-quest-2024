# ticket-check
> category: pwn; difficulty: easy; author: k4rt0fl3r
## Solution
The player ideally should follow this train of thought:
- Read the provided source code `challenge.c`, identify the goal and the vulnerability.
    - **Goal.** Pass the `strcmp(ticketType, "goldenTicket!!!")` check as to execute the `flag()` function, which prints the flag.
    - **Vulnerability.** Usage of `gets()` function, which accepts user input without performing any checks on the input length.
- Exploiting the nature of the `gets()` function, we can give as an input an arbirtary long text. The first 8 characters will be stored in the `ticketNo` buffer and then the remaining characters will overflow (also called buffer overflow) on the stack.
- Due to the stack layout of the two buffers `ticketNo` and `ticketType` are placed in neighbouring memory addresses. If we provide input longer than 8 characters, the first 16 characters after the 8th character will overwrite the contents of `ticketType`.
- We can exploit the above behaviour as to overwrite `silverTicket!!!` with `goldenTicket!!!` and reach our goal.
    > Example input: AAAAAAAAgoldenTicket!!!
- After giving an appropriate input, like the example input aboce, the flag will be visible, wrapped in this format `GTBQ{}`.

_Note: In the solution folder, you can find a Python script that solves the challenge, utilizing the pwntools library._ 
