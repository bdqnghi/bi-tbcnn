import java.util.*;
class graph{
String name;
String color;
int dis;
graph an;
List<graph> list = new ArrayList<graph>();
}

public class bfs{
public static void main(String arg[]){
Scanner in=new Scanner(System.in);
System.out.println("enter the number of node in graph");
int n=in.nextInt();
graph g[]=new graph[n];
for(int i=0;i<n;i++){
g[i]=new graph();
g[i].name=in.next();
g[i].color="white";
g[i].dis=0;
g[i].an=null;

}
for(int i=0;i<n;i++){
System.out.println("enter adj node number "+g[i].name+" ");
int l=in.nextInt();

for(int j=0;j<l;j++){
int k=in.nextInt();
g[i].list.add(g[k]);
}}
Queue queue = new LinkedList();
queue.add(g[0]);
while(!queue.isEmpty()){
	graph node=(graph)queue.remove();
	Iterator<graph> iterator = node.list.iterator();
		while(iterator.hasNext()){
  		  graph obj = iterator.next();
    			if(obj.color=="white"){
			obj.color="gray";
			obj.dis=node.dis+1;
			obj.an=node;
			queue.add(obj);
			}

		}

	node.color="black";
	}

for(int i=0;i<n;i++){
	if(i==0){
		System.out.println(g[i].name+" "+g[i].color+" "+g[i].dis+" ");//root node dont have perent node so 
	}else{
		System.out.println(g[i].name+" "+g[i].color+" "+g[i].dis+" "+g[i].an.name);
	}

}


}}
/*
input from corman page no 596 3rd edition
8
s
r
w
v
t
x
y
u
2 1 2
2 3 0
3 0 4 5
1 1
3 2 5 7
4 2 4 7 6
2 5 7
3 4 5 7


*/
