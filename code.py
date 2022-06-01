print(10)
import random
for i in range(10):
    n = random.randint(1, 5)
    print(n)
    for i in range(n):
        print(random.randint(1, 100), end =' ')
    print()
# mod = 10**9 + 7
# def solve():
#     n = int(input())
#     data = list(map(int, input().split()))
#     dp = [[0]*7 for _ in range(n)]
#     dp[0][data[0]%7] = 1
#     for i in range(1, n):
#         for j in range(7):
#             dp[i][j] = dp[i - 1][j]
#             dp[i][j] %= mod
#         dp[i][data[i]%7] +=1
#         for j in range(7):
#             md = (3* j + data[i])%7
#             dp[i][md] += dp[i - 1][j]
#             dp[i][md] %= mod
#     print(dp)
#     print(dp[n - 1][0])

# t = int(input())
# while(t>0):
#     t-=1
#     solve()
