import random
import sys
sys.setrecursionlimit(1000000)
n = random.randint(3, 100000)
print(1)
print(n - 2)
data = [i for i in range(1, n + 1)]
random.shuffle(data)
temp = []
fp = open('output.txt', 'w')
s = str(data)
fp.write(s)
for i in range(2, len(data)):
    cnt = 0
    if(data[i - 2] > data[i - 1]):
        cnt+= 1
    if(data[i - 1] > data[i]):
        cnt += 1
    if(data[i - 2] > data[i]):
        cnt += 1
    print(cnt, end = ' ')
print()