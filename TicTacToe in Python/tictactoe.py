game_grid = "         "
isRunning = True
currentMove = 1

def printGrid():
    print("---------")
    print("|" + " " + game_grid[0] + " " + game_grid[1] + " " + game_grid[2] + " " + "|")
    print("|" + " " + game_grid[3] + " " + game_grid[4] + " " + game_grid[5] + " " + "|")
    print("|" + " " + game_grid[6] + " " + game_grid[7] + " " + game_grid[8] + " " + "|")
    print("---------")

def checkStatus():
    global isRunning
    xwin = False
    owin = False
    notfinished = False
    impossible = False

    xcount = 0
    ocount = 0
    for c in game_grid:
        if c == 'X':
            xcount += 1
        if c == 'O':
            ocount += 1

    if abs(xcount-ocount) > 1:
        impossible = True

    if xcount + ocount < 9:
        notfinished = True


    # checking for lines and cols
    for i in range(0, 7, 3):
        if game_grid[i] == game_grid[i+1] == game_grid[i+2] == 'X':
                xwin = True
        if game_grid[i] == game_grid[i+1] == game_grid[i+2] == 'O':
                owin = True

    for i in range(3):
        if game_grid[i] == game_grid[i+3] == game_grid[i+6] == 'X':
                xwin = True
        if game_grid[i] == game_grid[i+3] == game_grid[i+6] == 'O':
                owin = True

    # checking the diagonals
    if game_grid[0] == game_grid[4] == game_grid[8] == 'X':
        xwin = True
    if game_grid[2] == game_grid[4] == game_grid[6] == 'X':
        xwin = True
    if game_grid[0] == game_grid[4] == game_grid[8] == 'O':
        owin = True
    if game_grid[2] == game_grid[4] == game_grid[6] == 'O':
        owin = True

    if xwin == True and owin == True:
        impossible = True

    if impossible == True:
        print("Impossible")
        isRunning = False
    else:
        if xwin == False and owin == False and notfinished == False:
            printGrid()
            print("Draw")
            isRunning = False
        elif xwin == True:
            printGrid()
            print("X wins")
            isRunning = False
        elif owin == True:
            printGrid()
            print("O wins")
            isRunning = False

def getInput(currentMove):
    global game_grid
    rightInput = False
    if currentMove == 1:
        player = 'X'
    else:
        player = 'O'
    while rightInput == False:
        coordinates = input("Enter cells:")
        if (' ' in coordinates) == False:
            print("You should enter numbers!")
        else:   
            x, y = coordinates.split(" ") 
            if x.isdigit() == False or y.isdigit() == False:
                print("You should enter numbers!")
            else: 
                    x = int(x)
                    y = int(y)
                    index = 3*(x-1) + (y-1)
                    if x > 3 or x < 1 or y > 3 or y < 1:
                        print("Coordinates should be from 1 to 3!")
                    elif game_grid[index] != ' ':
                        print("This cell is occupied! Choose another one!")
                    else:
                        game_grid = game_grid[:index] + player + game_grid[index + 1:]
                        rightInput = True

while(isRunning):
    printGrid()
    getInput(currentMove)
    currentMove = 1 - currentMove
    checkStatus()
