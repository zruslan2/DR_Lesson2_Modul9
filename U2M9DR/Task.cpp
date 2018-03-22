#include <stdio.h>
#include <cctype>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include "MyFunc.h"

using namespace std;
unsigned short int nz;

void main()
{
	setlocale(LC_ALL, "Rus");
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	srand(time(NULL));

	int i, j;
	while (true)
	{
		cout << "������� ����� �������, 0 - ��� ������ "; cin >> nz; cin.get();

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*1.	������ ������������ �����.������� ������ �� ���� �����, ���� �� ���������� 
			����� 10. ��������� ����� ������������� ��������� �������*/
			head("1. ������ ������������ �����.������� ������ �� ���� �����, ���� �� ���������� ����� 10. ��������� ����� ������������� ��������� �������");
			int sum = 0, razm = 0;
			int c;
			int *numbers = NULL;
			int *m;
			do
			{
				printf("������� ����� (10 - ��� ������): ");
				scanf("%d", &c);
				razm++;
				m = (int*)realloc(numbers, razm * sizeof(int));
				if (m != NULL)
				{
					numbers = m;
					numbers[razm - 1] = c;
				}
				else
				{
					free(numbers);
					printf("������ ��������� ������");
					system("exit");
				}
			} while (c != 10);

			for (int i = 0; i < razm; i++)
			{
				if (numbers[i] < 0)sum += numbers[i];
			}
			printf("����� ������������� ��������� = %d\n", sum);
			free(numbers);
		}
		else if (nz == 2)
		{
			/*2.	������ � StringGrid ������ �� 10 ����� �����. ������� ��� ����� ������� � �� 
			������������� � ������������� ��������� ��������� �������. ���������� ����� ��������� 
			������� �������.*/
			head("2. ������ � StringGrid ������ �� 10 ����� �����. ������� ��� ����� ������� � �� ������������� � ������������� ��������� ��������� �������. ���������� ����� ��������� ������� �������.");
			int StringGrid[10] = { 10,-6,-9,2,-10,45,-24,22,90,-50 };
			int pol = 0, otr = 0;
			printf("StringGrid:");
			for (int i = 0; i < 10; i++)
			{
				printf("\t%d", StringGrid[i]);
				if (StringGrid[i] > 0)pol++;
				else otr++;
			}
			int *P;
			int *O;
			int SP=0, SO=0;
			P = (int*)calloc((pol), sizeof(int));
			O = (int*)calloc((otr), sizeof(int));
			for (int i = 0; i < 10; i++)
			{
				if (StringGrid[i] > 0)
				{
					*P = StringGrid[i];
					SP += *P;
					P++;
				}
				else
				{
					*O = StringGrid[i];
					SO += *O;
					O++;
				}
			}
			printf("\n����� ��������� ������� ������������� ����� = %d\n", SP);
			printf("����� ��������� ������� ������������� ����� = %d\n", SO);
		}
		else if (nz == 4)
		{
			/*4.	������ ������������ �����.������� ������ �� ������������� �����.����������, 
			�������� �� ������ ������������� �� �����������.*/
			head("4. ������ ������������ �����. ������� ������ �� ������������� �����. ����������, �������� �� ������ ������������� �� �����������.");
			int sum = 0, razm = 0;
			int c;
			int *numbers = NULL;
			int *m;
			do
			{
				printf("������� ����� (0 - ��� ������): ");
				scanf("%d", &c);
				if (c > 0)
				{
					razm++;
					m = (int*)realloc(numbers, razm * sizeof(int));
					if (m != NULL)
					{
						numbers = m;
						numbers[razm - 1] = c;
					}
					else
					{
						free(numbers);
						printf("������ ��������� ������");
						system("exit");
					}
				}
			} while (c != 0);
			int b = 1;
			for (int i = 0; i < razm-1; i++)
			{
				if (numbers[i + 1] < numbers[i])b = 0;
			}
			if (b == 1)printf("������ ���������� �� �����������\n");
			else printf("������ �� ���������� �� �����������\n");
		}
		else
		{
			red();
			cout << "������ ������� �� ���������� \n";
			white();
		}
	}
}