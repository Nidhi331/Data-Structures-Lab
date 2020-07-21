

n = int(input()) #no.of vertices

m = int(input()) #no.of edges

adj = {}
visited = [0 for i in range(n+1)]

for i in range(1,n+1) :
    
    adj[i] = []

for i in range(m) :
    
    s,d = map(int,input().split())
    
    adj[s].append(d)
    
    adj[d].append(s)
    
q = []
p = [0 for i in range(n+1)] #to store each node is coming from where so that we can get shortest path between any source and vertex

q.append(1)

visited[1]=1 

while(q!=[]) :
    
    popped = q.pop(0)
    
    print(popped)
    
    for i in adj[popped] :
        
        if visited[i]==0 :
            
            q.append(i)
            
            p[i] = popped
            
        visited[i]=1 
        
print(p)
path = []

src,dst = map(int,input().split())

if visited[dst]==0 :
    
    print("No path")
    
else :
    v = dst
    
    while(v != 0) :
        
        path.append(v)
        
        v = p[v]
        
print(path)
        
        




















    
    
    
    
