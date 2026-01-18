n, t = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

arr.sort()
minS, res = 10**18, -10**18
for i in range(n - 2):
    l, r = i + 1, n - 1
    while l < r:
        s = arr[i] + arr[l] + arr[r]
        queA = abs(s - 3*t)

        if (queA <= minS):
            minS = queA
            res = max(res, s)

        if s - 3*t < 0:
            l += 1
        else:
           r -= 1

print(res)
