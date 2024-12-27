#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int arraysum(int array[], int size)
{
	int answer = 0;

	for (int i = 0; i < size; i++)
	{
		answer += array[i];
	}

	return answer;
}

int average(int array[], int size)
{
	int answer = (arraysum(array, size)) / size;
	return answer;
}

void ascending_order(int a[], int size)
//�������� �Ϸ��� �ϴ� ó������ ���� �̵���Ű�鼭 �����ʿ� ū���� �ΰ�
//���� �ٲ��� ������ �� ���ڵ��� �Ѿ�� �ǳ�?
{
	bool check = true;
	while (check)
	{
		bool swapped = true; //�ٲ������� üũ�ϰ� �ѹ��̶� ������ �ٽùݺ�
		for (int i = 0; i < size - 1; i++)//���� ū���� �� �ʿ����
			//���������ΰ��� ū�� �ű��
		{
			if (a[i] > a[i + 1])
			{
				int change = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change;
				swapped = false;
			}
		}
		size--;//���� ���� ���� ū���� ������ �����״� ����� �ٿ����� �ݺ�
		if (check == swapped) check = false;//�ٲ�� ���ٸ� ������
	}
}

void descending_order(int a[], int size)
{
	bool check = true;
	while (check)
	{
		bool swapped = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (a[i + 1] > a[i])//���Ǹ� �ٲ��ֱ�
			{
				int change = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change;
				swapped = false;
			}
		}
		size--;
		if (check == swapped) check = false;
	}
}

int main()
{
	int size = 5;
	int Sum = 0;
	int avg = 0;

	cout << "�󸶳� ���ڸ� �Է��Ͻðڽ��ϱ� : ";
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> array[i];
	}

	Sum = arraysum(array, size);
	avg = average(array, size);
	cout << "�հ�� : " << Sum << endl;
	cout << "����� : " << avg << endl;
	cout << "�������� : ";
	ascending_order(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n�������� : ";
	descending_order(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	delete[] array;//�޸� ������ �ʼ�!
}