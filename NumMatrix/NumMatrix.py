class NumMatrix(object):

    def __init__(self, matrix):
        self.matrix = matrix
        self.prefix()

    def prefix(self):
        rows, cols = len(self.matrix), len(self.matrix[0])

        for i in range(rows):
            for j in range(cols):
                top = self.matrix[i-1][j] if i > 0 else 0
                left = self.matrix[i][j-1] if j > 0 else 0
                diagonal = self.matrix[i-1][j-1] if i > 0 and j > 0 else 0
                
                self.matrix[i][j] += top + left - diagonal

        

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        total = self.matrix[row2][col2]

        top = self.matrix[row1 - 1][col2] if row1 > 0 else 0
        left = self.matrix[row2][col1 - 1] if col1 > 0 else 0
        diagonal = self.matrix[row1 - 1][col1 - 1] if row1 > 0 and col1 > 0 else 0

        return total - top - left + diagonal


numMatrix = NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]])
print(numMatrix.sumRegion(2, 1, 4, 3))
print(numMatrix.sumRegion(1, 1, 2, 2))
print(numMatrix.sumRegion(1, 2, 2, 4))
