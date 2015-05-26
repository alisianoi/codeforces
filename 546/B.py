n = int(input())
cool = [int(i) for i in input().split()]
cool.sort()

total = 0
for i in range(n - 1):
    if cool[i + 1] <= cool[i]:
        total += cool[i] - cool[i + 1] + 1
        cool[i + 1] = cool[i] + 1

print(total)
