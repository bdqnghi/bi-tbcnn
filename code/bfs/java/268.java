package hou.structrue.map;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * @author houweitao 2015年8月10日 下午2:15:30
 *         http://blog.csdn.net/gamer_gyt/article/details/47147855
 */

public class BFS {
	private Object[] vet; // 定义vet数组用来存放顶点信息
	private int[][] array; // 定义邻接矩阵存放图的顶点信息
	private int vexnum; // 存储边的条数
	private boolean[] ifVisit;// 存放结点是否被访问过
	private List<Object> list = new ArrayList<Object>(); // 定义一个临时的队列用来存放已经被访问过的结点

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BFS map = new BFS(5);
		Character[] vet = { 'A', 'B', 'C', 'D', 'E' };
		map.addVet(vet);
		map.addEage(0, 1);
		map.addEage(0, 4);
		map.addEage(1, 3);
		map.addEage(2, 3);
		map.addEage(2, 4);

		System.out.println("广度优先遍历开始：");
		map.bfs();
	}

	// 广度优先遍历
	public void bfs() {
		Queue<Integer> queue = new LinkedList<Integer>(); // 定义一个队列
		for (int i = 0; i < vexnum; i++) {
			if (!ifVisit[i]) {
				ifVisit[i] = true;
				visited(i);
				queue.add(i);
				while (!queue.isEmpty()) {
					int j = (Integer) queue.remove().intValue();
					// 判断队列是否循环完了，如果循环完了，就不需要再循环了
					if (list.size() == vexnum) {
						queue.removeAll(queue); // 清空队列
						return;
					}
					for (int m = this.first(j); m > 0; m = this.next(j, m)) {
						if (!ifVisit[m]) {
							queue.add(m);
							ifVisit[m] = true;
							visited(m);
						}
					}
				}
			}

		}
	}

	// 获得当前结点
	public int first(int i) {
		for (int j = 0; j < vexnum; j++)
			if (array[i][j] > 0)
				return j;
		return -1;
	}

	public int next(int i, int k) {
		for (int j = k + 1; j < vexnum; j++) {
			if (array[i][j] > 0)
				return j;
		}
		return -1;
	}

	// 初始化图的节点
	private void addVet(Object[] object) {
		this.vet = object;
	}

	// 往临时队列里添加已经访问过的结点，并输出
	public void visited(int k) {
		list.add(vet[k]);
		System.out.print("->" + vet[k]);
	}

	// 构建邻接矩阵，保存边的信息
	public void addEage(int m, int n) {
		if (m != n) {
			array[m][n] = 1;
			array[n][m] = 1;
		} else
			return;
	}

	// 图的初始化
	public BFS(int m) {
		vexnum = m;
		vet = new Object[m];
		array = new int[m][m];
		ifVisit = new boolean[m];
		for (int i = 0; i < m; i++) {
			ifVisit[i] = false;
			for (int j = 0; j < m; j++)
				array[i][j] = 0;
		}
	}
}
