import incidence_matrix
import pentominos
import examples

class Algorithm_X(object):
    def __init__(self, matrix):
        self.matrix = matrix
        self.o = []
        self.search(0)
        print(self.matrix.representation())
    
    def search(self, k):
        if self.matrix.h.right == self.matrix.h:
            return
        c = self.chooseColumnObj()
        self.matrix.coverColumn(c)
        r = c.down
        while r is not c:
            o[k] = r
            j = r.right
            while j is not r:
                self.matrix.coverColumn(j.listHeader)
                j = j.right
            self.search(k + 1)
            c = r.listHeader
            j = r.left
            while j is not r:
                self.matrix.uncoverColumn(j.listHeader)
                j = j.left
            r = r.down
        self.matrix.uncoverColumn(c)
        
    def chooseColumnObj(self):
        c = self.matrix.h
        s = 1e100000
        j = self.matrix.h.right
        while j is not self.matrix.h:
            if j.size < s:
                c = j
                s = j.size
            j = j.right
        return c
        
def append_all_possible_placements(matrix):
    names = []
    tiles = []
    currentColumnObject = matrix.h.right
    while currentColumnObject.name is not "root":
        if incidence_matrix.is_number(currentColumnObject.name):
            tiles.append(currentColumnObject.name)
        else:
            names.append(currentColumnObject.name)
        currentColumnObject = currentColumnObject.right
    pset = pentominos.fixed_pentominos_of_name_list(names)
    max0 = max([int(s[0]) for s in tiles])
    max1 = max([int(s[1]) for s in tiles])
    for p in pset.set:
        for i in range(0, max0):
            for j in range(0, max1):
                q = p.translate_by([i, j])
                if matrix.is_valid_placement(q.coos):
                    matrix.appendRow(q.name, [str(c[0]) + str(c[1]) for c in q.coos])
        
def run_scott_example():
    matrix = examples.scott_example()
    append_all_possible_placements(matrix)
    Algorithm_X(matrix)    

if __name__ == '__main__':
    run_scott_example()
    
    