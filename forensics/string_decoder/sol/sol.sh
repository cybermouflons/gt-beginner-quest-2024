#!/usr/bin/bash

strings chal.dat | rg "Part 1: GT"
strings -el chal.dat | rg "Part 2: "
strings -eL chal.dat | rg "Part 3: "
strings -eB chal.dat | rg "Part 4: "