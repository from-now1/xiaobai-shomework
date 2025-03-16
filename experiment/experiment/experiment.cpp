#include<iostream>
#include<cstring>
using namespace std;
void clear(char* a[], int n) {
	int i = 0;
	for (i = 0; i<n; i++) {
		// 释放分配的内存
		delete[] a[i];
	}
}
int read(char* a[]) //读入输入的字符串
{
	char str[1000];
	char* s;
	char* p = nullptr;
	int i = 0;
    cin.getline(str, 1000);
	s = strtok_s(str, " ",&p);
	while (s!=NULL) {
		// 为每个字符串分配独立的内存空间
		a[i] = new char[strlen(s) + 1];
		strcpy_s(a[i], strlen(s) + 1, s);
		i++;
		s = strtok_s(NULL, " ", &p);
	}
	return i;
}
void sort(char* a[], int n)//实现冒泡排序
{
	int i = 0, j = 0;
	for (i = 0; i <= n - 2; i++) {
		for (j = n - 2; j >= i; j--) {

			if (strcmp(a[j], a[j + 1]) > 0)
			{
				char* temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void huiwen(char* a[], int n) //判断回文
{
	int i = 0, j = 0, m = 0;
	for (i = 0; i < n; i++) {
		int s = 0;
		char* b = a[i];
		int len = strlen(b);
		for(j=0;j<len/2;j++){
			if (b[j] == b[len - 1 - j]) {
				s++;
			}
			else
				break;
		}
		if (s == len / 2) {
			cout << "第" << i+1<< "个字符串" <<b<< "为" << "回文" << endl;
			m++;
		}
	}
	if (m == 0)
		cout << "没有回文数" << endl;
}
void write(char* a[], int number)//写出读取的字符串
{
	for (int i = 0; i < number; i++) {
		cout  << a[i] << " ";
	}
	cout << endl;
}
int main() {
    char* a[100];
    int number=0;
	int m = 0;
	while (1) {
			cout << "1.请输入字符串,以回车结束" << endl;
			cout<<"2.输出所输入的字符串数组" << endl; 
			cout << "3.排序字符串数组" << endl;
			cout << "4.查找回文数" << endl;
			cout << "5.退出系统" << endl;
			cout << "请输入你的选择:";
			cin >> m;
			switch (m)
			{
			case 1:
				clear(a, number);
				cout << "请输入字符串数组" << endl;
				cin.get();
				number = read(a);
				break;
			case 2:
				if (number == 0) {
					cout << "没有字符串，请先进行1" << endl;
					break;
				}
				write(a, number);
				break;
			case 3:
				if (number == 0) {
					cout << "没有字符串，请先进行1" << endl;
					break;
				}
				cout << "排序后：" << endl;
				sort(a, number);//排序
				write(a, number);
				break;
			case 4:
				if (number == 0) {
					cout << "没有字符串，请先进行1" << endl;
					break;
				}
				huiwen(a, number);//回文
				break;
			case 5:
				clear(a, number);//在退出系统前释放最后一次字符串所占的内存
				return 0;
			default:
				cout << "输入有误，请重新输入" << endl;
				break;
			}
	}
}