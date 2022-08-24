#include <iostream>
#include <vector>
// #include "include/seqList.h"
#include "include/linkList.h"

using namespace std;

int main()
{
	// 测试 SeqList
	// SeqList<int> L1 = SeqList<int>(10);
	// L1.insert(0, 1);
	// L1.insert(1, 2);
	// L1.insert(2, 5);

	// cout << L1.length() << endl;
	// L1.traverse();

	// L1.clear();
	// L1.traverse();

	// 测试 LinkList
	LinkList<int> L1 = LinkList<int>();
	cout << L1.length() << endl;
	L1.insert(0, 1);
	L1.insert(1, 2);
	L1.insert(2, 3);
	L1.insert(3, 4);
	L1.insert(4, 5);
	L1.insert(5, 6);

	cout << L1.length() << endl;
	// L1.clear();
	// cout << L1.length() << endl;
	cout << L1.search(5) << endl;
	L1.traverse();
	L1.remove(3);	// 有点问题
	L1.traverse();
	// system("pause");
	return 0;
}