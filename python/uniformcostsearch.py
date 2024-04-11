import heapq

def uniform_cost_search(graph, start, goal):
    visited = set()  # Keep track of visited nodes.
    pq = [(0, start, [])]  # Priority queue, (cost, node, path).

    while pq:
        cost, node, path = heapq.heappop(pq)  # Get the node with the lowest cost.
        if node == goal:
            return path + [node], cost  # Found the goal!

        if node not in visited:
            visited.add(node)
            for neighbor, edge_cost in graph[node].items():
                new_cost = cost + edge_cost
                heapq.heappush(pq, (new_cost, neighbor, path + [node]))

    return None, None  # No path found.

# Example usage
graph = {
    'Maldon': {'Tiptree': 8},
    'Tiptree': {'Feering': 3,'calcton':29},
    'Feering': {'Maldon': 11, 'Blaxhall': 46,},
    'calcton': {'Maldon': 40, 'Harwich': 17},
    'Harwich': {'Tiptree': 31, 'Blaxhall': 40,'Dunwich':53},
    'Blaxhall': {'Dunwich': 15},
    'Dunwich': {'Blaxhall': 17},
}

start = 'Maldon'  # Corrected start node label
goal = 'Dunwich'

path, min_cost = uniform_cost_search(graph, start, goal)

if path:
    print(f"Minimum cost from {start} to {goal} is = {min_cost}")
    print("Path:", path)
else:
    print("No path found.")
