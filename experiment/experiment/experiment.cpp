#include<iostream>
#include<cstring>
using namespace std;
void clear(char* a[], int n) {
	int i = 0;
	for (i = 0; i<n; i++) {
		// �ͷŷ�����ڴ�
		delete[] a[i];
	}
}
int read(char* a[]) //����������ַ���
{
	char str[1000];
	char* s;
	char* p = nullptr;
	int i = 0;
    cin.getline(str, 1000);
	s = strtok_s(str, " ",&p);
	while (s!=NULL) {
		// Ϊÿ���ַ�������������ڴ�ռ�
		a[i] = new char[strlen(s) + 1];
		strcpy_s(a[i], strlen(s) + 1, s);
		i++;
		s = strtok_s(NULL, " ", &p);
	}
	return i;
}
void sort(char* a[], int n)//ʵ��ð������
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
void huiwen(char* a[], int n) //�жϻ���
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
			cout << "��" << i+1<< "���ַ���" <<b<< "Ϊ" << "����" << endl;
			m++;
		}
	}
	if (m == 0)
		cout << "û�л�����" << endl;
}
void write(char* a[], int number)//д����ȡ���ַ���
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
			cout << "1.�������ַ���,�Իس�����" << endl;
			cout<<"2.�����������ַ�������" << endl; 
			cout << "3.�����ַ�������" << endl;
			cout << "4.���һ�����" << endl;
			cout << "5.�˳�ϵͳ" << endl;
			cout << "���������ѡ��:";
			cin >> m;
			switch (m)
			{
			case 1:
				clear(a, number);
				cout << "�������ַ�������" << endl;
				cin.get();
				number = read(a);
				break;
			case 2:
				if (number == 0) {
					cout << "û���ַ��������Ƚ���1" << endl;
					break;
				}
				write(a, number);
				break;
			case 3:
				if (number == 0) {
					cout << "û���ַ��������Ƚ���1" << endl;
					break;
				}
				cout << "�����" << endl;
				sort(a, number);//����
				write(a, number);
				break;
			case 4:
				if (number == 0) {
					cout << "û���ַ��������Ƚ���1" << endl;
					break;
				}
				huiwen(a, number);//����
				break;
			case 5:
				clear(a, number);//���˳�ϵͳǰ�ͷ����һ���ַ�����ռ���ڴ�
				return 0;
			default:
				cout << "������������������" << endl;
				break;
			}
	}
}