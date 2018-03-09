# import matplotlib.pyplot as plt
# from numpy.random import random

# colors = ['b', 'c', 'y', 'm', 'r']

# lo = plt.scatter(random(10), random(10), marker='x', color=colors[0])
# ll = plt.scatter(random(10), random(10), marker='o', color=colors[0])
# l  = plt.scatter(random(10), random(10), marker='o', color=colors[1])
# a  = plt.scatter(random(10), random(10), marker='o', color=colors[2])
# h  = plt.scatter(random(10), random(10), marker='o', color=colors[3])
# hh = plt.scatter(random(10), random(10), marker='o', color=colors[4])
# ho = plt.scatter(random(10), random(10), marker='x', color=colors[4])

# plt.legend((lo, ll, l, a, h, hh, ho),
#            ('Low Outlier', 'LoLo', 'Lo', 'Average', 'Hi', 'HiHi', 'High Outlier'),
#            scatterpoints=1,
#            loc='lower left',
#            ncol=3,
#            fontsize=8)

# plt.show()


# import matplotlib.pyplot as plt
# import numpy as np
# import matplotlib.colors as colors
# X = [1,2,3,4,5,6,7]
# Y = [1,2,3,4,5,6,7]
# label = [0,1,4,2,3,1,1]

# # Define a colormap with the right number of colors
# cmap = plt.cm.get_cmap('jet',max(label)-min(label)+1)

# bounds = range(min(label),max(label)+2)

# print bounds
# norm = colors.BoundaryNorm(bounds, cmap.N)

# plt.scatter(X, Y, c= label, s=50, cmap=cmap, norm=norm)

# # Add a colorbar. Move the ticks up by 0.5, so they are centred on the colour.
# cb=plt.colorbar(ticks=np.array(label)+0.5)
# cb.set_ticklabels(label)

# plt.show()

# import matplotlib.pyplot as plt
# import numpy as np

# # Generate some data
# x, y, z = np.random.random((3, 30))
# z = z * 20 + 0.1

# # Set some values in z to 0...
# z[:5] = 0

# cmap = plt.get_cmap('jet', 20)
# cmap.set_under('gray')

# fig, ax = plt.subplots()
# cax = ax.scatter(x, y, c=z, s=100, cmap=cmap, vmin=0.1, vmax=z.max())
# fig.colorbar(cax, extend='min')

# plt.show()

import matplotlib.pyplot as plt

x=[1,2,3,4]
y=[5,6,7,8]
classes = [2,4,4,2]
unique = list(set(classes))
colors = [plt.cm.jet(float(i)/max(unique)) for i in unique]
print colors
for i, u in enumerate(unique):
    xi = [x[j] for j  in range(len(x)) if classes[j] == u]
    yi = [y[j] for j  in range(len(x)) if classes[j] == u]
    print colors[i]
    plt.scatter(xi, yi, c=colors[i], label=str(u))
plt.legend()

plt.show()