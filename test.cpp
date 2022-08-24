#include <iostream>
using namespace std;

typedef long long LL;

int n;
const int N = 100010;
//int q[N];
int tmp[N];

LL merge_sort(int q[], int l, int r)//错误这个函数的返回类型写成int了
{
	if (l >= r) return 0;//错误1，写成return res;了
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1, k = 0;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tmp[k++] = q[i++];//错误，写成q[i] < q[j]了
		else
		{
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];//错误，写成i < r
	//错误上面要加一个int

	return res;
}

int main()
{
	//提交
	//cin >> n;
	//for (int i = 0; i < n; i++) cin >> q[i];

	//测试
	n = 7;
	int q[] = { 2, 3, 4, 5, 6, 1, 2 };
	for (int i = 0; i < n; i++) cout << q[i] << " ";
	cout << "\n";

	cout << merge_sort(q, 0, n - 1) << endl;
	for (int i = 0; i < n; i++) cout << q[i] << " ";
	cout << "\n";

	system("pause");
	return 0;
}

//**********************************************************************
//提交版本1
/*


#include <iostream>
using namespace std;

typedef long long LL;

int n ;
const int N = 100010;
int q[N];
int tmp[N];

LL merge_sort(int q[], int l, int r)
{
if (l >= r) return 0;//错误1，写成return res;了
int mid = (l + r) >> 1;
int i = l, j = mid + 1, k = 0;
LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

while (i <= mid && j <= r)
{
if (q[i] <= q[j]) tmp[k++] = q[i++];//错误，写成q[i] < q[j]了
else
{
tmp[k++] = q[j++];
res += mid - i + 1;
}
}
while (i <= mid) tmp[k++] = q[i++];
while (j <= r) tmp[k++] = q[j++];

for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];//错误，写成i < r

return res;
}

int main()
{
//提交
cin >> n;
for (int i = 0; i < n; i++) cin >> q[i];

//测试
//n = 7;
//int q[] = { 2, 3, 4, 5, 6, 1, 2 };
//for (int i = 0; i < n; i++) cout << q[i] << " ";
//cout << "\n";

cout << merge_sort(q, 0, n - 1) << endl;
//for (int i = 0; i < n; i++) cout << q[i] << " ";
//cout << "\n";

return 0;
}


*/
