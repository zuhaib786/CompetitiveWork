import random
print(10)
for _ in range(10):
    n = random.randint(2, 100)
    data = [i + 1 for i in range(n)]
    for _ in range(20):
        idx1 = random.randint(0, n - 2)
        idx2 = random.randint(0, n - 2)
        data[idx1] = random.randint(min(data[idx1], data[idx2]), max(data[idx1], data[idx2]))
    data.sort()
    # random.shuffle(data)
    # print(1)
    print(n)
    mx = -1
    
    for i in data:
        print(i,end = ' ')
    print()