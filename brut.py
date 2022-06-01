mod = 10**9 + 7
# global ct
def rec(data, s, id, ct):
    if id == len(data):
        if len(s)!=0:
            # print(s,end = ' ')
            if(int(s)%7 ==0):
                # print("acc")
                ct[0] += 1
            # else:
            #     print("rej")
        return
    rec(data, s + str(data[id]), id + 1, ct)
    rec(data, s, id + 1, ct)
def solve():
    n = int(input())
    ct = 0
    data = list(map(int, input().split()))
    s = ""
    ct = [0]
    rec(data, s, 0, ct)
    print(ct)

t = int(input())
while(t>0):
    t-=1
    solve()
