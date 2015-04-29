n = int(input())
a = input()

sub = {
    '0':None,
    '1':None,
    '2':'2',
    '3':'3',
    '4':'322',
    '5':'5',
    '6':'53',
    '7':'7',
    '8':'7222',
    '9':'7332',
}

result = []
for i in a:
    if sub[i]:
        for j in sub[i]:
            result.append(j)
print(''.join(sorted(result, reverse=True)))
