# Probelem 1:
''' Tic Tac Toe Puzzle Problem'''
def sum(a,b,c):
    return a+b+c
def printBoard(xState,zState):
    print(f"{'X' if xState[0] else ('O' if zState[0] else 0)} | {'X' if xState[1] else ('O' if zState[1] else 0)} | {'X' if xState[2] else ('O' if zState[2] else 0)} ")
    print(f"--|---|---")
    print(f"{'X' if xState[3] else ('O' if zState[3] else 0)} | {'X' if xState[4] else ('O' if zState[4] else 0)} | {'X' if xState[5] else ('O' if zState[5] else 0)} ")
    print(f"--|---|---")
    print(f"{'X' if xState[6] else ('O' if zState[6] else 0)} | {'X' if xState[7] else ('O' if zState[7] else 0)} | {'X' if xState[8] else ('O' if zState[8] else 0)} ")
    pass


def checkWin(xState,zState):
    xwins=[[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]
    for win in xwins:
        if(sum(xState[win[0]],xState[win[1]],xState[win[2]])==3):
            print("X won the Match")
            return 1
        if(sum(zState[win[0]],zState[win[1]],zState[win[2]])==3):
            print("O won the Match")
            return 0
    return -1
        
    
if __name__=="__main__":
    xState=[0,0,0,0,0,0,0,0,0]
    zState=[0,0,0,0,0,0,0,0,0]
    turn=1 # 1 for X and 0 for O
    
    print("Welcome to Tic Tac Toe")
    while(True):
        printBoard(xState,zState)
        if(turn==1):
            print("X's Chance")
            value=int(input("Please Enter The Value: "))
            xState[value]=1
        else:
            print("O's Chance")
            value=int(input("Please Enter the Value: "))
            zState[value]=1
            
        cwin=checkWin(xState,zState)
        if(cwin!=-1):
            print("Match Over")
            break
        turn=1-turn
        
        