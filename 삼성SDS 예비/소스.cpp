#include <iostream>
#include<fstream>
using namespace std;

void Find_max(int** yard, int number,int M,int N,int* max,int* max_X,int* max_Y)
{
	for (int row = 0; row < M; row++)    
	{
		for (int col = 0; col < N; col++)
		{
			int digit = yard[row][col];
			for (int index = 0; index < number; index++)
			{
				if (digit > max[index])
				{
					for (int i = number-2; i >= index; i--)
					{
						max[i + 1] = max[i];
						max_X[i + 1] = max_X[i];
						max_Y[i + 1] = max_Y[i];
					}
					max[index] = digit;
					max_X[index] = row;
					max_Y[index] = col;
					break;
				}
				
			}
		}
	}
	return;
}

long long int Mow_yard(int** yard, int number,int* max,int* max_X, int* max_Y)
{
	long long int result = 0;
	for (int i = 0; i < number; i++)
	{
		result = result + (max[i] - 1);
		yard[max_X[i]][max_Y[i]] = 1;
	}
	return result;

}





int main()
{
	ifstream fin;
	fin.open("sample_input.txt");
	 int T, M, N,D;
	fin >> T;
	for (int temp1 = 0; temp1 < T; temp1++)  //testcase�� �־��� T�� ��ŭ ����
	{
		long long int result=0;
		fin >> M >> N >> D;     //M,N,D���� �Է����� �޴´�.
		int** yard= new int* [M]; //M*Nũ���� 2���� �����迭 yard�� �����

		for (int i = 0; i < M; i++) //������ �ε����� �����ϰ��� �ϴ� �迭�� ũ�⸸ŭ�� ����Ű�� ��.
			yard[i] = new int[N];

		

		
		int* oil = new int[D]; //�⸧ Ki�� �����ϴ� 1���� �����迭 oil

		for (int row = 0; row < M; row++)    //���� for������ ���� input���� �־��� ������ yard�� ��´�.
		{
			for (int col = 0; col < N; col++)
			{
				int temp;
				fin >> temp;
				yard[row][col] = temp;
			}
		}

		for (int i = 0; i < D; i++)    //for������ ���� input���� �־��� �⸧�� ������ oil�� ��´�.
		{
			int temp;
			fin >> temp;
			oil[i] = temp;
		}

		for (int temp2 = 0; temp2 < D; temp2++)  //������ testcase���� D�� ��ŭ ����
		{
			for (int row = 0; row < M; row++)    //���� for������ ���� input���� �־��� ������ yard�� ��´�.
			{
				for (int col = 0; col < N; col++)
				{
					yard[row][col] = yard[row][col] + 1;
				}
			}
			
			int number = oil[temp2];   //temp2������ �⸧�� ��(Ki)�� oil�迭���� ������ number�迭�� ��´�
			int* max = new int[number];   //numberũ�� ��ŭ max���� �����ϴ� 1���� �����迭 max
			int* max_X = new int[number];  //���� max���� x��ǥ�� �����ϴ� 1���� ���� �迭 max_X
			int* max_Y = new int[number];  //���� max���� y��ǥ�� �����ϴ� 1���� ���� �迭 max_Y
			for (int i = 0; i < number; i++)
			{
				max[i] = 0;
				max_X[i] = 0;
				max_Y[i] = 0;
			}

			//Find_max(yard, number,M,N, max, max_X, max_Y);
			for (int row = 0; row < M; row++)
			{
				for (int col = 0; col < N; col++)
				{
					int digit = yard[row][col];
					for (int index = 0; index < number; index++)
					{
						if (digit > max[index])
						{
							for (int i = number - 2; i >= index; i--)
							{
								max[i + 1] = max[i];
								max_X[i + 1] = max_X[i];
								max_Y[i + 1] = max_Y[i];
							}
							max[index] = digit;
							max_X[index] = row;
							max_Y[index] = col;
							break;
						}

					}
				}
			}
			//
			
			//result=result+ (temp2+1)*Mow_yard(yard, number, max, max_X, max_Y);
			long long int result_temp = 0;
			for (int i = 0; i < number; i++)
			{
				result_temp = result_temp + (max[i] - 1);
				yard[max_X[i]][max_Y[i]] = 1;
			}
			result = result + (temp2 + 1) * result_temp;
			//
			delete[] max;
			delete[] max_X;
			delete[] max_Y;

		}
		cout << "#" << temp1 + 1 << " " << result << endl;
		delete[] oil;
		for (int i = 0; i < M; i++)
			delete[] yard[i];

		delete[] yard;

	}
}