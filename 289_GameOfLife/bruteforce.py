class Solution:
    def updateCell(self, originalBoard: List[List[int]], row: int, col:int) -> int:
        m = len(originalBoard)
        n = len(originalBoard[0])
        countNeighbors = -originalBoard[row][col]
        for i in range(max(0, row-1), min(m, row+2)):
            for j in range(max(0, col-1), min(n, col+2)):
                countNeighbors += originalBoard[i][j]
        
        if (originalBoard[row][col] == 0):
            return 1 if countNeighbors == 3 else 0
        return 1 if countNeighbors == 2 or countNeighbors == 3 else 0

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        originalBoard = [x[:] for x in board]
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = self.updateCell(originalBoard, i, j)
        