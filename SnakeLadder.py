
import math


board = [0 for i in range(50)]

board[2] = 13
board[5] = 2
board[9] = 18
board[18] = 11 
board[17] = -12
board[20] = -14 
board[24] = -8
board[25] = 10 
board[34] = -22
board[32] = -2 


adj = {}
visited = [0 for i in range(37)]

for i in range(0,37) :
    
    adj[i] = []

    for j in range(1,7) :
        
        dst = i + j + board[i+j]
    
        if dst<=36 :
            adj[i].append(dst)
    
    
q = []

d = [math.inf for i in range(37)]
d[0]=0
q.append(0)

visited[0]=1 

while(q!=[]) :
    
    popped = q.pop(0)
    
    #print(popped)
    
    for i in adj[popped] :
        
        if visited[i]==0 :
            
            q.append(i)
            
            
            d[i] = d[popped] + 1
            
        visited[i]=1 
        
src = 0

for i in range(0,37) :
  print(str(0) +  "->" + str(i) ,end=" " )
  print(d[i])
        




















    
    
    
    

