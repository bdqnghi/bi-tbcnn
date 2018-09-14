import java.util.*;
import java.io.*;

public class bfs{

	public static int[][] level=new int[8][8];
	public static int[][] arr=new int[8][8];

	public static void log(Object obj){
		System.out.println(obj);
	}
	
	public static void main(String[] args) throws Exception{
			int times;
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			times=Integer.parseInt(br.readLine());

			for(int i=0;i<times;i++){
				String[] splits=br.readLine().split(" ");
				
				level=new int[8][8];
				arr=new int[8][8];
				
				do_bfs(splits[0],splits[1]);	
			}
			
	}

	public static void visit(String a){
		//cout<<"visited "<<a<<endl;
		arr[a.charAt(0)-'a'][a.charAt(1)-'1']=1;
	}

	public static int check(String a){
		//log("temp is "+a);
		return arr[a.charAt(0)-'a'][a.charAt(1)-'1'];
	}

	public static void do_bfs(String a,String b){
		ArrayDeque<String> queue=new ArrayDeque<>();
		
		queue.add(a);
		level[a.charAt(0)-'a'][a.charAt(1)-'1']=0;

		while(!queue.isEmpty()){
			String aa=queue.pop();

			char aa0=aa.charAt(0);
			char aa1=aa.charAt(1);

			int temp_level=level[aa0-'a'][aa1-'1'];
			visit(aa);

			if(aa.equals(b)){
				log(temp_level);
				break;
			}

			if(aa0+1<='h'){
				if(aa1+2<='8'){
					String temp=(char)(aa0+1)+""+(char)(aa1+2);

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}

				if(aa1-2>='1'){
					String temp=(char)(aa0+1)+""+(char)(aa1-2)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}
			}	//

			if(aa0+2<='h'){
				if(aa1+1<='8'){
					String temp=(char)(aa0+2)+""+(char)(aa1+1)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}

				if(aa1-1>='1'){
					String temp=(char)(aa0+2)+""+(char)(aa1-1)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}
			}	//

			if(aa0-2>='a'){
				if(aa1+1<='8'){
					String temp=(char)(aa0-2)+""+(char)(aa1+1)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}

				if(aa1-1>='1'){
					String temp=(char)(aa0-2)+""+(char)(aa1-1)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}
			}	//

			if(aa0-1>='a'){
				if(aa1+2<='8'){
					String temp=(char)(aa0-1)+""+(char)(aa1+2)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}

				if(aa1-2>='1'){
					String temp=(char)(aa0-1)+""+(char)(aa1-2)+"";

					if(check(temp)==0){
						queue.add(temp);
						level[temp.charAt(0)-'a'][temp.charAt(1)-'1']=temp_level+1;
					}
				}
			}	//

		}	// end of while

	}

}