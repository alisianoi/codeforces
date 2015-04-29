import sys

n, m = [int(i) for i in input().split()]

grid = [[j for j in input()] for i in range(n)]

def get_degree(grid, i, j):
    n, m = len(grid), len(grid[0])
    degree = 0
    if i - 1 >= 0 and grid[i - 1][j] == ".": degree += 1
    if i + 1 <  n and grid[i + 1][j] == ".": degree += 1
    if j - 1 >= 0 and grid[i][j - 1] == ".": degree += 1
    if j + 1 <  m and grid[i][j + 1] == ".": degree += 1
    return degree

def get_empty_neighbors(grid, i, j):
    n, m = len(grid), len(grid[0])
    neighbors = []
    if i - 1 >= 0 and grid[i - 1][j] == ".":
        neighbors.append((i - 1, j))
    if i + 1 <  n and grid[i + 1][j] == ".":
        neighbors.append((i + 1, j))
    if j - 1 >= 0 and grid[i][j - 1] == ".":
        neighbors.append((i, j - 1))
    if j + 1 <  m and grid[i][j + 1] == ".":
        neighbors.append((i, j + 1))
    return neighbors

vertices = []
for i in range(n):
    for j in range(m):
        if grid[i][j] == "." and get_degree(grid, i, j) == 1:
            vertices.append((i, j))

while vertices:
    i, j = vertices.pop()
    if i - 1 >= 0 and grid[i - 1][j] == ".":
        grid[i - 1][j], grid[i][j] = "^", "v"
        for nbr in get_empty_neighbors(grid, i - 1, j):
            if get_degree(grid, nbr[0], nbr[1]) == 1:
                vertices.append(nbr)
    if i + 1 <  n and grid[i + 1][j] == ".":
        grid[i + 1][j], grid[i][j] = "v", "^"
        for nbr in get_empty_neighbors(grid, i + 1, j):
            if get_degree(grid, nbr[0], nbr[1]) == 1:
                vertices.append(nbr)
    if j - 1 >= 0 and grid[i][j - 1] == ".":
        grid[i][j - 1], grid[i][j] = "<", ">"
        for nbr in get_empty_neighbors(grid, i, j - 1):
            if get_degree(grid, nbr[0], nbr[1]) == 1:
                vertices.append(nbr)
    if j + 1 <  m and grid[i][j + 1] == ".":
        grid[i][j + 1], grid[i][j] = ">", "<"
        for nbr in get_empty_neighbors(grid, i, j + 1):
            if get_degree(grid, nbr[0], nbr[1]) == 1:
                vertices.append(nbr)

for i in range(n):
    for j in range(m):
        if grid[i][j] == ".":
            print("Not unique")
            sys.exit()

for i in range(n):
    for j in range(m):
        print(grid[i][j], end="")
    print()
