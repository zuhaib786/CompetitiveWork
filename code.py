import random
import sys
N = 10**5
r = 10**9
Q = 1
t = random.randint(1, 10)
print(t)
for _ in range(t):
    n = random.randint(1, 10)
    print(n)
    for _ in range(n):
        print(random.randint( 10**9, 2* (10**9)), end = ' ')
    print()
    q = random.randint(1, Q)
    print(q)
    for _ in range(q):
        l = random.randint(1, n)
        r = random.randint(1, n)
        # l = r
        x = random.randint(10**9, 2* (10**9))
        print(min(l, r), max(l, r), x)