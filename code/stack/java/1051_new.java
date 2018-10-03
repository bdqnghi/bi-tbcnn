
package ParsingShuntingYard;

import org.junit.Test;
import static org.junit.Assert.*;


public class StackTest {
    
    @Test
    public void StackTest() {
        Stack stack= new Stack();
        stack.pushStack("+");
        stack.pushStack("-");
        stack.pushStack("*");
        assertEquals("*", stack.popStack());
        stack.pushStack("3");
        assertEquals("3",stack.popStack());
        assertEquals("-",stack.popStack());
        assertEquals("+",stack.popStack());
        
    }
}
