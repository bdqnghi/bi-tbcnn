import java.lang.*;
import java.util.*;
import java.io.*;

public class BFS {
    
    //finds the first circuit that solves the truth table by using BFS on a tree of all possible circuits with optimizations
    public static Circuit bfsAlgorithm(ArrayList<String> circuit_inputs, ArrayList<String> circuit_solutions, int not_gates_allowed) throws IOException {
        ArrayList<String> start_circuit_lines = new ArrayList<String>();
        for (int i = 1; i <= circuit_inputs.size(); ++i) {
            start_circuit_lines.add(i + " NONE " + i);
        }
        
        ArrayList<Integer> input_solution_lines = new ArrayList<Integer>();
        Circuit start_circuit = new Circuit(start_circuit_lines, 0, circuit_inputs, not_gates_allowed, circuit_solutions, input_solution_lines); // this should initialize the first
                                         
        Queue<Circuit> q = new LinkedList<Circuit>();
        q.add(start_circuit);
        
        int count = 0;
        
        Circuit current_circuit;
        while ((current_circuit = q.poll()) != null) {
            System.out.println("Looking at circuit " + ++count);
            ArrayList<Circuit> children = new ArrayList<Circuit>(current_circuit.getPossibleGates() ); // level to search through
            for (Circuit c : children) {
                
                if (c.solution_lines.size() == circuit_solutions.size()) {
                    System.out.println("\nFound a solution!");
                    return c;
                }
                else 
                    q.add(c); // pushes current circuit into q
            }
            
        }
        return null;
    }
    
    public static void main(String[] args) throws IOException { 
        System.out.println("Testing XOR\n");
         //circuit_inputs
         ArrayList<String> circuit_in = new ArrayList<String>();
         circuit_in.add("0011");
         circuit_in.add("0101");

        //circuit solutions
        ArrayList<String> solution = new ArrayList<String>();
        solution.add("0110");
        
        //input lines of ciruit, number of not gates, input truth table, not gates allowed, solution outputs wanted, number of solutuon lines found
        Circuit test = bfsAlgorithm(circuit_in, solution, 2);
        for (String t : test.circuit) {
                    System.out.println(t);
        }
        System.out.println();
        System.out.print("Solution line(s) are");
        for (Integer i : test.solution_lines) {
            System.out.print(" " + i);
        }
        System.out.println();
        
        ///////////////////////////////////////////////////////////////////
        
        //un-comment and comment out the rest of main to test 
        // System.out.println("Testing one-bit full adder\n");
        //  //circuit_inputs
        //  ArrayList<String> circuit_in = new ArrayList<String>();
        //  circuit_in.add("00001111");
        //  circuit_in.add("00110011");
        //  circuit_in.add("01010101");

        // //circuit solutions
        // ArrayList<String> solution = new ArrayList<String>();
        // solution.add("00010111");
        // solution.add("01101001");
        
        
        // //input lines of ciruit, number of not gates, input truth table, not gates allowed, solution outputs wanted, number of solutuon lines found
        // Circuit test = bfsAlgorithm(circuit_in, solution, 2);
        // for (String t : test.circuit) {
        //             System.out.println(t);
        // }
        // System.out.println();
        // System.out.print("Solution line(s) are");
        // for (Integer i : test.solution_lines) {
        //     System.out.print(" " + i);
        // }
        // System.out.println();
        
        ///////////////////////////////////////////////////////////////////
        
        //un-comment and comment out the rest of main to test 
        // System.out.println("Testing triple negation\n");
        //  //circuit_inputs
        //  ArrayList<String> circuit_in = new ArrayList<String>();
        //  circuit_in.add("00001111");
        //  circuit_in.add("00110011");
        //  circuit_in.add("01010101");

        // //circuit solutions
        // ArrayList<String> solution = new ArrayList<String>();
        // solution.add("11110000");
        // solution.add("11001100");
        // solution.add("10101010");
        
        
        // //input lines of ciruit, number of not gates, input truth table, not gates allowed, solution outputs wanted, number of solutuon lines found
        // Circuit test = bfsAlgorithm(circuit_in, solution, 2);
        // for (String t : test.circuit) {
        //             System.out.println(t);
        // }
        // System.out.println();
        // System.out.print("Solution line(s) are");
        // for (Integer i : test.solution_lines) {
        //     System.out.print(" " + i);
        // }
        // System.out.println();
        
    }
   
}