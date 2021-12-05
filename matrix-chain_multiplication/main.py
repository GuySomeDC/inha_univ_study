def matrix(i, j):  # Ai부터 Aj까지 multiplication 횟수
    if dp[i - 1][j - 1] != float('inf'):
        return dp[i - 1][j - 1]
    if i == j:
        dp[i - 1][j - 1] = 0
        return dp[i - 1][j - 1]
    if j - i == 1:
        dp[i - 1][j - 1] = p[i - 1] * p[i] * p[j]
        return dp[i - 1][j - 1]
    result = min([matrix(i, k) + matrix(k + 1, j) + p[i - 1] * p[k] * p[j] for k in range(i, j)])
    dp[i - 1][j - 1] = result
    return dp[i - 1][j - 1]


if __name__ == '__main__':
    n = int(input('n='))  # matrix 개수
    p = []
    for _ in range(0, n + 1):
        p.append(int(input(f'p{_}=')))
    for _ in range(0, n):
        print(f'A{_ + 1}={p[_]}x{p[_ + 1]}')

    dp = [[float('inf') for __ in range(0, n)] for _ in range(0, n)]
    matrix(1, n)
    for d in dp:
        print(d)
    print(dp[0][n - 1])
