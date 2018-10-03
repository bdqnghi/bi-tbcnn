package jds.core.ref;

/**
 * Created with IntelliJ IDEA.
 * User: sai
 * Date: 9/17/13
 * Time: 12:44 AM
 * To change this template use File | Settings | File Templates.
 */
public class Stack {

    ListElement top;

    public Stack(Object data){
        top = new ListElement(data);
    }

    public Stack(){
        top = new ListElement(null);
    }

    public Object getStackTop(){
        return top.getData();
    }
    public Boolean push(Object data){
        if(top.getData()==null){
            top.setData(data);
            return true;
        }
        ListElement element = new ListElement(data);
        element.setNext(top);
        top= element;
        return true;
    }

    public Object pop(){
        if(top.getData()==null)
            return null;
        Object poppedData = top.getData();
        top = top.getNext();
        return poppedData;
    }

}
