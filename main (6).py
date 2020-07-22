
#Bipartite graph 
# A graph can be divided to two sets such that there is not any two vertices
# in a single set which contain an edge 

# S(x) != S(y)

# Can a tree be Bipartite tree?
"""
        1 
        
    2      3
     
  4   5  6   7
   

"""
# in the above eg. set1=[1,4,5,6,7] and set2=[2,3] is the solution for Bipartite tree 
# so yes a tree can be expressed as bipartite tree, such that alterate level vertices are in one set and the rest other in another ser 

# Graph :

"""
        1 
    
    2       3
    
        4
above is a cyclic graph , s1= [1,4] and s2 = [2,3] is the solution for bipartite graph.
so a graph containing cycle of even length can be expressed as bipartite
graph
      
another eg. 
        1 
            5    
    2 
            4
       3 
      (all the gaps are connected)
      
    if s1=[1,3] s2= [2,4] , 5 cannot be put into both s1 and s2. so the graph contating cycle of odd length cannot be expressed as bipatite graph.
      
"""
"""
color - 0 (unvisited)
        1(visited not discovered)
        2 (discovered)
"""

def dfs(start,graph,v,par,col,odd) :
    
    v[start] = col 
    
    for i in graph[start] :
        
        if v[i]==0 :
            
            dfs(i,graph,v,start,3-col,odd)
            
        elif i!=par and col==v[i]: 
            #backedge(cycle)
            odd = 1 
        
    return odd
            
n,m = map(int,input().split())
adj = {}

for i in range(n) :
    
    adj[i] = []
    
for i in range(m) :
    
    s,d = map(int,input().split())
    
    adj[s].append(d)
    adj[d].append(s)
    
v = [0 for i in range(n)]
odd_len_cycle = 0

    
if dfs(0,adj,v,0,1,odd_len_cycle) :
    print("No,Graph cannot be bipartite")
    
else :
    print("Yes,Graph is bipartite")
    
    
    
    
    
    
    
    
    
    
    
    
    
    

































