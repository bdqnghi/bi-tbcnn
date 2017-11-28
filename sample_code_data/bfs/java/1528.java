/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datastructures.graphs.bfs;

import datastructures.queues.LinkedListQueue;
import datastructures.queues.Queue;

/**
 *
 * @author Denny Oommen Mathew <denny@dennymathew.com>
 */
public class BFS<Item> {
    
    private Vertex<Item> root;
    
    public void traverse() {
        Queue<Vertex<Item>> vertices = new LinkedListQueue();
        root.setVisted(true);
        vertices.add(root);

        while( !vertices.isEmpty() ) {
           Vertex<Item> currentVertex = vertices.remove();
           System.out.println(currentVertex);

           for(Vertex<Item> v : currentVertex.getNeighbourVertices()) {
               if(!v.isVisted()) {
                   v.setVisted(true);
                   vertices.add(v);
               }
           }
        }
    }
     
     public BFS(Vertex<Item> root) {
         this.root = root;
     }
    
}
