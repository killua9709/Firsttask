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
//오름차순 하려면 일단 처음부터 끝을 이동시키면서 오른쪽에 큰값을 두고
//만약 바뀌지 않으면 그 숫자들은 넘어가도 되나?
{
	bool check = true;
	while (check)
	{
		bool swapped = true; //바꼈는지를 체크하고 한번이라도 됐으면 다시반복
		for (int i = 0; i < size - 1; i++)//제일 큰수는 할 필요없지
			//오른쪽으로가며 큰수 옮기기
		{
			if (a[i] > a[i + 1])
			{
				int change = a[i];
				a[i] = a[i + 1];
				a[i + 1] = change;
				swapped = false;
			}
		}
		size--;//제일 끝은 제일 큰수가 무조건 있을테니 사이즈를 줄여가며 반복
		if (check == swapped) check = false;//바뀐게 없다면 나가기
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
			if (a[i + 1] > a[i])//조건만 바꿔주기
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

	cout << "얼마나 숫자를 입력하시겠습니까 : ";
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "숫자를 입력해주세오 : ";
		cin >> array[i];
	}

	Sum = arraysum(array, size);
	avg = average(array, size);
	cout << "합계는 : " << Sum << endl;
	cout << "평균은 : " << avg << endl;
	cout << "오름차순 : ";
	ascending_order(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n내림차순 : ";
	descending_order(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	delete[] array;//메모리 해제는 필수!
}