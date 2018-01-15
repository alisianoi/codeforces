n, k = map(int, input().split())
xs = list(map(int, input().split()))

ans = 0

for x in xs:
    if k % x == 0 and x > ans:
        ans = x

print(k // ans)
