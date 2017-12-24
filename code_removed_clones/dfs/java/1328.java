public class DFS {
    static int time;

    enum Color {
        WHITE,
        GRAY,
        BLACK
    }

    public static void main(String[] args) {
        int [][] graph=new int[][]{
                {0,1,0,1,0,0},
                {0,0,0,0,1,0},
                {0,0,0,0,1,1},
                {0,1,0,0,0,0},
                {0,0,0,1,0,0},
                {0,0,0,0,0,1}
        };
        DFS(graph);
    }
    static void DFS(int[][] G){
        Node[] nodes=new Node[G.length];
        for(int i=0;i<G.length;i++){
            nodes[i]=new Node(Color.WHITE);
        }
        time=0;
        for(int i=0;i<G.length;i++){
            if(nodes[i].getColor().equals(Color.WHITE)){
                DFSVisit(G,i,nodes);
            }
        }
        for(int i=0;i<nodes.length;i++) {
            System.out.printf("%d - discovery : %d  finish : %d\n",i,nodes[i].getDiscovery(),nodes[i].getFinish());
        }
    }

    static void DFSVisit(int[][]  G, int u,Node[] nodes){
        time++;
        nodes[u].setDiscovery(time);
        nodes[u].setColor(Color.GRAY);
        for(int v=0;v<G[u].length;v++){
            if(G[u][v]==1){
                if(nodes[v].getColor().equals(Color.WHITE)){
                    nodes[v].setParentNode(nodes[u]);
                    DFSVisit(G,v,nodes);
                }
            }
        }
        nodes[u].setColor(Color.BLACK);
        time++;
        nodes[u].setFinish(time);
    }
    static class Node {
        private Color color;
        private int discovery;
        private int finish;
        private Node parentNode;

        public Node(Color color) {
            this.color = color;
        }

        public Color getColor() {
            return color;
        }

        public void setColor(Color color) {
            this.color = color;
        }

        public int getDiscovery() {
            return discovery;
        }

        public void setDiscovery(int discovery) {
            this.discovery = discovery;
        }

        public int getFinish() {
            return finish;
        }

        public void setFinish(int finish) {
            this.finish = finish;
        }

        public Node getParentNode() {
            return parentNode;
        }

        public void setParentNode(Node parentNode) {
            this.parentNode = parentNode;
        }
    }
}
