import java.io.BufferedWriter;
import java.io.FileWriter;

/**
 * The class containing the main method.
 * Sorts a binary file of 4096 bytes using 
 * a modified version of the quicksort algorithm
 *
 * @author Randy Liang (randy8)
 * @author Patrick McKee (bludevil)
 * @version October 24, 2016
 */

// On my honor:
//
// - I have not used source code obtained from another student,
// or any other unauthorized source, either modified or
// unmodified.
//
// - All source code and documentation used in my program is
// either my original work, or was derived by me from the
// source code published in the textbook for this course.
//
// - I have not discussed coding details about this project with
// anyone other than my partner (in the case of a joint
// submission), instructor, ACM/UPE tutors or the TAs assigned
// to this course. I understand that I may discuss the concepts
// of this program with other students, and that another student
// may help me debug my program so long as neither of us writes
// anything during the discussion or modifies any computer file
// during the discussion. I have violated neither the spirit nor
// letter of this restriction.

public class Quicksort {

    /**
     * the main method
     * stores the contents of the file in the buffer pool
     * sorts the bufferpool
     * writes out information about the sorting that just happened
     * 
     * @param args the arguments
     *          args[0] data file name
     *          args[1] numb-buffers
     * @throws Exception IO Exception
     */
    public static void main(String[] args) throws Exception {
        if (args != null && args.length == 3) {
            BufferPool pool = new BufferPool(args[0],
                    Integer.parseInt(args[1]));
            Sort sort = new Sort(pool);
            sort.sort();
            pool.flush();
            FileWriter fStream = new FileWriter(args[2], true);
            BufferedWriter buffWrite = new BufferedWriter(fStream);
            buffWrite.write("-----------------------------------\n");
            buffWrite.write("File:         " + args[0] + '\n');
            buffWrite.write("Hits:         " + pool.hits() + '\n');
            buffWrite.write("Reads:        " + pool.reads() + '\n');
            buffWrite.write("Writes:       " + pool.writes() + '\n');
            buffWrite.write("Time in ms:   " + sort.getRunTime() + '\n');
            buffWrite.write("-----------------------------------\n");
            buffWrite.close();
        }
        else {
            System.out.println("Wrong args");
        }
    }

    /**
     * generates a file
     * @param file is the file to generate
     * @param type is the type (ie. read/write)
     * @param size size of file
     * @throws Exception
     */
    public static void generateFile(String file, String type, String size)
            throws Exception {
        FileGenerator generator = new FileGenerator();
        generator.generateFile(new String[]{type, file, size});
    }
}
