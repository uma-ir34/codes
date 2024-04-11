class graph:
    def __init__(self):
        self.graph={}

    def add_edge(self,u,v):
        if u not in self.graph:
            self.graph[u]=[]
        self.graph[u].append(v)

    def dfs_util(self,vertex,visited):
        visited[vertex]=True
        print(vertex,end=' ')

        for neighbor in self.graph.get(vertex,[]):
            if neighbor in visited and not  visited[neighbor]:
                self.dfs_util(neighbor,visited)


    def dfs(self,start_vertex):
        visited={ vertex:False for vertex in self.graph}

        print("the DFS traversal is")
        self.dfs_util(start_vertex,visited)
        print()

def main():
    my_graph=graph()

    my_graph.add_edge(0,1)
    my_graph.add_edge(0,2)
    my_graph.add_edge(1,2)
    my_graph.add_edge(2,3)
    my_graph.add_edge(3,4)
    my_graph.add_edge(3,5)
    my_graph.add_edge(4,5)

    start_vertex=0

    my_graph.dfs(start_vertex)

if __name__=="__main__":
    main()