package model.algorithm;

import java.util.ArrayList;
import java.util.HashMap;

import model.domains.SearchDomain;

public class BFS extends CommonSearcher {		//Algorithm #2 BFS

	public BFS() {
		System.out.println("------------------------");
		System.out.println("BFS Algorithm Chosen");
		System.out.println("------------------------");
	}
	@Override
	public ArrayList<Action> search(SearchDomain domain) {
		System.out.println("Activating BFS Search Method");
		State start=domain.getStartState();
		start.setgScore(domain.getG(start));
		start.setCameWithAction(null);
		start.setfScore(start.getgScore());
	
		this.openSet.add(start);
		while (!openSet.isEmpty() && !stop)
		{
			State n = openSet.poll();
			closedSet.add(n);
			if (n.equals(domain.getGoalState()))
				return (reconstrucePath(n.getCameFrom(), n));
			HashMap<Action, State> successors = domain.getAllPossibleMoves(n);
			for (Action a : successors.keySet())
			{
				State s = successors.get(a);
				double newPathPrice = n.getgScore() + a.getCost();
				if (!openSet.contains(s) && !closedSet.contains(s))
				{
					s.setCameFrom(n);
					s.setCameWithAction(a);
					s.setgScore(newPathPrice);
					s.setfScore(newPathPrice);
					openSet.add(s);
				}
				else
				{	
					if (newPathPrice < s.getgScore())
					{
						if (!openSet.contains(s))
							openSet.add(s);
						else {
								openSet.remove(s);
								s.setCameFrom(n);
								s.setCameWithAction(a);
								s.setgScore(newPathPrice);
								s.setfScore(newPathPrice);
								openSet.add(s);
						}	
							
					}
				}
					
			}
		}	
		return null;
	}
	@Override
	public void stopSearch() {		//stops the search()
		this.stop=true;
		
	}

}
