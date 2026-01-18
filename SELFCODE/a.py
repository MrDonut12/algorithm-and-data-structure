n, t = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

res, minS = -1e18, 1e18;
for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):

            sum = abs((arr[i] + arr[j] + arr[k]) - 3*t)
            print(f"{arr[i]} + {arr[j]} + {arr[k]} + {sum}")
            if (sum <= minS):
                minS = sum
                res = max(arr[i] + arr[j] + arr[k], res)
print(res)
