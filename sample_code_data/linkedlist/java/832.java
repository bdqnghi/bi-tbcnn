import java.util.LinkedList;
import java.util.List;

public class linkedlist {
   private List<Integer> list=new LinkedList<>();
        void list(){
            for (int i = 0; i <16 ; i++) {
                list.add(i);}
                System.out.println(list);
            }
         void list(int size){
        for (int i = 0; i <size; i++) {
            list.add(i);}
            System.out.println(list);

        }
        public void add(int num){
        list.remove(0);
        list.add(num);
            System.out.println(list);
        }
}

