// Animation of a breadth-first-search in an undirected graph
// unvisited part is displayed in yellow (default), completed nodes in blue,
// nodes still being processed are displayed in red (elements of the search queue)
// current node is depicted in green
// edges belonging to search tree are firstly displayed in red, after processing eventually in blue
// backward (additional) edges in green

#include <iostream>
#include <climits>
#include <LEDA/graphics/graphwin.h>
#include <LEDA/graphics/color.h>
#include <LEDA/system/basic.h>
#include <LEDA/core/queue.h>

#include "control.h" // Control window (adjusting speed etc.)

#define WAIT 0.5

#define p(str) ( std::cout << str << std::endl ) // print helper

using leda::graph;
using leda::node;
using leda::edge;
using leda::node_array;
using leda::user_label;
using leda::GraphWin;
using leda::red;
using leda::blue;
using leda::green;
using leda::yellow;
using leda::string;
using leda::queue;
using leda::gw_node_shape;
using leda::rectangle_node;

// iterative function to conduct breadth-first-search (bfs);
// parameters:
//    v: current node
//    g: graph to be searched in (as reference)
//    gw: Diplaying window of graph (as reference)
//    bfsnum: Field for assigning bfs numbers to nodes (as reference)
//    count: current bfs number (as reference)
//    rank: distance to starting node (number of edges) (as reference)
void bfs(node v, graph &g, GraphWin &gw, node_array<int> &bfsnum, int &count, int &rank) {

    queue<node> fifo_queue;    // queue for next bfs node

    fifo_queue.push(v); // add the starting node
    
bfsnum[v] = rank++;                              // Assigning bfs number
gw.set_user_label(v, string("%d (%d)", count, bfsnum[v]));  // Display bfs number
gw.set_color(v, red);                           // Color node in red
gw.redraw();                                  // Update displayed graph
control_wait(WAIT);                              // Wait for 0.5 sec 
count++;


// loop through all queue elements and add all childs to queue
// also add some graphical hints
do {

    v = fifo_queue.pop(); // pop first element of search queue
    gw.set_color(v, green); // current node of queue, mark it green
    control_wait(WAIT); // Wait for 0.5sec

    edge e;
    forall_inout_edges(e, v) {  // all neighbour nodes of v
        node w = g.opposite(v, e); // neighbour node on the other side of edge e
        if (bfsnum[w] < 0) { // if node w has not been visited yet
            bfsnum[w] = bfsnum[v]+1; // assign to current node last assigned bfs number incremented by one
            gw.set_color(e, red);     // color edge in red     
            gw.set_color(w, red);	// color node in red
            gw.set_width(e, 2);           
            gw.set_user_label(w, string("%d (%d)", count++, bfsnum[w])); // display order first, in brackets distance to starting node
                fifo_queue.append(w); // add the child node to the queue
                control_wait(WAIT);             // Wait for 0.5 sec 
            } else {    // if node w has already been visited
                if (bfsnum[w] < bfsnum[v]) { // Backward edge
                    if (gw.get_color(e) == red){ // check, if edge is the connection between parent and child node
			            gw.set_color(e, blue); // color edge in blue
			            gw.set_width(e, 2);
			            control_wait(WAIT); // wait for 0.5 sec
		            }
                } else { // edge to a node in queue
                    gw.set_color(e, green); // color edge 
                    gw.set_width(e, 2);
                    control_wait(WAIT); // wait for 0.5 sec
                }
            }
        }
        gw.set_color(v, blue); // Color node in blue
        control_wait(WAIT); // wait for 0.5 sec
        gw.redraw();
	// Update displayed graph (to ensure correct updation)
    } while (!fifo_queue.empty());  // loop until queue is empty
}

// Main program
int main(int argc, char *argv[]) {
    p("los gehts");
    // Create window for illustrating the graph with size 800 x 600 
    GraphWin gw(800, 600);

    gw.display(); // Display window on the screen
    create_control(); // Display control window
    gw.set_directed(false); // use undirected graph presentation
    if (argc > 1)    // falls Name als Parameter, Graph laden
        gw.read(argv[1]);

    gw.edit();   // switch to edit mode until user presses 'done'

    // jetzt holen wir uns den Graphen, den der Benutzer eingegeben oder geladen hat
    graph &g = gw.get_graph();

    if (g.number_of_nodes() == 0) {  // Ende, wenn der Graph leer ist.
        gw.close(); destroy_control();
        exit(1);
    }

    // Jetzt deklarieren wir ein Feld, das jedem Knoten eine Nummer zuordnet,
    // und initialisieren es mit "-1"
    node_array<int> bfsnum(g, -1);

    // Nun zeigen wir fuer alle Knoten den bfsnum-Wert als User-Label an
    // sowie initialisieren den Graphen gelb.
    node v;
    forall_nodes(v, g) {
        gw.set_label_type(v, user_label);    // User-Label anzeigen (statt Index-Label)
        gw.set_user_label(v, string("%d", bfsnum[v])); // User-Label auf bfsnum[v] setzen
        gw.set_color(v, yellow);
        gw.set_shape(v, rectangle_node);
        gw.set_width(v, 90);
    }
    edge e;
    forall_edges(e, g)
        gw.set_color(e, yellow);

    // in dieser Variable merken wir uns die nächste zu vergebende Nummer
    // (und gleichzeitig die Zahl der schon besuchten Knoten)
    int count = 0;
    int ranks = 0; // hier merken wir uns den abstand zur startnode

    do {
        // jetzt lassen wir den Benutzer mit der Maus einen unbesuchten Knoten
        // auswählen (wenn er danebenklickt, wird NULL zurückgeliefert),
        while ((v = gw.read_node()) == NULL || bfsnum[v] >= 0) ;

        // nun rufen wir die iterative BFS-Funktion auf
        bfs(v, g, gw, bfsnum, count, ranks);
    } while (count < g.number_of_nodes()); // bis alle Knoten besucht wurden

    gw.acknowledge("Ready!"); // Dialogbox anzeigen und bestätigen lassen
    gw.edit(); // nochmal in den Edit-Modus, zum Anschauen :)

    // Aufräumen und Ende
    gw.close();
    destroy_control();
    exit(0);
}
