board = [6, 5, 3, 2, 4, 8, 7, 0, 1]
solution = [1, 2, 3, 4, 5, 6, 7, 8, 0]
 
def bfs(board):
    count = 0
    current_nodes = []
    current_nodes.append(board)
    new_nodes = []
    used = []
    used.append(board)
   
    if board == solution:
        return count
   
    while True:
        for node in current_nodes:
            index = node.index(0)
            #create left
            if (index % 3 != 0):
                new_board = list(node)
                value = new_board[index - 1]
                new_board[index - 1] = 0
                new_board[index] = value
                if not new_board in used:
                    used.append(new_board)
                    new_nodes.append(new_board)
                    #print (new_board)
           
            #create right
            if (index % 3 != 2):
                new_board = list(node)
                value = new_board[index + 1]
                new_board[index + 1] = 0
                new_board[index] = value
                if not new_board in used:
                    used.append(new_board)
                    new_nodes.append(new_board)
                    #print (new_board)
                   
            #create up
            if (index > 2):
                new_board = list(node)
                value = new_board[index - 3]
                new_board[index - 3] = 0
                new_board[index] = value
                if not new_board in used:
                    used.append(new_board)
                    new_nodes.append(new_board)
                    #print (new_board)
                   
            #create down
            if (index < 6):
                new_board = list(node)
                value = new_board[index + 3]
                new_board[index + 3] = 0
                new_board[index] = value
                if not new_board in used:
                    used.append(new_board)
                    new_nodes.append(new_board)
                    #print (new_board)
                   
        count += 1
        print (count)
       
        if solution in new_nodes:
            return count
       
        current_nodes = new_nodes
        print(len(current_nodes))
        new_nodes = []
        #print (current_nodes)
	
