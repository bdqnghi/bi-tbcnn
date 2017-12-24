import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;

public class DFS 
{
    private State startState;
    private State endState;
    private Stack<State> fringe;
    private Random generator;
    private ArrayList solution;
    
    public DFS(State _startState, State _endState)
    {
        this.generator = new Random();
        startState = _startState;
        endState = _endState;
        fringe = new Stack<State>();
    }
    
    public int getRandomNumber()
    {
        return generator.nextInt(4);
    }
    
    public void pushToFringe(State aNode)
    {
        fringe.push(aNode);
    }
    
    public State popFromFringe()
    {
        return fringe.pop();
    }
    
    public void solve()
    {
        State currentState;
        boolean isMove = false;
        
        while(!startState.isEqual(endState))
        {
            int move = this.getRandomNumber();
            System.out.println(move);
            isMove = startState.isMoveable(move);
            if(isMove)
            {
                startState.move(move);
                startState.print();
            }
        } 
    }
    
    public void makeSolution()
    {
        
    }
    
    public boolean isGoalState(State endState)
    {
        return this.endState == endState;
    }
    
    public boolean isFringeEmpty()
    {
        return fringe.empty();
    }
    
}
