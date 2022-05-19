#include <iostream>

using namespace std;

int m, MOD = 1000003;

struct Math // with MOD 1000003
{
	long pow_mod(long a, long p)
	{
		if (a >= m) a %= MOD;
		if (a == 0) return 0;
		if (p == 0) return 1;
		long t = pow_mod(a, p / 2);
		if (p & 1) return a * t % MOD * t % MOD;
		return t*t % MOD;
	}
	long inverse(long a) { return pow_mod(a, MOD - 2); }
	long C_MOD(long n, long k)
	{
		long ans = 1;
		if (k > n / 2) k = n - k;
		for (int i = 1; i <= k; i++)
		{
			ans *= n - k + i;
			ans %= MOD;
			ans *= inverse(i);
			ans %= MOD;
		}
		return ans;
	}
} math;

struct BST
{
	struct node {
		int val, sz, F;
		node *ch[2];
	} *root;
	void Del(node* T)
	{
		if (!T) return;
		Del(T->ch[0]);
		Del(T->ch[1]);
		delete T;
	}
	void reset()
	{
		Del(root);
		root = nullptr;
	}
	int getsz(node *T) { return T ? T->sz : 0; }
	void insert(int v, node* &T)
	{
		if (!T)
		{
			T = new node();
			T->val = v;
			T->sz = 1;
		}
		else
		{
			insert(v, T->ch[v > T->val]);
			T->sz = getsz(T->ch[0]) + getsz(T->ch[1]) + 1;
		}
	}
	int f(node* T)
	{
		if (!T) return 1;
		if (T->F) return T->F;
		return T->F = (long)f(T->ch[0]) * f(T->ch[1]) % MOD \
			* math.C_MOD(getsz(T->ch[0]) + getsz(T->ch[1]), getsz(T->ch[0])) % MOD;
	}
} bst;

int main()
{
	int T, n, A[1010];
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
		//build_BST();
		bst.reset();
		for (int i = 1; i <= n; i++) bst.insert(A[i], bst.root);
		int ans = bst.f(bst.root) * math.C_MOD(m, n) % MOD;
		printf("%d\n", ans);
	}
}
