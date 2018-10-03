/*
ID: tangjin2
LANG: C++
TASK: milk3
*/
#include <cstdio>
int lim[3], stack[400][3], head, tail;
bool used[21], hash[10001];
int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	int i, r, a, b, c;
	scanf("%d%d%d", &lim[0], &lim[1], &lim[2]);
	stack[0][2] = lim[2];
	used[lim[2]] = 1;
	hash[lim[2]] = 1;
	while(head <= tail)
	{
		r = tail;
		for(i = head; i <= tail; ++i)
		{
			if(!stack[i][0]) used[stack[i][2]] = 1;
			if(stack[i][0])
			{
				if(stack[i][1] < lim[1])
				{
					c = stack[i][2];
					if(stack[i][0] < lim[1] - stack[i][1]) a = 0, b = stack[i][0] + stack[i][1];
					else a = stack[i][0] + stack[i][1] - lim[1], b = lim[1];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
				if(stack[i][2] < lim[2])
				{
					b = stack[i][1];
					if(stack[i][0] < lim[2] - stack[i][2]) a = 0, c = stack[i][0] + stack[i][2];
					else a = stack[i][0] + stack[i][2] - lim[2], c = lim[2];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
			}
			if(stack[i][1])
			{
				if(stack[i][0] < lim[0])
				{
					c = stack[i][2];
					if(stack[i][1] < lim[0] - stack[i][0]) b = 0, a = stack[i][0] + stack[i][1];
					else b = stack[i][0] + stack[i][1] - lim[0], a = lim[0];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
				if(stack[i][2] < lim[2])
				{
					a = stack[i][0];
					if(stack[i][1] < lim[2] - stack[i][2]) b = 0, c = stack[i][1] + stack[i][2];
					else b = stack[i][1] + stack[i][2] - lim[2], c = lim[2];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
			}
			if(stack[i][2])
			{
				if(stack[i][0] < lim[0])
				{
					b = stack[i][1];
					if(stack[i][2] < lim[0] - stack[i][0]) c = 0, a = stack[i][0] + stack[i][2];
					else c = stack[i][0] + stack[i][2] - lim[0], a = lim[0];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
				if(stack[i][1] < lim[1])
				{
					a = stack[i][0];
					if(stack[i][2] < lim[1] - stack[i][1]) c = 0, b = stack[i][1] + stack[i][2];
					else b = stack[i][1] + stack[i][2] - lim[1], c = lim[1];
					if(!hash[((a * 21) + b) * 21 + c])
					{
						++r;
						stack[r][0] = a, stack[r][1] = b, stack[r][2] = c;
						hash[((a * 21) + b) * 21 + c] = 1;
					}
				}
			}
		}
		head = tail + 1;
		tail = r;
	}
	for(i = lim[2] - lim[1] > 0 ? lim[2] - lim[1] : 0; i < lim[2]; ++i) if(used[i]) printf("%d ", i);
	printf("%d\n", i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
