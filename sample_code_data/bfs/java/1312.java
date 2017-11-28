
package tira.labyrinttiohjelma;

/**
 * Breadth-First seach algoritmi
 * 
 * @author Henri
 */
public class BFS extends Ratkaisija {
    

    // Merkkaaja Node kertoo kun uusi 'aalto' tai sykli alkaa jonossa, milloin voi kasvattaa matkan pituutta.
    private Node merkkaaja;
    private boolean uusiSykli = false;
    private Jono<Node> q;
    
    /**
     *
     * @param laby
     */
    public BFS (Labyrintti laby) {
        super(laby);
        
    }
 
    /**
     * Palauttaa lyhimmän reitin pituuden
     * 
     * @return
     */
        @Override
    public int lyhin() {;
        this.q = new Jono<>();
        int n = kopio.getAlkuX();
        int m = kopio.getAlkuY();
        q.add(new Node(n, m));
        merkkaaja = new Node(n, m);
        kopio.getKuva()[n][m] = '#';
        int matka = 0;
        while (!q.isEmpty()) {
            Node s = q.poll();
            int x = s.getX();
            int y = s.getY();
            
            if (merkkaaja != null) {
                if (s.getX() == merkkaaja.getX() && s.getY() == merkkaaja.getY()) {
                    uusiSykli = true;
                    merkkaaja = null;
                    matka++;
                }
            }
            if (reitti(x+1, y, s)) return matka;
            if (reitti(x-1, y, s)) return matka;
            if (reitti(x, y+1, s)) return matka;
            if (reitti(x, y-1, s)) return matka;

        }
        System.out.println("Loppua ei löytynyt");
        this.kopio = teeKopioNykyisesta();
        return -1;
    }

    /**
     * Palauttaa true jos maali löytyy
     * 
     * @param x
     * @param y
     * @param edel
     * @return
     */
        public boolean reitti(int x, int y, Node edel) {
        if (reitinSelvitys(x, y)) {
            Node m = new Node(x, y, edel);
            q.add(m);
            if (uusiSykli) {
                merkkaaja = new Node(x, y);
                uusiSykli = false;
            }
            if (kopio.getKuva()[x][y] != '!') {
                kopio.getKuva()[x][y] = '#';
            } else {
                this.kopio = teeKopioNykyisesta();
                maali = m;
                return true;
            }
        }
        return false;
    }
    
}
