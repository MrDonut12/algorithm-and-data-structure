from collections import Counter

q = int(input())
for _ in range(q):
    n = int(input())
    s, t = input().split()
    if Counter(s) == Counter(t):
        print("YES")
    else:
        print("NO")
