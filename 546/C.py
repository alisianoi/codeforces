from math import factorial

n = int(input())
s1 = [int(i) for i in input().split()][1:]
s2 = [int(i) for i in input().split()][1:]

i, finished, N = 1, False, 120
while s1 and s2:
    x, y = s1.pop(0), s2.pop(0)
    if x > y:
        s1 += [y, x]
    else:
        s2 += [x, y]
    if i == N:
        print(-1)
        break
    i = i + 1

if not s1:
    print(i - 1, 2)
elif not s2:
    print(i - 1, 1)
