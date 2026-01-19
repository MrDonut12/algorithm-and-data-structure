n = int(input())
mp = {}
for _ in range(n):
    a, b = map(int, input().split(" "))
    mp[a] = mp.get(a, 0) + 1
    mp[b] = mp.get(b, 0) - 1

result, sum = 0, 0
ans = []
size = 0
for it in mp:
    ans.append(it)
    size += 1
ans.sort()
for _ in range(size):
    sum += mp[ans[_]]
    result = max(result, sum)
print(result)
