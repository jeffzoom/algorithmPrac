#include <iostream>
using namespace std;

typedef long long LL;

int n;
const int N = 100010;
//int q[N];
int tmp[N];

LL merge_sort(int q[], int l, int r)//������������ķ�������д��int��
{
	if (l >= r) return 0;//����1��д��return res;��
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1, k = 0;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tmp[k++] = q[i++];//����д��q[i] < q[j]��
		else
		{
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];//����д��i < r
	//��������Ҫ��һ��int

	return res;
}

int main()
{
	//�ύ
	//cin >> n;
	//for (int i = 0; i < n; i++) cin >> q[i];

	//����
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
//�ύ�汾1
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
if (l >= r) return 0;//����1��д��return res;��
int mid = (l + r) >> 1;
int i = l, j = mid + 1, k = 0;
LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

while (i <= mid && j <= r)
{
if (q[i] <= q[j]) tmp[k++] = q[i++];//����д��q[i] < q[j]��
else
{
tmp[k++] = q[j++];
res += mid - i + 1;
}
}
while (i <= mid) tmp[k++] = q[i++];
while (j <= r) tmp[k++] = q[j++];

for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];//����д��i < r

return res;
}

int main()
{
//�ύ
cin >> n;
for (int i = 0; i < n; i++) cin >> q[i];

//����
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
