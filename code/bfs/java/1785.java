/**
 * 
 */
package org.shaastra.automania;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import org.shaastra.automania.*;

/**
 *
 */
public class Bfs {
	List<Position> traverser_posn = new ArrayList<Position>();
	List<Position> nitro_posn = new ArrayList<Position>();
	List<Integer> traverser_move = new ArrayList<Integer>();
	List<Integer> nitro_move = new ArrayList<Integer>();
	List<Integer> traverser_distance = new ArrayList<Integer>();
	List<Integer> nitro_distance = new ArrayList<Integer>();
	
	public void compute(Map map, Position my_posn) {
		// TODO Auto-generated method stub
		Queue <Node> Q = new LinkedList <Node>();		

		Position temp_posn;
		int[][] visited;
		visited = new int[(GlobalDataStore.MAX_X)+2][(GlobalDataStore.MAX_Y)+2];

		int i = 0, j = 0;
		for(i = 0; i < GlobalDataStore.MAX_X + 2; i++)
		{
			for(j = 0; j < GlobalDataStore.MAX_Y + 2; j++)
			{
				visited[i][j] = 0;
			}
		}
		//initial pushes
		visited[my_posn.x][my_posn.y] = 1;;

		temp_posn = my_posn;
		temp_posn.update( GlobalDataStore.EAST );
		if( map.moveable_position( temp_posn) != 0 ) 
		{
			Node n = new Node(temp_posn,GlobalDataStore.EAST,1);
			Q.add(n);
		}

		temp_posn = my_posn;
		temp_posn.update( GlobalDataStore.WEST );
		if( map.moveable_position( temp_posn) != 0 )
		{
			Node n = new Node(temp_posn,GlobalDataStore.WEST,1);
			Q.add(n);
		}

		temp_posn = my_posn;
		temp_posn.update( GlobalDataStore.NORTH );
		if( map.moveable_position( temp_posn) != 0 )
		{
			Node n = new Node(temp_posn,GlobalDataStore.NORTH,1);
			Q.add(n);
		}

		temp_posn = my_posn;
		temp_posn.update( GlobalDataStore.SOUTH );
		if( map.moveable_position( temp_posn) != 0)
		{
			Node n = new Node(temp_posn,GlobalDataStore.SOUTH,1);
			Q.add(n);
		}
		
		//The main loop

		while( !Q.isEmpty())
		{
			Node n = Q.remove();
			visited[n.cur_posn.x][n.cur_posn.y] = 1;
			if(visited[n.cur_posn.x][n.cur_posn.y] != 0)
			{
				continue;
			}
			

			if( map.get_symbol( n.cur_posn ) == GlobalDataStore.TRAVERSER)
			{
				traverser_posn.add(n.cur_posn);
				traverser_move.add(n.initial_move);
	            traverser_distance.add(n.distance);
			}

			if( map.get_symbol( n.cur_posn ) == GlobalDataStore.NITRO )
			{
				nitro_posn.add(n.cur_posn);
				nitro_move.add(n.initial_move);
	            nitro_distance.add(n.distance);
			}
			
			temp_posn.x = n.cur_posn.x;
			temp_posn.y = n.cur_posn.y;
			temp_posn.update( GlobalDataStore.EAST );
			if( map.moveable_position( temp_posn) != 0 )
			{
				if(visited[temp_posn.x][temp_posn.y] == 0 )
				{
					Node n2 = new Node(temp_posn,n.initial_move,n.distance+1);
					Q.add(n2);
				}
			}

			temp_posn.x = n.cur_posn.x;
			temp_posn.y = n.cur_posn.y;
			temp_posn.update( GlobalDataStore.WEST );
			if( map.moveable_position( temp_posn) != 0 )
			{
				if(visited[temp_posn.x][temp_posn.y] == 0 )
				{
					Node n2 = new Node(temp_posn,n.initial_move,n.distance+1);
					Q.add(n2);
				}
			}
		
			temp_posn.x = n.cur_posn.x;
			temp_posn.y = n.cur_posn.y;
			temp_posn.update( GlobalDataStore.NORTH );
			if( map.moveable_position( temp_posn) == 0 )
			{
				if(visited[temp_posn.x][temp_posn.y] != 0 )
				{
					Node n2 = new Node(temp_posn,n.initial_move,n.distance+1);
					Q.add(n2);
				}
			}
		
			temp_posn.x = n.cur_posn.x;
			temp_posn.y = n.cur_posn.y;
			temp_posn.update( GlobalDataStore.SOUTH );
			if( map.moveable_position( temp_posn) == 0 )
			{
				if(visited[temp_posn.x][temp_posn.y] != 0 )
				{
					Node n2 = new Node(temp_posn,n.initial_move,n.distance+1);
					Q.add(n2);
				}
			}
		}
	}

}
