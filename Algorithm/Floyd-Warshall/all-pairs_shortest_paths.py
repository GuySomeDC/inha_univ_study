def print_graph():
    print('    ', end='')
    for q in range(n):
        print('%3s' % (q + 1), end=' ')
    print()
    for q, gr in enumerate(graph):
        print('%3s' % (q + 1), end=' ')
        for g in gr:
            print('%3s' % g, end=' ')
        print()


if __name__ == '__main__':
    directed = False  # if directed graph, set True, else set False
    weighted = True  # if weighted graph, set True, else set False
    n = int(input('n='))  # number of vertices
    graph = [[float('inf') if __ != _ else 0 for __ in range(n)] for _ in range(n)]
    while True:
        edge = input('v1 v2 weight=' if weighted else 'v1 v2=')  # if edge is 'end', stop
        # if directed v1->v2
        # vertices number must be 1 to n
        if edge == 'end':
            break
        edge = list(map(int, edge.split()))
        graph[edge[0] - 1][edge[1] - 1] = edge[2] if weighted else 0
        if not directed:
            graph[edge[1] - 1][edge[0] - 1] = edge[2] if weighted else 0
    for k in range(n):
        for i in range(n):
            for j in range(n):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    print_graph()
