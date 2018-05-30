n = int(input())
colors = []
for i in range(n):
    colors.append(input())

data = [
    [0, 'Power', 'purple']
    , [0, 'Time', 'green']
    , [0, 'Space', 'blue']
    , [0, 'Soul', 'orange']
    , [0, 'Reality', 'red']
    , [0, 'Mind', 'yellow']
]

for color in colors:
    for i in range(len(data)):
        if data[i][2] == color:
            data[i][0] = 1

total = 0
for d in data:
    if d[0] == 0:
        total += 1

print(total)
for d in data:
    if d[0] == 0:
        print(d[1])
