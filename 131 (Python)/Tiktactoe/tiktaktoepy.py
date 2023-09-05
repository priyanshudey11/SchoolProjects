def main():
    board_length= int(input("How big do you want the board to be: "))
    temp=[]
    board=[]
    for x in range(board_length):
            board.append('-')
    board=[board]*board_length
    '''
    for y in range(len(board)):
        temp.append(y)
    board.append(temp)
    '''
    for n in range(len(board)):
        print(board[n],'\n',sep='')
    game(board,board_length,win,player)

def game(board,board_length,win,player):
    countg=0
    xy=0
    while xy==0:
        if countg % 2 == 0:
            player=1
        elif countg % 2 != 0:
            player=2
        print('Player',player,'Turn')
        player_input_row=int(input("Which Row?:"))
        player_input_col=int(input("Which Col?:"))
        while(board[player_input_row][player_input_col] == playerval1) or (board[player_input_row][player_input_col] == playerval2):
            print('Spot already taken choice another value')
            player_input_row=int(input("Which Row?:"))
            player_input_col=int(input("Which Col?:"))

def wincheck(board,board_length,playerval1,playerval2,win,player_input_row,player_input_col):
    win=False
    for row in range(len(board)):
            if player==1:
                board[player_input_row][player_input_col]=playerval1
            if player==2:
                board[player_input_row][player_input_col]=playerval2
                
            for colum in range (len(board[row])):
                if([board[0][colum]]*len(board) == board):
                    if board[0][colum]== playerval1:
                        print('player 1 has won',playerval1)
                        
                    if board[0][colum]== playerval1:
                        print('player 2 has won',playerval2)
                        break
        #Up and Down  
        for row in range(len(board)):
            updown=[i[row] for i in board]
            for y in range(len(updown)):
                if updown[1:] == updown[:-1]:
                    if updown[0]=='x':
                        print('player 1 has won',playerval1)
                        break
                    elif updown[0]=='o':
                        print('player 2 has won',playerval2)  
                        break
                
            for colum in range (len(board[row])):
                if([board[0][colum]]*len(board) == board):
                    if board[0][colum]== playerval1:
                        print('player 1 has won',playerval1)
                        break
                    if board[0][colum]== playerval1:
                        print('player 2 has won',playerval2)
                        break   
        if countg>=board_length-1:
            #changed since old one did not work all the time
            # gets digonal values 
                digonaltop=[board[i][i] for i in range(len(board))]
                digonalbottom=[board[i][len(board)-i-1] for i in range(len(board))]
                #checks if everything in the diognal is the same 
                if digonaltop[1:] == digonaltop[:-1]:
                    if digonaltop[0]=='x':
                        print('player 1 has won',playerval1)
                        break
                    elif digonaltop[0]=='o':
                        print('player 2 has won',playerval2)  
                        break
                if digonalbottom[1:] == digonalbottom[:-1]:
                    if digonalbottom[0]=='x':
                        print('player 1 has won',playerval1)
                        break
                    elif digonalbottom[0]=='o':
                        print('player 2 has won',playerval2)
                        break
                    if countg==board_length*board_length:
                        if win==False:
                            print("It is a tie")
main()