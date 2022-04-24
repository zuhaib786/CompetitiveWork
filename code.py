from posixpath import split


data =- list( map ( int, input().strip('][').split(',')))
assign = []
l = 0
for i in range(1,len(data)):
    if data[i] > data[i-1]:
        if(i == 0):
            l+=1
        elif data[i -1] > data[i- 2]:
            l += 1
        elif data[i-1] < data[i-2]:
            assign.append((l, - 1))
    elif data[i] < data[i-1]:
        if(i == 0):
            l+=1
        elif data[i -1] > data[i- 2]:
            l += 1
        elif data[i-1] < data[i-2]:
            assign.append((l, - 1))

