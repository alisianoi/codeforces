a, b, s = [int(i) for i in input().split()]
x = abs(a) + abs(b)
if s >= x and (s - x) % 2 == 0:
    print("YES")
else:
    print("No")
