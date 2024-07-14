# Solution

1. Use the `ltrace` command to trace all library function call
2. If an arbitrary string is provded in place of the flag you will notice a debug screen that gets created using `sprintf` but not actually printed onto the screen.

```
strlen("GTBQ{test_flag}")                                                        = 16
sprintf("DEBUG: Invalid Input Length. 15 "..., "DEBUG: Invalid Input Length. %d "..., 15, 59) = 54
puts("That's not the flag! It's not ev"...That's not the flag! It's not even the right length!)   
```

3. The debug string looks to be cut short and looks to be indicating the length of the flag. Reading through the documentation of the command (`ltrace -h`) reveals the option `-s` which allows you to specify the maximum string length to print to the screen.

```
    -s STRSIZE          specify the maximum string size to print.
```

4. Using the flag shows the full string in `sprintf` telling us the flag is 59 characters long.

```
strlen("GTBQ{test_flag}")                                                         = 15
sprintf("DEBUG: Invalid Input Length. 15 provided, 59 expected.", "DEBUG: Invalid Input Length. %d provided, %d expected.", 15, 59) = 54
puts("That's not the flag! It's not even the right length!"That's not the flag! It's not even the right length!
)                      = 53
```

5. Providing a string, 59 characters long and rerunning the program with ltrace and the string size flag reveals the full flag, in the `strncmp` funciton call which checks the validity of our input.

```
➜  reverse/software-tracer/setup on  master [?] ltrace -s 100 ./software-tracer aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
.
.
.
strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")                           = 59
strncmp("GTBQ{ltr4c3_unv31l5_th3_h1dd3n_w4y5_1n_th3_50ftw4r3_m4z3!!}", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 59) = -26
puts("Wrong"Wrong
)                                                                                   = 6
+++ exited (status 1) +++
```

