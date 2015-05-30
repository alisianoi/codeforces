n = int(input())
colors = [[int(i) for i in input().split()] for j in range(n)]
plays = [[0, 0] for i in range(n)]
home, away = [0 for i in range(10**5 + 1)], [0 for i in range(10**5 + 1)]

for color in colors:
    home[color[0]] += 1
    away[color[1]] += 1

for i in range(n):
    print(n - 1 + home[colors[i][1]], n - 1 - home[colors[i][1]])
