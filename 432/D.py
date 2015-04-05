from math import ceil, log2

def sufar(txt):
    txt = txt + chr(0)
    N, tokens = len(txt), sorted(set(t for t in txt))

    equivalence = {t: i for i, t in enumerate(tokens)}

    c, r = [equivalence[t] for t in txt], [(0, 0, 0)]

    for i in range(1, ceil(log2(N)) + 1):
        n = 2 ** (i - 1)

        r = sorted([(c[j],  c[(j + n) % N], j) for j in range(N)])

        c[r[0][2]] = 0
        for j in range(1, N):
            c[r[j][2]] = c[r[j - 1][2]]
            if r[j][0:2] != r[j - 1][0:2]:
                c[r[j][2]] += 1

    return [result[2] for result in r][1:]

txt = input()
suf = sufar(txt)
total, result = 0, []
for i in range(1, len(txt)):
    if txt[:i] == txt[-i:]:
        count, total = 1, total + 1
        l, r = 0, len(txt)
        while (l < r):
            m = (l + r) // 2

            if txt[suf[m]:] == txt[:i]:
                break
            elif txt[suf[m]:] < txt[:i]:
                l = m
            else:
                r = m

        while m + 1 < len(txt) and txt[suf[m+1]:].startswith(txt[:i]):
            m, count = m + 1, count + 1

        result.append([len(txt[:i]), count])
result.append([len(txt), 1])

print(total + 1)
for i in result:
    print(i[0], i[1])
