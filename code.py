import random
import sys
sys.setrecursionlimit(1000000)
n = random.randint(3, 5000)
print(1)
data =['(', ')']
for i in range(n):
    k = random.randint(1, 100)
    print(data[k%2 ] , end = '')
print()