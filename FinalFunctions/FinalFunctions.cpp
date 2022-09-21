// ������������ ������
#include <iostream>
#include <ctime>
#include <cstdlib>
//���������� ������� ���������� ������� �� begin �� end
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//����� ������� arr � �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void Middle_sort(T arr[], const int length) {
	int FirstIndex = 0, LastIndex = 0;
	for(int i =0;i<length;i++)
		if (arr[i] < 0) {
			FirstIndex = i; break;
		}
	for (int i = length-1; i >=0; i--)
		if (arr[i] < 0) {
			LastIndex = i; break;
		}
	//����������� ����������
	for (int i = LastIndex-1; i > 0; i--)
		for (int j = FirstIndex+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	//������� ����������
	sort(arr + FirstIndex + 1, arr + LastIndex - 1);
		
}
void type_off(int num);
template <typename T>
void move_arr(T arr[], const int length, int num);
void type_off(double num);
void type_off(char num);
int Sym_AtoB(int A, int B);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������ 1. ����� ���� ������ 
	/*
	std::cout << "������ 1.\n";
	std::cout << "12 - ";
	type_off(12);
	std::cout << "9.11 - ";
	type_off(9.11);
	std::cout << "\'T\' - ";
	type_off('T');
	
	//������ 2.�������� �� A �� B
	std::cout << "������� ��� �����:";
	std::cin >> n >> m;
	std::cout << "����� ����� �� A �� B = " << Sym_AtoB(n, m) << '\n';
	
	//������ 3. ���������� ������ �������
	std::cout<<"����������� ������:\n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	Middle_sort(arr3, size3);
	std::cout << "�������� ������:\n";
	show_arr(arr3, size3);
	std::cout << '\n';
	*/
	//������� 4.����� �������
	std::cout << "��������� ������:\n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	show_arr(arr4, size4);
	std::cout << "������� ���������� �������:\n";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "�������� ������:\n";
	show_arr(arr4, size4);
	return 0;
}
//������ 1
void type_off(int num) {
	std::cout << "INT" << '\n';
}
void type_off(double num) {
	std::cout << "DOUBLE" << '\n';
}
void type_off(char num) {
	std::cout << "CHAR" << '\n';
}
//������ 2
int Sym_AtoB(int A, int B) {
	if (B == A+1)
		return A+B;
	return Sym_AtoB(A, B - 1)+B;
}
//������ 4
template <typename T>
void move_arr(T arr[], const int length, int num) {
	if(num >=0) //����� ������
		for (int j =0;j<num;j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i + 1]);
	else         //����� �����
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length-1; i++)
				std::swap(arr[i], arr[i + 1]);
	}