t, maxn, maxm = map(int, input().split())
table = [[0] * maxm for i in range(maxn)]
cnt = [[0] * maxm for i in range(maxn)]

for i in range(t):
    n, m, score = map(int, input().split())
    table[n - 1][m - 1] += score
    cnt[n - 1][m - 1] += 1

for i in range(maxn):
    for j in range(maxm):
        if cnt[i][j] > 0:
            table[i][j] /= cnt[i][j]
        else:
            table[i][j] = '-'
        if j == maxm - 1:
            print('& ', '{:.2f}'.format(table[i][j]) if table[i][j] != '-' else '-')
        else:
            print('& ', '{:.2f}'.format(table[i][j]) if table[i][j] != '-' else '-', end=' ')
