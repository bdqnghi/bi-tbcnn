/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author Dinal
 */

class Heap{
    String[] data=new String[1000];
    int heapSize=0;
    
    public boolean input(String in){    //input data to the heap
        if(heapSize<1000){
            data[heapSize]=in;
            heapSize++;
            return true;
        }
        return false;
    }
    
    public String output(int x){        //take out nay data according to given index
        return data[x];
    }
    
    public void heapify(int i){        //standard heapify operation
        int l,r,largest;
        l=2*i+1;
        r=2*i+2;
        if(l<heapSize && Integer.parseInt(data[l].substring(0,8))>Integer.parseInt(data[i].substring(0,8))){
            largest=l;
        }
        else largest=i;
        if(r<heapSize && Integer.parseInt(data[r].substring(0,8))>Integer.parseInt(data[largest].substring(0,8))){
            largest=r;
        }
        if(largest!=i){
            String x=data[i];
            data[i]=data[largest];
            data[largest]=x;
            heapify(largest);
        }
    }
    
    public void buildHeap(){    //standard buildHeap operation
        for(int i=heapSize/2;i>=0;i--){
            heapify(i);
        }
    }
    public void heapSort(){        //standard heapSort operation
        buildHeap();
        String x=null;
        for(int i=heapSize-1;i>0;i--){
            x=data[0];
            data[0]=data[i];
            data[i]=x;
            heapSize--;
            heapify(0);
        }
    }
    
}

