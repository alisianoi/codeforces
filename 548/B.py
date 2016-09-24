n, m, q = map(int, input().split())

xs = [list(map(int, input().split())) for i in range(n)]

def go(xs):
    answer, total = 0, 0
    for x in xs:
        total = total + 1 if x else 0

        answer = total if total > answer else answer

    return answer

ss = [go(x) for x in xs]

for i in range(q):
    i, j = map(int, input().split())

    if xs[i - 1][j - 1] == 0:
        xs[i - 1][j - 1] = 1
        ss[i - 1] = go(xs[i - 1])
    else:
        xs[i - 1][j - 1] = 0
        ss[i - 1] = go(xs[i - 1])

    print(max(ss))
