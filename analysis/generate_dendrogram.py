from scipy.cluster.hierarchy import dendrogram, linkage
import random
from matplotlib.pyplot import show
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import fcluster
max_d = 14.2


with open("./test_vectors/test_vectors_10.txt", "r") as f:
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
labels_all = []
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


	# if label != "knapsack":
	vectors_all.append(vector_f)
	labels_all.append(label)
	
	

# labels = ["bfs","dfs","bublesort","quicksort","mergesort","heap","linkedlist", "queue","stack","knapsack"]
vectors = []
print(len(bfs_vectors))
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

def augmented_dendrogram(*args, **kwargs):

    ddata = dendrogram(*args, **kwargs)

    if not kwargs.get('no_plot', False):
        for i, d in zip(ddata['icoord'], ddata['dcoord']):
            x = 0.5 * sum(i[1:3])
            y = d[1]
            plt.plot(x, y, 'ro')
            plt.annotate("%.3g" % y, (x, y), xytext=(0, -8),
                         textcoords='offset points',
                         va='top', ha='center')

    return ddata

def fancy_dendrogram(*args, **kwargs):
    max_d = kwargs.pop('max_d', None)
    if max_d and 'color_threshold' not in kwargs:
        kwargs['color_threshold'] = max_d
    annotate_above = kwargs.pop('annotate_above', 0)

    ddata = dendrogram(*args, **kwargs)

    if not kwargs.get('no_plot', False):
        plt.title('Hierarchical Clustering Dendrogram (10 program each class)')
        plt.xlabel('sample index or (cluster size)')
        plt.ylabel('distance')
        for i, d, c in zip(ddata['icoord'], ddata['dcoord'], ddata['color_list']):
            x = 0.5 * sum(i[1:3])
            y = d[1]
            if y > annotate_above:
                plt.plot(x, y, 'o', c=c)
                plt.annotate("%.3g" % y, (x, y), xytext=(0, -5),
                             textcoords='offset points',
                             va='top', ha='center')
        if max_d:
            plt.axhline(y=max_d, c='k')
    return ddata


Z = linkage(vectors_all, "average")
print(Z)

# fancy_dendrogram(Z, labels= labels)
# dendrogram(Z,truncate_mode='lastp',p=12,labels = labels, show_contracted=True)

ddata = fancy_dendrogram(Z,truncate_mode='lastp',labels = labels_all,max_d=max_d)


# Retrieving cluster
clusters = fcluster(Z, max_d, criterion='distance')
print(clusters)
print(len(clusters))

cluster_indexes = [x for x in range(0,11)]
from collections import defaultdict
result = defaultdict(list)
for k, v in zip(clusters, labels_all):
	result[k].append(v)

for k,v in result.items():
	print("---------------------------")
	print("Number of programs : " + str(len(v)))
	print("Cluster %s - %s" % (str(k), str(v)))


show()
