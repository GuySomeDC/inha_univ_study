def matrix(i, j):  # Ai부터 Aj까지 multiplication 횟수
    if dp[i - 1][j - 1][0] != float('inf'):
        return dp[i - 1][j - 1][0]
    if i == j:
        dp[i - 1][j - 1][0] = 0
        dp[i - 1][j - 1][1] = i
        return dp[i - 1][j - 1][0]
    result = float('inf')
    min_k = 0
    for k in range(i, j):
        r = matrix(i, k) + matrix(k + 1, j) + p[i - 1] * p[k] * p[j]
        if r < result:
            result = r
            min_k = k
    dp[i - 1][j - 1][0] = result
    dp[i - 1][j - 1][1] = min_k
    return dp[i - 1][j - 1][0]


def print_optimal_parens(i, j):
    if i == j:
        return f'A{i}'
    return '(' + print_optimal_parens(i, dp[i - 1][j - 1][1]) + print_optimal_parens(dp[i - 1][j - 1][1] + 1, j) + ')'


if __name__ == '__main__':
    n = int(input('n='))  # matrix 개수
    p = []
    for _ in range(0, n + 1):
        p.append(int(input(f'p{_}=')))
    for _ in range(0, n):
        print(f'A{_ + 1}={p[_]}x{p[_ + 1]}')

    dp = [[[float('inf'), 0] for __ in range(0, n)] for _ in range(0, n)]
    matrix(1, n)
    print(dp[0][n - 1][0])
    print(print_optimal_parens(1, n))
