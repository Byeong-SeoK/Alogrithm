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
	for (int temp1 = 0; temp1 < T; temp1++)  //testcase로 주어진 T번 만큼 실행
	{
		long long int result=0;
		fin >> M >> N >> D;     //M,N,D값을 입력으로 받는다.
		int** yard= new int* [M]; //M*N크기의 2차원 동적배열 yard를 만든다

		for (int i = 0; i < M; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
			yard[i] = new int[N];

		

		
		int* oil = new int[D]; //기름 Ki를 저장하는 1차원 동적배열 oil

		for (int row = 0; row < M; row++)    //이중 for문으로 부터 input으로 주어진 값들을 yard에 담는다.
		{
			for (int col = 0; col < N; col++)
			{
				int temp;
				fin >> temp;
				yard[row][col] = temp;
			}
		}

		for (int i = 0; i < D; i++)    //for문으로 부터 input으로 주어진 기름의 값들을 oil에 담는다.
		{
			int temp;
			fin >> temp;
			oil[i] = temp;
		}

		for (int temp2 = 0; temp2 < D; temp2++)  //각각의 testcase마다 D번 만큼 수행
		{
			for (int row = 0; row < M; row++)    //이중 for문으로 부터 input으로 주어진 값들을 yard에 담는다.
			{
				for (int col = 0; col < N; col++)
				{
					yard[row][col] = yard[row][col] + 1;
				}
			}
			
			int number = oil[temp2];   //temp2일차의 기름의 양(Ki)를 oil배열에서 가져와 number배열에 담는다
			int* max = new int[number];   //number크기 만큼 max값을 저장하는 1차원 동적배열 max
			int* max_X = new int[number];  //각각 max값의 x좌표를 저장하는 1차원 동적 배열 max_X
			int* max_Y = new int[number];  //각각 max값의 y좌표를 저장하는 1차원 동적 배열 max_Y
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