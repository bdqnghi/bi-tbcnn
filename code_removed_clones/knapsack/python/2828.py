
# KNAP SACK - W
# n items {p[i], w[i]}
# many items of each type
# one item of each type
# max( sum(p[i] for i in S), sum(w[i] for i in S) <= W

# Greedy
I[i] = p[i] / w[i]
W - w[i]

# DP - one item
p[i]
w[i]

memo[W+1][n+1]

def solve(w, n):
	if n == 0:
		if w[0] < w:
			return p[0]
		else:
			return 0

	if memo[w][n] == -1:
		memo[w][n] = max(solve(w-w[n], n-1) + p[n], solve(w, n-1))
		return memo[w][n]
	else:
		return memo[w][n]
