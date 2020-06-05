#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int words; //����������� ���� ����������� �� ������ ������
    vector<string> wordsInput; //������ ���������� ��������� �����
    int uniqueWord; // ���������� ���������� ����
    vector<string> uniqueWords; //������ ���������� ����
    vector<int> repetitionWords; //� �� �������� ���������� ���������� ������� �����

    ifstream fin("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\input.txt", ifstream::in); // ���� �� �����
    ofstream fout("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\output.txt", ofstream::out); //����� � ����

    fin.seekg (0, fin.end); //����������� ����� �����
    int length = fin.tellg(); //length ����� ������� �����������
    fin.seekg (0, fin.beg);

    char* buffer; //buffer ��� ������ ��� ������ ���� ����� ����������� �������
    fin.read (buffer, length); //����������� ���������� �����

    for (int i = 0; i < length; i++) //���� �������� ����� �� �����
		{
			if (buffer[i] != ' ' && buffer[i] != '\n') //��������, ���� ������ �� ������ � �� ������� �� ��������� ������, ������ ��� �����
			{
				wordsInput[words] += buffer[i];
			}
			else
			{

				if (wordsInput[words] != "")
				{
					words++; //������ ����� ���������� � ����� ������ � �������� ++
				}
			}
		}
    fin.close();

    for (int i = 1; i <= words; i++) //����������� ������������ ����� (���� ���������� �����)
	{
		bool flag = false; //����� true ���� � ������ ����������� ���������� �����

		for (int j = 0; j <= words; j++) //���� ���������� ����
		{
			if (wordsInput[i] == uniqueWords[j])
			{
				repetitionWords[j]++;
				bool flag = true;
			}
		}

        if (!flag)
		{
			uniqueWords[uniqueWord] = wordsInput[i];
			repetitionWords[uniqueWord] = 1;

			uniqueWord++;
		}
	}

	fout.open("output.txt"); //����� ������ � ����
	for (int i = 0; i < uniqueWord; i++)
	{
		//vector<char> outputs; //� ���� ����� ��������� �� ��� ����� ������� � ����

		uniqueWords[i] += " - ";
		uniqueWords[i] += (repetitionWords[i]);
		uniqueWords[i] += '\n';

		fout << uniqueWords[i];
	}
	fout.close();
    return 0;
}
