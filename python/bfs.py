from collections import deque
class graph:
    def __init__(self):
         self.graph={}

    def add_edge(self,u,v):
        if u not in self.graph:
            self.graph[u]=[]
        self.graph[u].append(v)

    def bfs(self,start_vertex):
        visited={vertex :False for vertex in self.graph}
        queue= deque([start_vertex])
        visited[start_vertex]=True

        print("Bfs traversal :")

        while queue:
            current_vertex=queue.popleft()
            print(current_vertex,end=' ')

        for neighbor in self.graph.get(current_vertex,[]):
            if  not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor]=True

def main():
    my_graph=graph()

    my_graph.add_edge(0,1)
    my_graph.add_edge(0,2)
    my_graph.add_edge(1,2)
    my_graph.add_edge(2,0)
    my_graph.add_edge(2,3)
    my_graph.add_edge(3,3)

    start_vertex= 0

    my_graph.bfs(start_vertex)

if __name__=="__main__":
    main()
    





