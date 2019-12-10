board = [
    [1, 0, 0, 0, 6, 0, 9, 0, 0],
    [9, 7, 4, 8, 5, 0, 0, 0, 0],
    [0, 0, 0, 0, 9, 0, 0, 0, 0],
    [0, 1, 7, 5, 0, 0, 0, 3, 0],
    [0, 4, 0, 9, 0, 3, 0, 7, 0],
    [0, 3, 0, 0, 0, 8, 2, 5, 0],
    [0, 0, 0, 0, 3, 0, 0, 0, 0],
    [0, 0, 0, 0, 8, 7, 5, 2, 4],
    [0, 0, 2, 0, 4, 0, 0, 0, 6]
] # the board representation of the puzzle to be solved

def solve(board):
  empty_square = find_empty_square(board) # find the next empty square
  if not empty_square:
    return True # if there are no more empty squares, puzzle is solved
  else:
    row, col = empty_square # tuple unpacking
  
  for i in range(1, 10): # for numbers 1 - 9
    if check_board_valid(board, i, (row, col)): # check if inserting the number is valid
      board[row][col] = i # if so, make the change and set the board's number

      if solve(board): # if with this number the board id recursively solved all the way
        return True
      
      board[row][col] = 0 # number was not correct, replace with zero and backtrack

def display_board(board):
    for i in range(len(board)):
        # print lines to separate rows in groups of three
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - -")

        for j in range(len(board[0])):
            # print vertical lines to separate columns in groups of three
            if j % 3 == 0 and j != 0:
                print(" | ", end="")

            #print the actual numbers
            if j == 8:
                print(board[i][j])
            else:
                print(str(board[i][j]) + " ", end="") # if number is not the last one in the column, don't print a new line
                    

def find_empty_square(board):
  #iteration through every square on the board
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0: # if board square is represented by 0
                return (i, j)
    return None


def check_board_valid(board, num, pos):
    # check row
    for i in range(len(board[0])):
        if board[pos[0]][i] == num and pos[1] != i: # if the number at the position equals the number being inserted
            return False

    # check column
    for i in range(len(board)):
        if board[i][pos[1]] == num and pos[0] != i:
            return False

    # check 3x3 box
    box_x = pos[1] // 3 # integer divison to find which 3x3 ninth the digit is contained within
    box_y = pos[0] // 3

    for i in range(box_y * 3, box_y * 3 + 3): #iterate through every column in the 3x3 box
        for j in range(box_x * 3, box_x * 3 + 3):
            if board[i][j] == num and (i, j) != pos:
                return False

    return True


# demonstration
print("====Unsolved Puzzle====")
display_board(board)
print("\n")
solve(board)
print("==Fully Solved Puzzle==")
display_board(board)