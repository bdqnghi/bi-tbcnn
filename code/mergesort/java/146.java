
package ordena;

import java.io.FileNotFoundException;
import java.io.IOException;
import tweeter.tweeterobj;
import write.write;

public class mergesort {
    private tweeterobj[] auxiliar;
    private tweeterobj[] vetor;
    private int n;
    private int copias = 0;
    private int comparacoes = 0;
    private long tempo;
    static final String[] statdata = new String[6];
    write output = new write();


    public void sort(tweeterobj[] array) {
        if (array ==null || array.length==0){
            return;
        }
        this.vetor = array;
        n = this.vetor.length;
        this.auxiliar = new tweeterobj[n];
        final long startTime = System.currentTimeMillis(); //INICIALIZA O CRONÔMETRO
        mergesort(0, n - 1);
        final long endTime = System.currentTimeMillis(); // PARA O CRONÔMETRO
        tempo = endTime - startTime; //CALCULA QUANTO TEMPO EM MS
    }

    private void mergesort(int ini, int fim) {
        
        if (ini < fim) {
            int meio = ini + (fim - ini) / 2;
            mergesort(ini, meio);
            mergesort(meio + 1, fim);
            merge(ini, meio, fim);
        }
    }

    private void merge(int ini, int meio, int fim) {
        for (int i = ini; i <= fim; i++) {
            auxiliar[i] = vetor[i];
        }

        int i = ini;
        int j = meio + 1;
        int k = ini;

        while (i <= meio && j <= fim) {
            if (auxiliar[i].getChave() <= auxiliar[j].getChave()) {
                vetor[k] = auxiliar[i];
                i++;
            } else {
                vetor[k] = auxiliar[j];
                j++;
            }
            k++;
            this.comparacoes++;
        }
        while (i <= meio) {
            vetor[k] = auxiliar[i];
            k++;
            i++;
        }


    }
    public void salvarMetricas(int x) throws FileNotFoundException, IOException{
        mergesort.statdata[x] = "\n\n\n Metricas Quantidade de elementos: " +this.vetor.length +"\nExecução numero: " +x +"\nNumero de comparações:  " +this.comparacoes +"\nNumero de copias de registro: " +this.copias +"\nTempo de execução QS: " +this.tempo +" ms";
        
        if(x==5) output.write("metricasvet"+this.vetor.length+x ,mergesort.statdata);
    }
}
