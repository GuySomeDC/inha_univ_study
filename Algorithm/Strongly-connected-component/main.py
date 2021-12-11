def dfs(start):
    if visit[start]:
        return
    print(alphabet[start])
    visit[start] = True

    for g in graph[start]:
        dfs(g)
    stack.append(start)


if __name__ == '__main__':
    alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXTZ'
    n = int(input('n='))  # number of vertices
    graph = [[] for _ in range(n + 1)]
    stack = []
    visit = [False for _ in range(n + 1)]
    while True:
        edge = input('edge=')  # edge v1->v2, input format=v1 v2
        if edge == 'end':
            break
        v1, v2 = map(int, edge.split())  # edge v1->v2
        graph[v1].append(v2)
    start_vertex = int(input('start='))
    dfs(start_vertex)
    for i in range(1, n + 1):
        if not visit[i]:
            dfs(i)
    print(stack)
    print([alphabet[s] for s in stack])
