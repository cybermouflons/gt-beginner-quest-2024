import random
import os


def inject(data, inj, where):
    return data[:where] + inj + data[where + len(inj) :]


fname = "./TFOTR.txt"
f_size = os.path.getsize(fname)

with open(fname, "rb") as f:
    data = f.read()


ofs = random.sample(range(0, f_size), 4)

for i, of in enumerate(ofs):
    print(f"Offset {i}: {hex(of)}")

flag_1 = "Part 1: GTBQ{3nc0ded_fl4g_1n_4sc11_\n"
flag_2 = "Part 2: UTF16_l3_f0r_w1nd0ws_\n"
flag_3 = "Part 3: but_wh4t_0n_\n"
flag_4 = "Part 4: 34rth_1s_UTF32}\n"

out = inject(data, flag_1.encode("ascii"), ofs[0])
out = inject(out, flag_2.encode("utf_16_le"), ofs[1])
out = inject(out, flag_3.encode("utf_32_le"), ofs[2])
out = inject(out, flag_4.encode("utf_32_be"), ofs[3])

with open("chal.dat", "wb") as f:
    f.write(out)
