class weighted:
    def __init__(self):
        self.graph={}
        
    def add_edge(self,start,end):
        if start not in self.graph:
            self.graph[start]=[]
        self.graph[start].append(end)


    def adjacency_list(self):
        print("Adjacenecy list :")
        for vertex in self.graph:
            print(f"{vertex}->{','.join(map(str,self.graph[vertex]))}")
        

def main():
    my_graph=weighted()

    num_vertex=int(input("Enter the number of vertex"))

    for _ in range(num_vertex):
        startvertex,endvertex=map(int,input("Add edge(start end)").split())

        my_graph.add_edge(startvertex,endvertex)

    my_graph.adjacency_list()

if __name__=="__main__":
    main()
