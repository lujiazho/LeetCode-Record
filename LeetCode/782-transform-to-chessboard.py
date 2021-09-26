###############################################################################################
# This question is more like MATH, we need to know the property of the board
###########
# 时间复杂度：O(n^2), most of the time complexity is attributed to CHECK the first property
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        N = len(board)
        # this line checks the condition that any two columns or rows must be the same or inverse(0-1 swapped)
        if any(board[0][0]^board[0][j]^board[i][0]^board[i][j] for i in range(N) for j in range(N)): return -1
        # under the property above, we only need to check the first row and column, then we're sure all other Rs/Cs must be set up already.
        # This line is to check the condition: every single line(column or row) must have N/2 ones if N%2 == 0
        # N/2 or (N+1)/2 ones if N%2 == 1, where the / should be exact division(means we take the quotient without reminder)
        if not N//2 <= sum(board[0]) <= (N+1)//2: return -1
        if not N//2 <= sum(board[i][0] for i in range(N)) <= (N+1)//2: return -1
        
        # we want to arrange it into 010101... by default
        col = sum(board[0][i] != i%2 for i in range(N))
        row = sum(board[i][0] != i%2 for i in range(N)) # if not equals, we get the count of swaps
        
        if N%2:
            # when N is odd, the count of swaps cannot be odd, because if it was, this swaps cannot be successful
            # so we have to make it N - count, which means we arrange it into 101010..
            # actually, the col and row must be both odd or even, so the if statement can be merged
            if col%2: col = N - col
            if row%2: row = N - row
        else:
            # when N is even, the count of swaps is always even, so we choose the smaller one
            # because both cases are acceptable, whether 0101.. or 1010..
            col = min(col, N - col)
            row = min(row, N - row)
        # the count needs being divided by 2, cause only one step is needed when swap two rows or columns
        return (col + row)//2