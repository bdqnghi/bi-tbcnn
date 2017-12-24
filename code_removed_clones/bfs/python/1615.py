# 130. Surrounded Regions My Submissions Question
# Total Accepted: 46767 Total Submissions: 298769 Difficulty: Medium
# Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
# A region is captured by flipping all 'O's into 'X's in that surrounded region.
# For example,
# X X X X
# X O O X
# X X O X
# X O X X
# After running your function, the board should be:
# X X X X
# X X X X
# X X X X
# X O X X


# class Solution(object):
# 	'''this code transfer the O to Y when qualified, in this way to speed up'''
# '''use a big queue, not each row queue, and put index first, with different method to get neighours, should be faster'''
# 	def solve(self, board):
# 		"""
# 		:type board: List[List[str]]
# 		:rtype: void Do not return anything, modify board in-place instead.
# 		"""
# 		m,n = self.get_board_size(board)
# 		if m == 0 or n == 0:
# 			return 
# 		#check the 1 and last rows, with 1 and last cols, and save all the O s; and then flip all the other 'X'	

# 		#make dictionary, checking dict, and make value as 0 if not checking.
# 		idx_dct = dict(zip([(i,j) for i in range(m) for j in range(n)],[0]*m*n))
		
# 		total_queue = [] + [(0,i) for i in range(n)] + [(m-1,i) for i in range(n)] + [(j,0) for j in range(1,m-1)]+ [(j,n-1) for j in range(1,m-1)]
		
# 		while len(total_queue) > 0:
# 			idx = total_queue[0]
# 			if board[idx[0]][idx[1]] == 'O':
# 				self.bfs(idx, board, idx_dct,total_queue)
# 			total_queue.pop(0)
						
# 		for i in range(0,m):
# 			for j in range(0,n):
# 				if board[i][j] == 'O':
# 					board[i][j] = 'X'
# 				elif board[i][j] == 'Y':	
# 					board[i][j] = 'O'
# 				else:
# 					pass
				
# 	def get_board_size(self, board):
# 		#m is the # of rows
# 		m = len(board)
# 		if m == 0:
# 			n = 0
# 			return m,n
# 		#n is the # of cols
# 		n = len(board[0])
# 		return m,n
	

# 	def bfs(self, idx, board, idx_dct,total_queue):
# 		'''if the idx has O on the bound, then search through it, to find all the Os next to it as a region, change them to Y'''
# 		queue = [idx]
# 		while len(queue) >0:
# 			cur = queue[0]
# 			board[cur[0]][cur[1]] = 'Y'
# 			neight_idx = self.get_neight(cur[0],cur[1])
# 			for ele in neight_idx:
# 				if ele in idx_dct and board[ele[0]][ele[1]] == 'O':
# 					queue.append(ele)
# 					board[ele[0]][ele[1]] = 'Y'
# 					# if ele in total_queue:
# 					# 	total_queue.remove(ele)
# 			queue.pop(0)



# 	def get_neight(self, i,j):
# 		return [(i-1,j), (i+1,j),(i,j-1),(i,j+1)]

#a more short and clear way to do it:
# Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
# A region is captured by flipping all 'O's into 'X's in that surrounded region.
# For example,
# X X X X
# X O O X
# X X O X
# X O X X
# After running your function, the board should be:
# X X X X
# X X X X
# X X X X
# X O X X
# class Solution(object):
# 	'''this code transfer the O to Y when qualified, in this way to speed up'''
# 	def solve(self, board):
# 		"""
# 		:type board: List[List[str]]
# 		:rtype: void Do not return anything, modify board in-place instead.
# 		"""
# 		m = len(board)
# 		if m==0: return
# 		n = len(board[0])
# 		if n==0: return
# 		#bfs, using queue
# 		#initialize
# 		queue = []
# 		for i in range(n): queue = queue + [(i,0), (i,m-1)]
# 		for j in range(1,m-1): queue = queue + [(0,j), (n-1,j)]
		
# 		while queue:
# 		    curIdx = queue.pop(0)
# 		    if board[curIdx[1]][curIdx[0]] == 'O':
# 		        board[curIdx[1]][curIdx[0]] = 'Y'
# 		        curNei = self.get_neigh(curIdx[0], curIdx[1], n, m)
# 		        #each loop, only process the current index: change it to Y, and add its neigh to queue
# 		        for item in curNei:
# 		            if board[item[1]][item[0]] == 'O': queue.append(item)
# 		    else: 
# 		        continue
			
# 		for i in range(m):
# 		    for j in range(n):
# 		        if board[i][j] == 'Y': board[i][j] = 'O'
# 		        else: board[i][j] = 'X'
		
# 	def get_neigh(self, x,y,n,m):
# 	    res = []
# 	    if x-1>=0: res.append((x-1,y))
# 	    if x+1<=n-1: res.append((x+1,y))
# 	    if y-1>=0: res.append((x,y-1))
# 	    if y+1<=m-1: res.append((x,y+1))
# 	    return res
	

# 127. Word Ladder My Submissions Question
# Total Accepted: 65673 Total Submissions: 335577 Difficulty: Medium
# Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

# Only one letter can be changed at a time
# Each intermediate word must exist in the word list
# For example,

# Given:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
# As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
# return its length 5.

# Note:
# Return 0 if there is no such transformation sequence.
# All words have the same length.
# All words contain only lowercase alphabetic characters.



# class Solution(object):
# 	def ladderLength(self, beginWord, endWord, wordList):
# 		"""
# 		:type beginWord: str
# 		:type endWord: str
# 		:type wordList: Set[str]
# 		:rtype: int
# 		"""
# 		#bfs:queue, dict and tree
# 		#to record the level/path, just add the step after the word state, that is it
# 		wordList.add(endWord)
# # 		dct = dict(zip(wordList, [1]*len(wordList)))        
# 		queue = [(beginWord,1)]
# 		n=len(endWord)
# 		letters = 'abcdefghijklmnopqrstuvwxyz'
# 		while queue:
# 			cur = queue.pop(0)
# 			curword, curlevel = cur[0], cur[1]
# 			if curword == endWord: return curlevel 
# 			for i in range(n):
# 				for letter in letters:
# 					new = curword[:i] + letter + curword[i+1:]
# 					if new in wordList:
# 						queue.append((new, curlevel+1))
# 				# 		dct.pop(new)
# 						wordList.remove(new)
# 		return 0



# class Solution(object):
# 	def ladderLength(self, beginWord, endWord, wordList):
# 		"""
# 		:type beginWord: str
# 		:type endWord: str
# 		:type wordList: Set[str]
# 		:rtype: int
# 		"""
# 		wordList.add(endWord)
# 		wordList.discard(beginWord)
# 		queue = [(beginWord, 1)]
# 		letters = 'abcdefghijklmnopqrstuvwxyz'
# 		assert len(letters)==26, 'number of letters wrong'
# 		n= len(beginWord)
		
# 		while queue:
# 			curWord, curLen = queue.pop(0)
# 			if curWord == endWord: return curLen
			
# 			for i in range(n):
# 				for letter in letters:
# 					newWord = curWord[0:i] + letter + curWord[i+1:]
# 					if newWord in wordList: 
# 						#in pricinple, only add elements to queue beygond the current element
# 						#but sometimes we can do some extra work to reduce computation complexity
# 						queue.append((newWord, curLen+1))
# 						wordList.remove(newWord)
# 			#the following works, but with more computation compared to the above line			
# 			# wordList.discard(curWord)
# 		return 0		                
					
				
			
# 126. Word Ladder II My Submissions Question
# Total Accepted: 38549 Total Submissions: 285578 Difficulty: Hard
# Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

# Only one letter can be changed at a time
# Each intermediate word must exist in the word list
# For example,
# Given:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
# Return
#   [
#     ["hit","hot","dot","dog","cog"],
#     ["hit","hot","lot","log","cog"]
#   ]
# Note:
# All words have the same length.
# All words contain only lowercase alphabetic characters.
# class parentNode(object):
# 	def __init__(self,word):
# 		self.val = word
# 		self.parent = None


# class Solution(object):
# 	def findLadders(self, beginWord, endWord, wordlist):
# 		"""
# 		:type beginWord: str
# 		:type endWord: str
# 		:type wordlist: Set[str]
# 		:rtype: List[List[int]]
# 		"""
# 		wordlist.add(endWord)
# 		wordlist.discard(beginWord)
# 		n=len(endWord)
# 		letters = 'abcdefghijklmnopqrstuvwxyz'

# 		queue = [(beginWord, parentNode(beginWord))]
# 		resNodes = []
# 		nextqueue=[]
# 		while queue:
# 			cur = queue.pop(0)
# 			curword, curNode = cur[0], cur[1]
# 			if curword == endWord:
# 				resNodes.append(curNode)
# 				while queue:
# 					next = queue.pop(0)
# 					nextword, nextNode = next[0],next[1]
# 					if nextword == endWord:
# 						resNodes.append(nextNode)
# 				break
# 			for i in range(n):
# 				for letter in letters:
# 					new = curword[:i] + letter + curword[i+1:]
# 					newNode = parentNode(new)
# 					newNode.parent = curNode
# 					# if using the following code, there might be a bug in some data, so 
# 					#make two queue, and remove all the previous queue word
# 					# if new in wordlist and (curNode.parent is None or new != curNode.parent.val):
# 					if new in wordlist:							
# 						nextqueue.append((new, newNode))
# 			#when the current queue be 0, mean all this level words have been processed					
# 			if not queue:
# 				#the following 3 lines are very important
# 				#because otherwise, there will be non-ending loop if there is no path
# 				#it will add up two alternative words such as lot and log alternatively forever
# 				for item in nextqueue:
# 					if item[0] in wordlist:
# 						wordlist.remove(item[0])
# 				queue = nextqueue
# 				nextqueue=[]			

# 		res=[]
# 		for node in resNodes:
# 			each_res=[]
# 			while node:
# 				each_res.insert(0, node.val)
# 				node= node.parent
# 			res.append(each_res)				
# 		return res

# if __name__ == '__main__':
# 	sk = Solution()
# 	print sk.findLadders('hit','kkk',set(["hot","dot","dog","lot","log"]))
# 	# print sk.findLadders('hot','dog',set(["hot","dog"]))




# class Node(object):
# 	def __init__(self, word):
# 		self.val =  word
# 		self.parent = None
		
# class Solution(object):
# 	def findLadders(self, beginWord, endWord, wordlist):
# 		"""
# 		:type beginWord: str
# 		:type endWord: str
# 		:type wordlist: Set[str]
# 		:rtype: List[List[int]]
# 		"""
# 		wordList = wordlist
# 		wordList.discard(beginWord)
# 		wordList.add(endWord)
# 		letters = letters = 'abcdefghijklmnopqrstuvwxyz'
# 		n = len(beginWord)
# 		resNodeList = []
# 		queue = [Node(beginWord)]
		
# 		newQueue = []
# 		newWordList = set([])
# 		while queue:
# 			curNode = queue.pop(0)
# 			curWord = curNode.val
# 			if curWord == endWord:
# 				resNodeList.append(curNode)
# 				while queue:
# 					curNode = queue.pop(0)
# 					if curNode.val == endWord: resNodeList.append(curNode)
# 				break 
			
			
# 			for i in range(n):
# 				for letter in letters:
# 					newWord = curWord[0:i]+letter+curWord[i+1:]
# 					if newWord in wordList:
# 						newNode = Node(newWord)
# 						newNode.parent = curNode
# 						newWordList.add(newWord)
# 						newQueue.append(newNode)
			
			
# 			if not queue:
# 				for newWord in newWordList: wordList.remove(newWord)
# 				queue = newQueue
# 				newQueue = []
# 				newWordList = set([])
		
# 		res = []
# 		for node in resNodeList:
# 			eachRes = []
# 			while node:
# 				eachRes.append(node.val)
# 				node = node.parent
# 			res.append(eachRes[::-1])
# 		return res



# ##this one will pass the time limit; above code mainly because of the space complexity to fail the test??
# class Solution(object):
# 	def findLadders(self, beginWord, endWord, wordlist):
# 		"""
# 		:type beginWord: str
# 		:type endWord: str
# 		:type wordlist: Set[str]
# 		:rtype: List[List[int]]
# 		"""

# 		wordList = wordlist
# 		wordList.discard(beginWord)
# 		wordList.add(endWord)
# 		letters = letters = 'abcdefghijklmnopqrstuvwxyz'
# 		n = len(beginWord)
# 		resNodeList = []
# 		queue = [Node(beginWord)]
		
# 		newQueue = []
# 		newWordList = set([])
# 		while queue:
# 			curNode = queue.pop(0)
# 			curWord = curNode.val
# 			if curWord == endWord:
# 				resNodeList.append(curNode)
# 				while queue:
# 					curNode = queue.pop(0)
# 					if curNode.val == endWord: resNodeList.append(curNode)
# 				break 
			
			
# 			for i in range(n):
# 				for letter in letters:
# 					newWord = curWord[0:i]+letter+curWord[i+1:]
# 					if newWord in wordList:
# 						newNode = Node(newWord)
# 						newNode.parent = curNode
# 						newWordList.add(newWord)
# 						newQueue.append(newNode)
			
			
# 			if not queue:
# 				for newWord in newWordList: wordList.remove(newWord)
# 				queue = newQueue
# 				newQueue = []
# 				newWordList = set([])
		
# 		res = []
# 		for node in resNodeList:
# 			eachRes = []
# 			while node:
# 				eachRes.append(node.val)
# 				node = node.parent
# 			res.append(eachRes[::-1])
# 		return res
						

#the following finally pass the time limit: the point is to reduce the matched pairs
class Solution(object):
	def findLadders(self, beginWord, endWord, wordlist):
		"""
		:type beginWord: str
		:type endWord: str
		:type wordlist: Set[str]
		:rtype: List[List[int]]
		"""
		wordlist.add(endWord)
		wordlist.discard(beginWord)
		n=len(endWord)
		letters = 'abcdefghijklmnopqrstuvwxyz'
		pathDict = {}
		
		queue = [beginWord]
		nextqueue=[]
		haveRes = None
		preSet = set([beginWord])
		while queue:
			curWord = queue.pop(0)
			pathDict[curWord] = []
			if curWord == endWord:
				# while queue:
				# 	curWord = queue.pop(0)
				# 	pathDict[curWord] = []
				haveRes = True
				break
				
			for i in range(n):
				for letter in letters:
					newWord = curWord[:i] + letter + curWord[i+1:]
					if newWord in wordlist and newWord not in preSet:
						pathDict[curWord].append(newWord)
						nextqueue.append(newWord)
			
			if not queue:
				nextqueue = list(set(nextqueue))
				#remove from wordlist, and add them into preSet
				for item in nextqueue:
					wordlist.remove(item)
					preSet.add(item)
				queue = nextqueue
				nextqueue=[]			
		
		res= []
		# print pathDict
		if haveRes:
			res = self.pathConstruct(pathDict, beginWord, endWord)
		return res
	
	def pathConstruct(self, dct, begin, end):
		if begin == end: return [[begin]]
		res = []
		if begin in dct:
			for word in dct[begin]:
				for seq in self.pathConstruct(dct, word, end):
					seq.insert(0, begin)
					res.append(seq)
		return res

if __name__ == '__main__':
	sk = Solution()
	print sk.findLadders('a','c',set(['a','b','c']))
	print sk.findLadders('hit','cog',set(["hot","dot","dog","lot","log"]))
	# print sk.findLadders('hot','dog',set(["hot","dog"]))
