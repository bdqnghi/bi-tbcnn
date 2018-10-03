/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artificial_lab_4;

/**
 *
 * @author yasin
 */
public class DFS {
    
    private int V[][];
    private String Color[];
    int      NNodes;
    private int Pred[];
    
    
    
    public DFS(int mat[][],int N)
    {
        NNodes =N;
        V=new int[NNodes][NNodes];
        Color=new String[NNodes];
        Pred=new int[NNodes];
        
        
      for ( int i=0; i < NNodes; i++)
        for ( int j=0; j < NNodes; j++)
            V[i][j] = mat[i][j];
        
       for(int u=0;u<NNodes;u++)
       {
       Color[u]="white";
       Pred[u]=0;
       
       }
      
       
       for(int u=0;u<NNodes;u++)
       {
        if(Color[u]=="white")
        {
        DFSVisit(u);
        }
       }
    
    }
    
    
    public void DFSVisit(int u)
    {
    Color[u]="gray";
    printNode(u);
        for(int v=0;v<NNodes;v++)
        {
            if(V[u][v] > 0 && Color[v]=="white")
            {
            Pred[v]=u;
            DFSVisit(v);
            }

        }
    Color[u]="black";
    
    }
    
       private void printNode(int n)
   {
       if(n==0)
           System.out.println("a");
       if(n==1)
           System.out.println("b");
       if(n==2)
           System.out.println("c");
       if(n==3)
           System.out.println("d");
       if(n==4)
           System.out.println("e");
       if(n==5)
           System.out.println("f");
       if(n==6)
           System.out.println("g");
       if(n==7)
           System.out.println("h");
    
       
      
   }
    
}
