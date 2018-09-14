// 2493893
// 4243395
import java.util.*;

public class Knapsack {
	long size; int[] vs; int[] ws; Map<Long, Integer> cache = new HashMap<Long, Integer>();

	public Knapsack(int s, int[] vs, int[] ws) { size = s; this.vs = vs; this.ws = ws; }

	long getKey(int i, int w) { return i*(size+1) + w; }

	int opt(int i, int w) {
		if(w == 0) return 0;
		if(i == 0) return ws[i] > w ? 0 : vs[i];

		long key = getKey(i, w);
		if(cache.containsKey(key)) return cache.get(key);

		int take = 0; if(w >= ws[i]) take = opt(i-1, w-ws[i]) + vs[i];  
		int drop = opt(i-1, w), max = Math.max(take, drop);
		cache.put(key, max);
		return max;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt(); 
		int[] vs = new int[s.nextInt()], ws = new int[vs.length];
		for(int i=0; i<vs.length; i++) { vs[i] = s.nextInt(); ws[i] = s.nextInt(); }
		System.out.println((new Knapsack(size, vs, ws)).opt(vs.length-1, size));
	}
}