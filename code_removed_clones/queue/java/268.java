package fr.enstabretagne.simulation.station;
import java.util.LinkedList;


public class Queue {
	
	public int taille;
	public LinkedList<Pompe> listePompe;

	public int getTaille() {
		return taille;
	}

	public void setTaille(int taille) {
		this.taille = taille;
	}

	public LinkedList<Pompe> getListePompe() {
		return listePompe;
	}

	public void setListePompe(LinkedList<Pompe> listePompe) {
		this.listePompe = listePompe;
	}
	
	public void lieaunepompe(Pompe p){
		this.listePompe.add(p);
		p.setQ(this);
	}

	public Queue() {
		
		this.taille = 0;
		this.listePompe= new LinkedList<Pompe>();
	}
	
	public void addclient(){
		
		this.taille++;
	}
	public boolean isApompeFree(){
		boolean temp=false;
		for(int i =0;i<this.listePompe.size();i++){
			temp=temp||listePompe.get(i).status;
			
		}
		return temp;
		
	}
	
	public void videqueue(){
		this.taille--;
	}
	public Pompe remplispompe(){
		
		for(int i =0;i<this.listePompe.size();i++){
			if(listePompe.get(i).isStatus()){
				listePompe.get(i).setStatus(false);
				return listePompe.get(i);
			}
				
		}
			

		return null;
	}

}
