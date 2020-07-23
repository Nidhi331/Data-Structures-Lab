
#Kosa-rajus algorithm 

#Strongly Connected Components -Connected components are those in agraph in which all the vertices of a component are connected to each other,
# Strongly term refers to directed graphs. if all the vertices come in a single strongly component , then it is strongly component graph.
"""
Order array ?? - there is an array containing all the vertices such that (y->x) y is connected to x and x comes before y in the order array.

for eg. given a graph-    

        1 --->2
        !     !
        !     !
        4<--- 3
        
        1->2 ,2->3 , 3->4 ,4->1 (directed)
        the order array wl be [4,3,2,1] 
        
    this is basically done by making a dfs tree of a graph.
"""

"""
This algorithm basically says - if in the original graph there is a path to src--->sink , then in the reversed graph 
there wl be a path from src-->sink if ans only if both source and sink are present in the same strongly component of a 
graph.

"""


"""
To find how many strongly components a graph --- 
Firstly make the original graph and reversed graph both .
Compute the order array by running dfs from the original graph.
Run another dfs on the reversed graph by taking src as the last element of ordered array.
And as we find no. of connected components color each component.


"""

import os
import sys
from io import BytesIO, IOBase

gr,grr = {},{}

order = []


def dfs(s,v) :
    v[s] = 1 
    for i in gr[s] :
        if v[i] ==0 :
            dfs(i,v)
            
    order.append(s)
    
def dfs_rev(s,vis,col,comp) :
    vis[s] = 1 
    comp[s] = col
    for i in grr[s] :
        if vis[i]==0 :
            dfs_rev(i,vis,col,comp)
    

def solve() :
    n,m = map(int,input().split())
    v = [0 for i in range(n+1)]
    comp = [0 for i in range(n+1)]

    
    for i in range(1,n+1) :
        gr[i] = []
        grr[i] = []
        
    for i in range(m) :
        s,d = map(int,input().split())
        
        gr[s].append(d)
        grr[d].append(s)
        
    for i in range(1,n+1) :
        if v[i] == 0 :
            dfs(i,v)
            
    vis = [0 for i in range(n+1)]
    col = 1
    print(order)
            
    for i in range(n-1,-1,-1) :
        if vis[order[i]]==0 :
            dfs_rev(order[i],vis,col,comp)
            col += 1
            
    for i in range(1,n+1) :
        
        print(str(i)+ "-->" + str(comp[i]))
        

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












