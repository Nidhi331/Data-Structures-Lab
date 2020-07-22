#Shortest cycle in a graph 
#start bfs from every node and if you find back edge(cycle)
#check d[child]>=d[parent]

#eg. 
"""
     1 
   2   3 
   
   in the above graph u start doing bfs from 1 you update distance of 2 and 3 as 1 (from src) 
   and then u check for adjacency of 2,i.e 3 d[2]>=d[3] so the distance of the cycle d[2]+d[3]+1
   
"""

def bfs(s,g,v,ans) :

    q = []
    q.append(s)
    v[s] = 1
    while(q!=[]) :
        popped = q.pop(0)
    
        for i in g[popped] :
            
            if v[i]==0 :
                v[i] = 1
            
                q.append(i)
            
                d[i] = d[popped] + 1 
                
            elif d[i]>=d[popped] :
                ans = min(ans,d[i]+d[popped]+1)

    return ans

n,m = map(int,input().split())

adj = {}
for i in range(n) :
    
    adj[i] = []
    
for i in range(m) :
    s,d = map(int,input().split())
    adj[s].append(d)
    adj[d].append(s)
ans = n + 1  

for i in range(n) :
    
    d = [0 for i in range(n)]
    v = [0 for i in range(n)]

    a = bfs(i,adj,v,ans)
    if a<ans :
        
        ans = a
    
    
    
if ans==n+1 :
    
    print("No Cycle")
    
else :
    
    print("Shortest Cycle " + str(ans))
    
    
    
    
    
    
    
    
    
    
    
    
    