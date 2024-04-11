import heapq

class uniformcostsearch:

    def __init__(self):
        self.graph={}
    
    def add_edge(self,start,end,weight):
        if start not in self.graph:
            self.graph[start]=[]
        self.graph[start].append((end,weight))

    def UCS(self,start,goal):
        priority_queue=[(0,start,[])]
        visited=set()

        while priority_queue:
            cost, current, path=heapq.heappop(priority_queue)

            if current not in visited:
                visited.add(current)
                path=path+[current]

                if current==goal:
                    return path,cost
                
                for neighbour,edge_cost in self.graph.get(current,[]):
                    if neighbour not in visited:
                        heapq.heappush(priority_queue,(cost+edge_cost,neighbour,path))

        return None,float('inf')

def main():
    my_graph=uniformcostsearch()

    my_graph.add_edge('maldon','tiptree',8)
    my_graph.add_edge('tiptree','clacton',29)
    my_graph.add_edge('tiptree','feering',3)
    my_graph.add_edge('clacton','maldon',40)
    my_graph.add_edge('clacton','harwich',17)
    my_graph.add_edge('feering','maldon',11)
    my_graph.add_edge('feering','blaxhall',46)
    my_graph.add_edge('harwich','tiptree',31)
    my_graph.add_edge('harwich','blaxhall',40)
    my_graph.add_edge('harwich','dunwich',53)
    my_graph.add_edge('blaxhall','dunwich',15)
    my_graph.add_edge('dunwich','blaxhall',17)

    start_vertex='maldon'
    end_vertex='dunwich'

    path,cost=my_graph.UCS(start_vertex,end_vertex)

    if path is not None:
        print(f"\nThe uniform cost search  path from {start_vertex}to{end_vertex} is")
        print("->".join(path))
        print("the cost is :",{cost})
    else:
        print("Path not found")

if __name__=="__main__":
    main()