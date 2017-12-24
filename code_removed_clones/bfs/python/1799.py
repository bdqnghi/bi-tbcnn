import sys
import Queue

dd=dict()

def bfs(root, target):
	Q = Queue.Queue()
	V = set()
	Q.put( (root, 0) )
	V.add(root)
	while not Q.empty():
		tp = Q.get()
		if tp[0] == target:
			return tp[1]
		for child in dd[ tp[0] ]:
			if child not in V:
				V.add(child)
				Q.put( (child, tp[1]+1) )
	return -1

k = int( sys.stdin.readline().rstrip().split()[0] )
for line in sys.stdin:
	nums = [int(x) for x in line.rstrip().split()]
	if nums[0] not in dd:
		dd[nums[0]] = []
	dd[nums[0]].append(nums[1])
for i in range(1, k+1):
	if i not in dd:
		dd[i] = []
		
print dd
	
for i in range(1, k+1):
	print bfs(root=1, target=i),