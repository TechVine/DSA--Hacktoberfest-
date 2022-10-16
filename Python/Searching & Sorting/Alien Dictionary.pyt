class graph:
    def __init__(self,k):
        self.matrix = [ [False for _ in range(k)] for _ in range(k) ]
        self.ancestors = [0 for _ in range(k)]
        self.index = {}
        self.next_index = 0
        self.characters = ''
    
    def add_char(self,char):
        if char in self.index:
            return
        self.index[char] = self.next_index
        self.next_index += 1
        self.characters += char
    
    def add_edge(self,first,second):
        i1 = self.index[first]
        i2 = self.index[second]
        if self.matrix[i1][i2]:
            return
        self.ancestors[i2] += 1
        self.matrix[i1][i2] = True
    
    def dfs(self,location,order):
        if self.ancestors[location]>1:
            self.ancestors[location] -= 1
            return
        
        order.append(self.characters[location])
        
        for i in range(len(self.matrix)):
            if self.matrix[location][i]:
                self.dfs(i,order)
    
    def topo_sort(self):
        order = []
        for i in range(len(self.matrix)):
            if self.ancestors[i] == 0:
                self.dfs(i,order)
        return order
class Solution:
    def findOrder(self,alien_dict,n,k):
        g = graph(k)
        for c in alien_dict[0]:
            g.add_char(c)
        
        for i in range(1,n):
            for c in alien_dict[i]:
                g.add_char(c)
            
            length = min( len(alien_dict[i]) , len(alien_dict[i-1]) )
            for j in range(length):
                if alien_dict[i-1][j] != alien_dict[i][j]:
                   g.add_edge( alien_dict[i-1][j] , alien_dict[i][j] )
                   break
        
        lst = g.topo_sort()
        order = ''
        for c in lst:
            order += c
        return order
    
    
