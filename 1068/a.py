N, M, K, L = list(map(int, input().split()))

each = (K + L) // M

if (K + L) % M != 0:
    each += 1

if each * M > N:
    print(-1)
else:
    print(each)
