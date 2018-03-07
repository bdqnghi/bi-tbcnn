from scipy.cluster.hierarchy import dendrogram, linkage
import random
from matplotlib.pyplot import show

with open("./test_vectors/test_vectors.txt", "r") as f:
	data = f.readlines()

labels = []

bubblesort_vectors = []
mergesort_vectors = []
quicksort_vectors = []
linkedlist_vectors = []
queue_vectors = []
stack_vectors = []
heap_vectors = []
bfs_vectors = []
dfs_vectors = []
knapsack_vectors = []
vectors_all = []
for line in data:
	l = line.replace("\n","").strip()
	splits = l.split(" ")
	label = splits[0]
	vector = splits[1:len(splits)]
	vector_f = [float(i) for i in vector]

	# labels.append(label)
	if label == "bfs":
		bfs_vectors.append(vector_f)
	if label == "dfs":
		dfs_vectors.append(vector_f)
	if label == "bubblesort":
		bubblesort_vectors.append(vector_f)
	if label == "quicksort":
		quicksort_vectors.append(vector_f)
	if label == "mergesort":
		mergesort_vectors.append(vector_f)
	if label == "heap":
		heap_vectors.append(vector_f)
	if label == "linkedlist":
		linkedlist_vectors.append(vector_f)
	if label == "queue":
		queue_vectors.append(vector_f)
	if label == "stack":
		stack_vectors.append(vector_f)
	if label == "knapsack":
		knapsack_vectors.append(vector_f)

	vectors_all.append(vector_f)
	
	

# labels = ["bfs","dfs","bublesort","quicksort","mergesort","heap","linkedlist", "queue","stack","knapsack"]
vectors = []
print len(bfs_vectors)
# vectors.append(random.choice(bfs_vectors))
# vectors.append(random.choice(dfs_vectors))
# vectors.append(random.choice(bubblesort_vectors))
# vectors.append(random.choice(quicksort_vectors))
# vectors.append(random.choice(mergesort_vectors))
# vectors.append(random.choice(heap_vectors))
# vectors.append(random.choice(linkedlist_vectors))
# vectors.append(random.choice(queue_vectors))
# vectors.append(random.choice(stack_vectors))
# vectors.append(random.choice(knapsack_vectors))

samples = 10
vectors.extend(random.sample(bfs_vectors,samples))
vectors.extend(random.sample(dfs_vectors,samples))
vectors.extend(random.sample(bubblesort_vectors,samples))
vectors.extend(random.sample(quicksort_vectors,samples))
vectors.extend(random.sample(mergesort_vectors,samples))
vectors.extend(random.sample(heap_vectors,samples))
vectors.extend(random.sample(linkedlist_vectors,samples))
vectors.extend(random.sample(queue_vectors,samples))
vectors.extend(random.sample(stack_vectors,samples))
vectors.extend(random.sample(knapsack_vectors,samples))



labels.extend(["bfs" for i in range(0,samples)])
labels.extend(["dfs" for i in range(0,samples)])
labels.extend(["bublesort" for i in range(0,samples)])
labels.extend(["quicksort" for i in range(0,samples)])
labels.extend(["mergesort" for i in range(0,samples)])
labels.extend(["heap" for i in range(0,samples)])
labels.extend(["linkedlist" for i in range(0,samples)])
labels.extend(["queue" for i in range(0,samples)])
labels.extend(["stack" for i in range(0,samples)])
labels.extend(["knapsack" for i in range(0,samples)])

# print vectors

Z = linkage(vectors, "ward")
# dendrogram(Z, labels= labels)
dendrogram(Z,labels = labels, show_contracted=True)
show()
