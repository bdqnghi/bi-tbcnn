/**
 * \file Heap.java
 *
 * \brief Definicao da classe da lista de prioridade.
 *
 * \author Petrucio Ricardo Tavares de Medeiros
 * Raul Lucena e Silva
 *
 * \version 1.0
 */

import java.util.Vector; // Vector para a heap
import java.io.*; // leitura de arquivo

/**
 * \class Heap
 *
 * \brief A classe da lista de prioridade.
 */
public class Heap {
	
	// Entrada
	static FileReader arqIn;
	static BufferedReader lerArq;
	
	// Saída
	static FileWriter arqOut;
	static PrintWriter gravarArq;
    
    public static void main(String[] args){
    	Heap heap = new Heap();
        
        heap.heap.add(null); // 1ª posição nula
        
        try {
        	
        	// Entrada
        	arqIn = new FileReader("testes/filaprioridade1.in");
        	lerArq = new BufferedReader(arqIn);
        	
        	// Saída
        	arqOut = new FileWriter("testes/saida.txt");
            gravarArq = new PrintWriter(arqOut);
            
  
        	String linha = lerArq.readLine(); // lê a primeira linha
			  
        	if(linha.contains("MAX")){
        		min_max = 1;
        		gravarArq.println("-");
        	} else if (linha.contains("MIN")) {
        		min_max = -1;
        		gravarArq.println("-");
        	}
          
        	while (linha != null) { // a variável "linha" recebe o valor "null" quando o processo de repetição atingir o final do arquivo texto
	    
	        	  linha = lerArq.readLine(); // lê da segunda até a última linha
	        	  String params[] = linha.split(" ");
	        	  
	        	  if (params[0].contains("insert")){
	        		  heap.insert(Integer.parseInt(params[1]) , Integer.parseInt(params[2]));
	        	  }
	        	  else if (params[0].contains("decrease")){
	        		  heap.decrease(Integer.parseInt(params[1]) , Integer.parseInt(params[2]));
	        	  }
	        	  else if (params[0].contains("increase")){
	        		  heap.increase(Integer.parseInt(params[1]) , Integer.parseInt(params[2]));
	        	  }
	        	  else if (params[0].contains("extract")) {
	        		  heap.extract();
	        	  }
        	}
          
        	lerArq.close();
            gravarArq.close();
          
        } catch (IOException e) {
            System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
        
        //min_max = 1;
        
        
    }
    
    //--------------------------------------------------------------------
    //                       Atributos Privado
    //--------------------------------------------------------------------
    static byte min_max = 0; // 0 = ainda não definido, 1 p/ max e -1 para min;
    private Vector<No> heap = new Vector<No>();
    
    
    /**
     * \class No
     *
     * \brief A classe do tipo do Array.
     */
    private class No{
        //--------------------------------------------------------------------
        //                       Atributos Privado
        //--------------------------------------------------------------------
        private int id, chave;
        //--------------------------------------------------------------------
        //                       Metodos privados
        //--------------------------------------------------------------------
        /**
         * \fn private No(int id, int chave)
         *
         * \brief Metodo construtor da classe No.
         *
         * \param id - atribui id ao objeto
         * chave - atribui chave ao objeto
         */
        private No(int id, int chave){
            this.id = id;
            this.chave = chave;
        }
        /**
         * \fn private int getId()
         *
         * \brief Metodo que retorna o valor da ID.
         */
        private int getId(){return this.id;}
        /**
         * \fn private int getChave()
         *
         * \brief Metodo que retorna o valor da Chave.
         */
        private int getChave(){return this.chave;}
    }
    
    //--------------------------------------------------------------------
    //                       Metodos privados
    //--------------------------------------------------------------------
    /**
     * \fn public void insert(int id, int chave)
     *
     * \brief Metodo que insere elemento da heap.
     *
     * \param id - posição a inserir Array
     * chave - valor guardado na posição
     */
    public void insert(int id, int chave){

        if (verificarId(id) > 0){
            gravarArq.println("notinserted");
            return;
        }
        No no = new No(id, chave);
        heap.add(no);
        System.out.println("add: " + id + " " + chave);
        int ultimaPosicao = heap.size() - 1;
        heapify(ultimaPosicao);
        gravarArq.println("-");
    }
    
    /**
     * \fn private void heapify(int posicao)
     *
     * \brief Metodo que ordena as prioridades da heap.
     *
     * \param posicao - posição a ordenar
     */
    private void heapify(int posicao){
            
        int pai = posicao/2;
        if (pai > 0){ // Pai existe
            if (min_max == 1){ // maxHeapify
                if (heap.get(pai).getChave() < heap.get(posicao).getChave()){
                    trocarNo(posicao, pai);
                    
                    heapify(pai);
                }
            }
            else if(min_max == -1){ // minHeapify
                if (heap.get(pai).getChave() > heap.get(posicao).getChave()) {
                    trocarNo(posicao, pai);
                    
                    heapify(pai);
                }
            }
        }
        for (int i=1; i < heap.size() ; i++ ) {
            System.out.printf(heap.get(i).chave + " ");
        }System.out.println();
    }

    /**
     * \fn public void extract()
     *
     * \brief Metodo que extrai a prioridade.
     */
    public void extract(){
    	
        int ultimaPosicao = heap.size() - 1;
        
        if (ultimaPosicao < 1){
        	gravarArq.println("empty");
        	return;
        }
        System.out.println("rm: " + heap.get(1).id + " " + heap.get(1).chave);

        gravarArq.println(heap.get(1).id + " " + heap.get(1).chave);
       
        No aux = heap.get(ultimaPosicao);
        trocarNo(1, ultimaPosicao);
        heap.remove(ultimaPosicao);

        for (int i=1; i < heap.size() ; i++ ) {
            System.out.printf(heap.get(i).chave + " ");
        }
        System.out.println();
        if (heap.size() >= 2){
            heap.set(1, aux);
            
            descer(1);
        }
        
    }
    
    /**
     * \fn private void descer(int posicao)
     *
     * \brief Metodo que desce o no da raiz para reaustá-lo à prioridade.
     * 
     * \param posicao - informa a posição do no a descer. Função recursiva.
     */
    private void descer(int posicao){
        int filhoE = -1;
        if ((posicao * 2) < heap.size()-1) {
        	filhoE = posicao * 2;
        }
        int filhoD = -1;
        if ( (filhoE + 1) < heap.size()) {
        	filhoD = filhoE + 1;
        }
        
        if ( /*(filhoE > 0) &&*/ (filhoD > 0) ){
            if (min_max == 1){ // maxHeapify
                if (heap.get(filhoE).getChave() > heap.get(filhoD).getChave()){
                    if (heap.get(posicao).getChave() < heap.get(filhoE).getChave()){
                        trocarNo(posicao, filhoE);
                        descer(filhoE);
                    }
                }
                else{
                    if (heap.get(posicao).getChave() < heap.get(filhoD).getChave()){
                        trocarNo(posicao, filhoD);
                        descer(filhoD);
                    }
                }
            }
            else if (min_max == -1){ // minHeapify
                if (heap.get(filhoE).getChave() < heap.get(filhoD).getChave()){
                    if (heap.get(posicao).getChave() > heap.get(filhoE).getChave()){
                        trocarNo(posicao, filhoE);
                        descer(filhoE);
                    }
                }
                else{
                    if (heap.get(posicao).getChave() > heap.get(filhoD).getChave()){
                        trocarNo(posicao, filhoD);
                        descer(filhoD);
                    }
                }
            }
        }
        else if (filhoE > 0){
            if(min_max == 1){ // MAX
            	if (heap.get(posicao).getChave() < heap.get(filhoE).getChave()){
                    trocarNo(posicao, filhoE);
                    descer(filhoE);
                }
            }else { // MIN
                if (heap.get(posicao).getChave() > heap.get(filhoE).getChave()){
                    trocarNo(posicao, filhoE);
                    descer(filhoE);
                }
            }
        }
    }
    
    /**
     * \fn private void trocarNo(int no1, int no2)
     *
     * \brief Metodo que troca a posição de dois nós no Array.
     * 
     * \param no1 - index do 1º nó a ser trocado.
     * no2 - index do 2º nó a ser trocado.
     */
    private void trocarNo(int no1, int no2){
        No aux = heap.get(no1);
        heap.set(no1, heap.get(no2));
        heap.set(no2, aux);
    }
    
    /**
     * \fn private boolean verificarId(int id)
     *
     * \brief Metodo que verifica se algum nó da heap possui o id passado e retorna a posição.
     * 
     * \param id - id a verificar.
     */
    private int verificarId(int id){
        for(int i = 1 ; i < heap.size() ; i++ ){
            if( heap.get(i).getId() == id ) {
                return i;
            }
        }
        return 0;
    }

    /**
     * \fn public decrease(int id, int chave)
     *
     * \brief Metodo que altera elemento da heap mínima.
     *
     * \param id - posição a mudar na heap
     * chave - novo valor a inserir na posição do id
     */
    public void decrease(int id, int chave){

        if(min_max != -1){ // para decrease() a heap tem que ser mínima 
        	gravarArq.println("notupdated");
            return;
        }

        int posicao = verificarId(id);

        if (posicao > 0){
            if(heap.get(posicao).getChave() > chave){
                No no = new No(id, chave);

                heap.set(posicao, no);
                gravarArq.println(id + "  " + chave);
                heapify(posicao);
            }
            else{
            	gravarArq.println("notupdated");
            }
        }
    }

    /**
     * \fn public increase(int id, int chave)
     *
     * \brief Metodo que altera elemento da heap máxima.
     *
     * \param id - posição a mudar na heap
     * chave - novo valor a inserir na posição do id
     */
    public void increase(int id, int chave){

        if(min_max != 1){ // para increase() a heap tem que ser máxima 
        	gravarArq.println("notupdated");
            return;
        }

        int posicao = verificarId(id);

        if (posicao > 0){
            if(heap.get(posicao).getChave() < chave){
                No no = new No(id, chave);

                heap.set(posicao, no);
                
                gravarArq.println(id + "  " + chave);
                heapify(posicao);
            }
            else{
            	gravarArq.println("notupdated");
            }
        }
    }
}