n, m = [int(i) for i in input().split()]
boys = [int(i) for i in input().split()][1:]
girls = [int(i) for i in input().split()][1:]

def gcf(a, b):
    while b:
        a, b = b, a % b
    return a

g = gcf(n, m)

for i in range(g):
    happy = False
    for boy in boys:
        if boy % g == i:
            happy = True
            break
    for girl in girls:
        if girl % g == i:
            happy = True
            break
    if not happy:
        print("NO")
        break

if happy:
    print("YES")
