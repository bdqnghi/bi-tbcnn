import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class BFS {
    
    private boolean[] marked;
    private int[] edgeTo;
    private int[] distTo;
    private int goal=-1;
    
    int source=0;
    String[] destinations;
    String[] nodes;
    int startTime;
    Bag<Pipe>[] adj;
    
    public BFS(String[] nodes, String[] destinations, int startTime, Pipe[] pipes){
        marked=new boolean[nodes.length];
        edgeTo=new int[nodes.length];
        distTo=new int[nodes.length];
        
        this.nodes=new String[nodes.length];
        for(int i=0;i<nodes.length;i++){
            this.nodes[i]=nodes[i];
        }
        
        this.destinations=new String[destinations.length];
        for(int i=0;i<destinations.length;i++){
            this.destinations[i]=destinations[i];
        }
        
        this.startTime=startTime;
        
        this.adj=(Bag<Pipe>[])new Bag[nodes.length];
        for(int i=0;i<nodes.length;i++)
            this.adj[i]=new Bag<Pipe>();

        for(int p=0;p<pipes.length;p++){
            adj[(int)Arrays.asList(nodes).indexOf(pipes[p].from().toString())].add(pipes[p]);
        }

        for(int i=0;i<nodes.length;i++){
            distTo[i]=Integer.MAX_VALUE;
        }        
    }
    
    public String bfs(){
        
        Queue<Integer> queue=new ArrayDeque<Integer>();
        marked[source]=true;
        edgeTo[source]=-1;
        distTo[source]=startTime;
        queue.add(source);
        
        while(!queue.isEmpty()){
            int from=queue.remove();
            
            //Check if goal reached               
            if(Arrays.asList(destinations).contains(nodes[from])){
                goal=from;
                break;
            }
            for(Pipe p : adj[from]){
                int to=(int)Arrays.asList(nodes).indexOf(p.to().toString());
                if(!marked[to]){
                    edgeTo[to]=from;
                    distTo[to]=distTo[from]+1;
                    marked[to]=true;
                    
                    queue.add(to);
                }
            }
        }
        
        if(goal==-1){
            return "None";
        }
        else{
            return nodes[goal].toString()+" "+(distTo[goal]%24);
        } 
    }
}