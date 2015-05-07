import incidence_matrix
import pentominos

class Algorithm_X():
	def __init__(self, matrix):
	    self.matrix = matrix
	    self.o = []
	    search(0)
	    print(matrix.representation())
	    
	def search(self, k):
		if matrix.h.right == matrix.h:
			return
		c = chooseColumnObj()
		matrix.coverColumn(c)
		r = c.down
		while r is not c:
			o[k] = r
			j = r.right
			while j is not r:
				matrix.coverColumn(j.listHeader)
				j = j.right
			search(k + 1)
			c = r.listHeader
			j = r.left
			while j is not r:
				matrix.uncoverColumn(j.listHeader)
				j = j.left
			r = r.down
		matrix.uncoverColumn(c)
		
	def chooseColumnObj(self):
		c = h
		s = float("inf")
		j = h.right
		while j is not h:
			if j.size < s:
				c = j
				s = j.size
			j = j.right
		return c
		
def run_scott_example():
	matrix = examples.scott_example()
	matrix.append_all_possible_placements()
	Algorithm_X(matrix)	    
	