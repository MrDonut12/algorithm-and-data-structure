n, m = map(int, input().split(" "))
a = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))
dp = [0 for i in range(n)]
a.sort()
for i in range(m):
    l, r = 0, n - 1
    while  l <= r:
        g = (l + r)//2
        if (a[g] > b[i] or (a[g] == b[i] and dp[i] == 1)):
            l = g + 1
        elif (a[g] <= b[i]):
            r = g - 1

    if (a[r] <= b[i]):
        print(a[r])
        dp[r] = 1;
        n = n - 1
    else:
        print("-1")
