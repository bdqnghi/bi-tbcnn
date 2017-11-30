template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock)        // 单个节点探索
{
	Queue<int> Q;                      // 存放队列
	status(v) = DISCOVERED;            // 初vertex状态UNDISCOVERED
	Q.enqueue(v);                      // 入队
	while (!Q.empty())                 // 队列不为空时
	{
		int v = Q.dequeue();           // 出一个
		dTime(v) = ++clock;
		for (int u = firstNbr(V); -1 < u; u = nextNbr(v, u))  // 访问u的临vertex们
			if (status(u) == UNDISCOVERED)                    // 如果是UNDISCOVRED
			{
				status(u) = DISCOVERED;                       // 调整状态
				Q.enqueue(u);                                 // 入队
				status(v, u) = TREE;                          // 标记为TREE上一点
				parent(u) = v;                                // 标记v为u的parent
			}
			else
				status(v, u) = CROSS;                         // 若时访问过的点，则边标记为CROSS(非TREE上的点，跨边)
		status(v) = VISITED;                                  // 当前v节点访问完毕
	}
}


template <typename Tv, typename Te>
coid Graph<Tv, Te>::bfs(int s)                               // 图中所有点探索，每个点调用BFS()
{
	reset();
	int clock = 0;
	int v = s;
	do
	{
		if (status(v) == UNDISCOVERED)
			BFS(v, clock);
	} while (s != (v = (++v % n)));                          // 按编号顺序访问(环状的计数)，不露，转回初始点结束
}