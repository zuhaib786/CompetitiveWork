fp = open("output.txt")
data1 = list(map(int, fp.readline().split()))
data2 = list(map(int, fp.readline().split()))
x1 = 0
x2 = 0
for i in range(len(data1)):
    x1 ^= data1[i]
    x2 ^= data2[i]
    if i%2 == 1:
        print(x1, x2)
