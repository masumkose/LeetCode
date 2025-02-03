""" class Solution(object):
    def backtrack(self, board, word, x, y, i):
        
        if x < 0 or x >= len(board) or y < 0 or y >= len(board[0]):
            return False

        if i == len(word) - 1 and word[i] == board[x][y]:
            return True

        if word[i] == board[x][y]:
            temp = board[x][y]
            board[x][y] = '#'  

            if (self.backtrack(board, word, x + 1, y, i + 1) or
                self.backtrack(board, word, x, y + 1, i + 1) or
                self.backtrack(board, word, x, y - 1, i + 1) or
                self.backtrack(board, word, x - 1, y, i + 1)):
                return True

            board[x][y] = temp
        if (self.backtrack(board, word, x + 1, y, 0) or
                self.backtrack(board, word, x, y + 1, 0)):
            return True
        return False




    def exist(self, board, word):
        if self.backtrack(board, word, 0, 0, 0):
            return True
        return False
         """


class Solution(object):
    def exist(self, board, word):
        if not board:
            return False

        rows, cols = len(board), len(board[0])

        def dfs(r, c, index):
            if index == len(word):
                return True
            if r < 0 or c < 0 or r >= rows or c >= cols or board[r][c] != word[index]:
                return False

            temp, board[r][c] = board[r][c], '#'
            found = (dfs(r+1, c, index + 1) or 
                     dfs(r, c+1, index + 1) or 
                     dfs(r-1, c, index + 1) or 
                     dfs(r, c-1, index + 1)) 
            board[r][c] = temp

            return found
        
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0] and dfs(i,j,0):
                    return True
        return False
        



sol = Solution()

print(sol.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"))
print(sol.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"))
print(sol.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"))
print(sol.exist([["a","b"],
                 ["c","d"]], word = "abcd"))