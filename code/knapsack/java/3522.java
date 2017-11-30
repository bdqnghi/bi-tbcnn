//******************************************************************************
//
// File:    Knapsack.java
// Package: ---
// Unit:    Class Knapsack
//
// This Java source file is for CSCI-251 project 1
//
//******************************************************************************


import java.util.*;

/**
 * Class Knapsack is the main program for solving Knapsack problem.
 *
 * Usage: java Knapsack <C> <W_1> <V_1> [<W_2> <V_2> ...]
 *
 * @author: Jiaqi Gu  (jxg4836@rit.edu)
 * @version: 16-Feb-2016
 */
public class Knapsack {


    /**
     * Monitor class
     *
     * A monitor object providing a shared matrix.
     *
     */
    private static class Matrix{

        // fields
        //Matrix for the Knapsack
        int matrix[][];

        /**
         * Constructor for monitor class
         *
         * @para int N, int C where N is the number of items, and C is the capacity
         */
        public Matrix(int N, int C){
            // Create and initialize matrix, and make each location be -1 except for the ones in the first row
            matrix = new int[N+1][C+1];

            for(int i = 1;i<=N;i++){ //start at the second row
                for(int j = 0;j<=C;j++){
                    matrix[i][j] = -1;  //-1 means no value has been put in
                }
            }
        }

        /**
         * putValue method
         *
         * This method puts the given value into the matrix at row i, column j.
         *
         * @para int i, int j, int value where i is the index of row, and j is the index of column
         */
        public synchronized void putValue(int i, int j, int value){
            // check if there is value has already been put at row i, column j
            if (matrix[i][j]!=-1) {
                System.err.println("A value has already been put at row " + i + ", column " + j);
                System.exit(1);//System should exit when an error occurs
            }
            // put value at row i, column j
            matrix[i][j] = value;
            notifyAll(); //notify all threads
        }

        /**
         * getValue method throws InterruptedException, which shouldn't happen
         *
         * This method returns the value stored in the matrix at row i, column j.
         *
         * This method does not return until the value at row i, column j has been put.
         *
         * @para int i, int j, int value where i is the index of row, and j is the index of column
         */
        public synchronized int getValue(int i, int j) throws InterruptedException {
            while (matrix[i][j]==-1){//if no value has been put in M[i,j], make it wait
                wait();
            }
            return matrix[i][j];
        }
    }



    /**
     *  Items class to store values of W, and values of V
     *
     *  in order to prevent change of values
     */
    private static class Item{

        //fields
        int Weight;
        int Value;

        /**
         *  Constructor
         *
         *  @para int weight, int value
         */
        public Item(int weight, int value){
            this.Weight = weight;
            this.Value = value;
        }

        /**
         * getWeight method
         *
         * This method is for getting the Weight of the item
         *
         * @return Weight, which is int
         */
        public int getWeight(){
            return Weight;
        }

        /**
         * getValue method
         *
         * This method is for getting the Weight of the item
         *
         * @return Value, which is int
         */
        public int getValue(){
            return Value;
        }
    }



    /**
     * A runnable object that computes one (and only one) matrix element
     */
    private static class compute extends Thread{

        //fields
        private Matrix SharedMatrix;
        private Item ItemArray[];//for getting weight and value of a item
        int i;//row
        int j;//col

        /**
         * compute method
         *
         * This method is to compute exact one element at M[i,j]
         *
         * @para Matrix SharedMatrix, int i, int j
         */
        public compute(Matrix SharedMatrix, Item ItemArray[], int i, int j){
            this.SharedMatrix = SharedMatrix;
            this.ItemArray = ItemArray;
            this.i = i;
            this.j = j;
        }

        /**
         * run method for computing
         */
        public void run() {
            //If Wi > j, then M[i, j] = M[i-1, j]
            try{
                if(this.ItemArray[i].getWeight()>j){
                    SharedMatrix.putValue(i,j,SharedMatrix.getValue(i-1,j));
                }else{   //Otherwise M[i, j] = max (M[i-1, j], M[i-1, j-Wi] + Vi)
                    int max = Integer.max(SharedMatrix.getValue(i-1,j),SharedMatrix.getValue(i-1,j-this.ItemArray[i].getWeight())+this.ItemArray[i].getValue());
                    SharedMatrix.putValue(i,j,max);
                }
            }catch (InterruptedException exc){
                // It shouldn't happen
            }

        }
    }





    /**
     * A runnable object that print the output
     */
    private static class printer extends Thread{

        //fields
        private Matrix SharedMatrix;
        private Item ItemArray[];//for getting weight and value of a item
        private int N;//the number of item
        private int C;//the capacity
        int total_weight;
        int total_value;

        /**
         *  Constructor
         *
         * @para Matrix SharedMatrix, int i, int j
         */
        public printer(Matrix SharedMatrix, Item ItemArray[], int N, int C){
            this.SharedMatrix = SharedMatrix;
            this.ItemArray = ItemArray;
            this.N = N;
            this.C = C;
        }

        /**
         * run method for printing
         */
        public void run() {
            try{
                total_value = SharedMatrix.getValue(N,C);
                total_weight = 0;

                // trace back algorithm
                int i = N;
                int j = C;
                while(SharedMatrix.getValue(i,j) != 0){
                    while (SharedMatrix.getValue(i,j) == SharedMatrix.getValue(i-1,j)){
                        i--;
                    }
                    if(total_weight==0){//if it is the first element, there is no space before it
                        System.out.print(i);
                    }else {//if it is not the first element, there is a space before it
                        System.out.print(" "+i);
                    }
                    //trace total weight
                    total_weight+=this.ItemArray[i].getWeight();
                    j = j - this.ItemArray[i].getWeight();
                    i --;
                }

                System.out.print("\n");

                // Print out the total weight
                System.out.println(total_weight);

                // Print out the total value
                System.out.println(total_value);

            }catch (InterruptedException exc){
                // It shouldn't happen
            }

        }
    }





    /**
     * The main program
     *
     * @param args The command line arguments (name of input file)
     */
    public static void main(java.lang.String[] args){

        // ---------------------------   Check if input arguments are valid  -----------------------

        // For temporary storage use
        int n;
        //count the number of arguments, and check their validation
        int num_arg = args.length;
        // If no argument
        if(num_arg == 0){System.err.println("Usage: (Miss arguments) java Knapsack <C> <W_1> <V_1> [<W_2> <V_2> ...]");  System.exit(1);}
        // If only one argument
        if(num_arg == 1){System.err.println("Usage: There must be at least one item");  System.exit(1);}
        // If the number of arguments is even, miss one value
        if( (num_arg % 2) == 0){
            n = Integer.parseInt(args[num_arg-1]) / 2;
            System.err.println("Usage: <V_" + n + "> is missed");
            System.exit(1);
        }
        //check if each argument is an integer greater than or equal to 1
        for(String arg:args) {
            try {
                n = Integer.parseInt(arg);
                // n should be >= 1
                if(n<1){System.err.println("Each argument must be an integer greater than or equal to 1");System.exit(1);}
            } catch (NumberFormatException ex) {//catch exception if arg cannot be converted into int
                System.err.println("Each argument must be an integer greater than or equal to 1");
                System.exit(1);
            }
        }


        // ------------------------------ Solve the Knapsack problem ------------------------------

        // Calculate the number of items
        int number = (num_arg-1)/2;

        // Put the capacity in capacity
        int capacity = Integer.parseInt(args[0]);

        // Create an Array to store Item objects
        Item ItemArray[] =  new Item[number + 1];
        int count = 0;//for count the number of items
        for(int i=1;i<num_arg;i+=2){ //index starts at 1 not 0
            ItemArray[count+1] = new Item(Integer.parseInt(args[i]),Integer.parseInt(args[i+1]));
            count++;
        }

        // create a new monitor object
        Matrix SharedMatrix = new Matrix(number,capacity);

        // first run output printing thread
        (new printer(SharedMatrix, ItemArray, number,capacity)).start();

        // start the thread that computes the last element in the last row
        // then the thread that computes the next-to-last element in the last row (backward)
        for(int i=number;i>=1;i--){
            for(int j=capacity;j>=0;j--){//start from the last element, then go backward
                (new compute(SharedMatrix, ItemArray, i,j)).start();
            }

        }

    }

}
