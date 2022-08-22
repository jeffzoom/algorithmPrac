#include <iostream>
using namespace std;

//const int N = 10e6;
int q[] = { 5, 9, 6, 4, 4, 3, 8, 0, 1, 6 };
//int q[N];

int quickFind_K(int l, int r, int k)
{
	if (l == r) return q[l];

	int i = l - 1, j = r + 1, x = q[l];
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);//错误1，写成i > j
	}
	int ls = j - l + 1;
	if (ls >= k) return quickFind_K(l, j, k);//错误3，写成ls > k了
	return quickFind_K(j + 1, r, k-ls);//错误2,写成(j + 1, r, k)了

}

int main()
{
	int n = 10, k = 2;//输入n个整数，从小到大第k个；0, 1, 3，4, 4, 5，6，6，8, 9
	//                                          顺序1, 2，3, 4, 5, 6, 7, 8, 9, 10  
	//int q[N] = { 5, 9, 6, 4, 4, 3, 8, 0, 1, 6 };

	//cin >> n >> k;
	//for (int i = 0; i < n; i++) cin >> q[i];

	//for (int i = 0; i < n; i++) cout << quickFind_K(0, n - 1, k);
	cout << quickFind_K(0, n - 1, k) << endl;

	system("pause");
	return 0;

}
