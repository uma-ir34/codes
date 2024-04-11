import random

def objective_function(x):
    return -1*(x **2)

def hillclimbing(initial_value,step_size,max_iteration):
    current_value=initial_value

    for _ in range(max_iteration):
        neighbors =[current_value-step_size,current_value,current_value+step_size]
        neighbor_value=[objective_function(neighbor)for neighbor in neighbors]

        best_neighbor=neighbors[neighbor_value.index(max(neighbor_value))]

        if objective_function(best_neighbor)<=objective_function(current_value):
         break

        current_value=best_neighbor

    return current_value,objective_function(current_value)

def main():
   
   initial_value=random.uniform(-10,10)
   step_size=0.1
   max_iteration=100
   peak_value,peak_objective=hillclimbing(initial_value,step_size,max_iteration)

   print("\n the hill climb search is")
   print(f"The initial value is {initial_value}")
   print(f"The peak value is {peak_value}")
   print(f"The peak objective is {peak_objective}")

if __name__=="__main__":
   main()