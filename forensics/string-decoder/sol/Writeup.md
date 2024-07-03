# String Decoder

As per the description we are looking for `UTF-7/8/16/32 L/B Endian` strings in the `chal.dat` file.
The `strings` program with the argument `-e` can help up decode the strings based on encoding.

Along with the `Part: n` annotation we can hunt down the 4 parts of the flag as so:

```sh
#!/usr/bin/bash

strings chal.dat | rg "Part 1: GT"
strings -el chal.dat | rg "Part 2: "
strings -eL chal.dat | rg "Part 3: "
strings -eB chal.dat | rg "Part 4: "
```
