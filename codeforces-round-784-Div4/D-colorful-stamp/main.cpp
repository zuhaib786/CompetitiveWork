/* 
def check(s):
    if(len(s) == 0):
        return True
    # print(s)
    return not (s == 'B'*len(s) or s == 'R'*len(s))  
 
t = int(input())
while t>0:
    t-=1
    n = int(input())
    s = input().split()[0]
    
    data = s.split('W')
    # print(data)
    poss = True
    Di = {}
    for i in data:
        poss = (check(i) and poss)
    if poss:
        print("YES")
    else:
        print("NO")
*/