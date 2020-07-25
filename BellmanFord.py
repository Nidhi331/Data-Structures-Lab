#Bellman-Ford Algorithm 

#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase

N= 10**5

adj = []
d = [sys.maxsize for i in range(N)]
u = [0 for i in range(N)]



def Bford(adj,s,n,p,m) :
    d[s] = 0
    
    p[s] = s

    for i in range(n) :
        
        x = -1
        
        for j in range(m) :
            
            if d[adj[j][0]]<sys.maxsize :
                
                if d[adj[j][1]]>d[adj[j][0]] + adj[j][2] :
                    
                    d[adj[j][1]] = d[adj[j][0]] + adj[j][2]
                    
                    p[adj[j][1]] = adj[j][0]
                    
            
                    x = adj[j][1]
                    
                    
    if x==-1 :
        
        print("No negative Cycle") 
        
        for i in range(1,n+1) :
        
            print("Shortest Distance " + str(s) + "-->" + str(i) + " " + str(d[i]))
    
        
        for i in range(1,n+1) :
            path = []
            
            k = i
            while(k!=s) :
                
                path.append(k)
                k = p[k]
                
            path.append(s)
            
        
            print("Shortest Path " + str(s) + "-->" + str(i) +" " +  str(path))
        
        
    
    else :
        
        y = x
        
        for i in range(n) :
            
            y = p[y]
            
            
        ncycle = []
        cur = y
        
        while(True) : 
            
            ncycle.append(cur)
            
            cur = p[cur]
            
            if cur==y and len(ncycle)>1 :
                
                break
            
        for i in range(len(ncycle)-1,-1,-1) :
            print(ncycle[i],end=" ")
            
    
            
        
def solve() :
    n,m = map(int,input().split())
    
    
        
    for i in range(m) :
        s,d,cost = map(int,input().split())
        
        adj.append([s,d,cost])
        
    
    p = [-1 for i in range(n+1)]
        
    start = int(input())  
    Bford(adj,start,n,p,m)
        
    
    


def main():
    solve()
    pass


# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()
