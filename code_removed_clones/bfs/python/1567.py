from graph_class import UnweightedUndirectedGraph
import matplotlib.pyplot as plt
from collections import deque
import time


class search_BFS:


    def __init__(self, node_start, node_goal, graph, delay):
        """
        Constructor.

        :param node_start: start node
        :param node_goal: goal node to search for

        :param graph: a Graph
        :type graph: UnweightedUndirectedGraph
        """

        self.G = graph                   # the graph
        self.visited = set()             # the set of already visited nodes
        self.queue = deque()             # the queue of the nodes to be processed next
        self.start = node_start          # the start node
        self.goal = node_goal            # the goal node
        self.queue.append(self.start)    # append the start node to the queue to start off
        self.delay = delay               # delay settings

        # plotting
        self.f, self.axarr = plt.subplots(1, 1, sharex=False, sharey=False)


    def run_algorithm(self):
        """
        The interesting part. Whole algorithm.
        """

        # iterate over the queue
        while len(self.queue) > 0:  # ... as long as it is not empty

            # set the current node
            current_node = self.queue.popleft()  # ... and delete it out of the queue

            # update the set of visited node
            self.visited.add(current_node)

            # PLOTTING | label the current robot's position for plotting purposes
            self._label_current_robot_position(current_node)

            # get the neighbors of the current node
            neighbors = self.G.get_neighbors(current_node)  # ... getter method of UnweightedUndirectedGraph class

            # goal condition
            if current_node == self.goal or self.goal in neighbors:
                # goal handler -> return true or something else because goal is found

                # PLOTTING | update the plot a last time
                self._plot(current_node)

                # stop the loop
                break

            # iterate over the neighbors
            while len(neighbors) > 0:  # ... as long as the neighbors list is not empty

                # get the first neighbor out of the deque
                neighbor = neighbors.popleft()  # ... and delete it in the deque

                # check if the neighbor already is in the queue or is already visited
                if neighbor not in self.queue and neighbor not in self.visited:

                    # insert the neighbor into the queue (at the end)
                    self.queue.append(neighbor)

                    # PLOTTING | update neighbor labels
                    self._label_neighbor(neighbor)

            # PLOTTING | plot, delay, labels, ...
            self._delay_plot_label_step(current_node)

        # PLOTTING | pause the animation - leave the window open until user exit
        plt.show(block=True)


    def _label_neighbor(self, neighbor):
        """
        Only for label updates of neighbors
        """
        if self.G.get_label(neighbor) not in ["g", "s", "x", "v", "r"]:
            self.G.set_label(neighbor, "q")


    def _label_current_robot_position(self, current_node):
        """
        Only for label updates of the robots position
        """
        if self.G.get_label(current_node) not in ["g", "s"]:
                self.G.set_label(current_node, "r")


    def _delay_plot_label_step(self, current_node):
        """
        Only for delay settings, plotting and label updates
        """

        # delay settings
        if self.delay == "0":
            bla = raw_input("press any key to continue...")
        elif self.delay == "1":
            time.sleep(1.0)
        elif self.delay == "2":
            time.sleep(0.5)

        # plotting
        self._plot(current_node)

        # label current robot node to visited so that a new node can become the robot's position
        if self.G.get_label(current_node) not in ["g", "s"]:
            self.G.set_label(current_node, "v")


    def _plot(self, current_node):
        """
        Only for visualization.

        :param current_node:
        :return:
        """
        self.axarr.clear()
        self.axarr.set_title("Breadth-First-Search")
        self.axarr.imshow(self.G.get_representations_array(), interpolation = "none")

        plt.xticks(range(0, self.G.get_representation_dimensions()[1]))
        plt.yticks(range(0, self.G.get_representation_dimensions()[0]))

        queue = list(self.queue)

        line1 = "Robot position: {}".format(current_node)
        line2 = "Queue nodes (first 6) : {}".format(queue[0:6])
        line3 = "Queue nodes (last 6)  : {}".format(queue[-6:])

        plot_text = "{}\n{}\n{}".format(line1, line2, line3)
        plt.text(0.0, self.G.get_representation_dimensions()[0] + 1.0,
                 plot_text, size=12, horizontalalignment='left', verticalalignment='top')

        plt.draw()
        plt.pause(0.01)

