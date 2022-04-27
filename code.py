import random
n = random.randint(1, 15)
print(n)
for i in range(n):
    sz = random.randint(1, 15)
    print(sz)
    for i in range(sz):
        print(random.randint(1, 30), end = ' ')
    print()
    k = random.randint(1, 20)
    print(k)
    