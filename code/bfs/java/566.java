package TP2;
import TP1.*;
import TP1.List;

import java.util.*;
 

public class BFS {
	
	public static LinkedList<Vertex> bfs(GrapheLis g, Vertex source){
		Queue<Vertex> f= new LinkedList<Vertex>();
		Queue<Vertex> f2= new LinkedList<Vertex>();
		boolean[] colored= new boolean[g.succ.length];
		colored[source.getId()]=true;
		f.add(source);
		f2.add(source);
		while(!f.isEmpty()){
			Vertex v=f.poll();
			for(List ls=g.succ[v.getId()];ls!=null;ls=ls.suivant){
Vertex w=ls.val;
				if(!colored[w.getId()]){
					colored[w.getId()]=true;
					((LinkedList<Vertex>) f2).push(w);
					((LinkedList<Vertex>) f).push(w);
					
				}
			}}
			return (LinkedList<Vertex>) f2;
	}
	/*Une m�thode pour montrer au console les sommets parcouris en ordre lorsque de la BFS
	 * Cette m�thode fais appel au premiere m�thode tout simplement et cast les listes chain�es en 
	 * String modifiable puis en string static .
	 */
		 static void showBFS(GrapheLis g,Vertex source){
			    LinkedList<Vertex> f2=bfs(g,source);
			    StringBuilder sb=new StringBuilder("");
			    sb.append("LinkedList<Vertex > de BFS "+source.ToString() +" <" );
				   for(int i=0;i<f2.size();i++){
					   Vertex v=f2.get(i);
					   sb.append(""+v.ToString()+" ->");				  
					  
				   }
				   sb.append("Fin >");
		System.out.println(sb.toString());	   
		 }
	 
		/*
		 * Le calcul de plus cours chemins repose sur l'ajoute de deux tableaux le premier pour 
		 * stocker les distances au sommets et le deuxi�me les parents d'un sommet pour trouver facilement 
		 * le courts chemins.
		 */
		
	
	
	
	public static void bfs_CChemin(GrapheLis g, Vertex source){
		Queue<Vertex> f= new LinkedList<Vertex>();
		boolean[] colored= new boolean[g.succ.length];
		int[] dist=new int[g.succ.length];
		 for(int i:dist ) i=-1;
		int[] parents=new int[g.succ.length];
		 for (int v:parents) v=-1;
		 dist[source.getId()]=0;
		colored[source.getId()]=true;
		f.add(source);
		while(!f.isEmpty()){
			Vertex v=f.poll();
			for(List ls=g.succ[v.getId()];ls!=null;ls=ls.suivant){
				Vertex w=ls.val;
				if(!colored[w.getId()]){
					colored[w.getId()]=true;
					dist[w.getId()]++;
					parents[w.getId()]=v.getId();
					((LinkedList<Vertex>) f).push(w);
					
				}
			}
		}

		System.out.println("Dist"+Arrays.toString(dist));
		System.out.println("Parents"+Arrays.toString(parents));
}
}