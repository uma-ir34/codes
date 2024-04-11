class weighteddirected:

    def __init__(self):
        self.graph={}

    def add_edge(self,start,end,weight):
        if start not in self.graph:
            self.graph[start]=[]
        self.graph[start].append((end,weight))
    

    def adjacency_list(self):
        print("The adjacency list :")
        for vertex in self.graph:
            print(f"{vertex}->{','.join(f'({neighbour},{weight})'for neighbour,weight in self.graph[vertex])}")


def main():

    my_graph=weighteddirected()

    num_edges=int(input("Enter the number of edges"))
    for _ in range(num_edges):
        edge = input("Enter edge(start end weight)").split()
        start,end,weight=edge[0],edge[1],edge[2]
        my_graph.add_edge(start,end,weight)

    my_graph.adjacency_list()

if __name__=="__main__":
    main()
            