import os
import base64
from typing import Callable
import random
import string


flag = os.getenv("FLAG", "CTF{this_is_not_the_real_flag}")

rot13_table = str.maketrans("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                            "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM")

bin_operations: dict[str, Callable[[int, int], str]] = {
    "add": lambda x, y: str(x + y),
    "sub": lambda x, y: str(x - y),
    "mul": lambda x, y: str(x * y),
    "div": lambda x, y: str(x // y),
    "mod": lambda x, y: str(x % y),
}

un_operations: dict[str, Callable[[str], str]] = {
    "b64e": lambda x: base64.b64encode(x.encode()).decode(),
    "b64d": lambda x: base64.b64decode(x.encode()).decode(),
    "rot13": lambda x: x.translate(rot13_table),
}

all_operations = {**bin_operations, **un_operations}

NUM_ITERATIONS = 1000

if __name__ == "__main__":
    print("Welcome to the advanced calculator!")
    print("How fast can you do the calculations?")

    print()

    correct = True
    for it in range(1, NUM_ITERATIONS + 1):
        print(f"Round {it}:")

        ans = None

        operation = random.choice(list(all_operations.keys()))

        if operation in bin_operations:
            params = [random.randint(1, 1000) for _ in range(2)]
        else:
            params = [''.join(random.choices(string.ascii_letters +
                                             string.digits, k=30))]
        if operation == 'b64d':
            params = [base64.b64encode(params[0].encode()).decode()]
        ans = all_operations[operation](*params)

        user_ans = input(f"{operation}({', '.join(map(str, params))}) = ")

        if user_ans != str(ans):
            print("Sorry, that's incorrect.")
            print(f"The correct answer was {ans}.")
            print("Better luck next time!")
            correct = False
            break

    if correct:
        print(f"Congratulations! Here's your flag: {flag}")
