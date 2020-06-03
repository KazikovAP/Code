#include <iostream>
#include <cstring>

#define MAXWORDCOUNT 1000
#define MAXSYMBOLCOUNT 10000

using namespace std;

int main()
{
	int currentWordCount = 0;
	int uniqueWordCount = 0;

	char fileInput[MAXSYMBOLCOUNT] = { '\0' };
	string parsedWordInput[MAXWORDCOUNT] = { { "" }, { "" } };
	string uniqueWordArray[MAXWORDCOUNT] = { { "" }, { "" } };

	int repetitionCounterArray[MAXWORDCOUNT] = { 0 };

	FILE* inputFileStream = fopen("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\input.txt", "r");

	//�������� ����� �� ����� ��� ������ ��������������� �������
	//fgets ��������� ���������
	while (fgets(fileInput, MAXSYMBOLCOUNT, inputFileStream) != NULL)
	{
		for (int i = 0; i < MAXSYMBOLCOUNT; i++)
		{
			if (fileInput[i] == '\0')
			{
				break;
			}
			if (fileInput[i] != ' ' && fileInput[i] != '\n')
			{
				parsedWordInput[currentWordCount] += fileInput[i];
			}
			else
			{
				//���� ������� ������ ��� ������ �������� �� ����� ������, � ��� ���� �������� �� ����� ����� �� ������, ����� ������� ���� �������������
				//� ��������� ������ � ������ ������ ��������� ������ �����
				if (parsedWordInput[currentWordCount] != "")
				{
					currentWordCount++;
				}
			}
		}
	}

	fclose(inputFileStream);


	//����������� ������������ �����
	for (int i = 1; i <= currentWordCount; i++)
	{
		int elementExists = 0;

		//���� �������� �� ������� ���������� ����, ��������� � ��������� ��������� ������. ���� ��������� ����������, ���������� ������������� ��������� �������� 1.
		//��� ���� ������� ���������� ������������� �� 1.
		for (int j = 0; j <= currentWordCount; j++)
		{
			if (parsedWordInput[i] == uniqueWordArray[j])
			{
				repetitionCounterArray[j]++;
				elementExists = 1;
			}
		}

		//���� ���������� ������������� �������� 0, �.�. ������ ����� �� �������, ��� ������������ � ����������, ��� ���� ������������ ���������� ���������� ����� ������� � 1
		if (!elementExists)
		{
			uniqueWordArray[uniqueWordCount] = parsedWordInput[i];
			repetitionCounterArray[uniqueWordCount] = 1;

			uniqueWordCount++;
		}
	}

	FILE* outputFileStream = fopen("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\output.txt", "w");

	//������� �� cstring ������� � ���������� �������� ������, ����� � ������ char ��� ������� fputs.
	for (int i = 0; i < uniqueWordCount; i++)
	{
		char fileOutput[MAXSYMBOLCOUNT] = { '\0' };

		uniqueWordArray[i] += " - ";
		uniqueWordArray[i] += (repetitionCounterArray[i] + '0');
		uniqueWordArray[i] += '\n';
		int j = 0;

		while (uniqueWordArray[i][j] != '\0')
		{
			fileOutput[j] = uniqueWordArray[i][j];
			j++;
		}

		fputs(fileOutput, outputFileStream);
	}

	fclose(outputFileStream);
}
