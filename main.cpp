#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int words = 0; //����������� ���� ����������� �� ������ ������
    vector<string> wordsInput; //������ ���������� ��������� �����
    wordsInput.resize(1); //����������, ��� ����������� ������ ������� 1
    int uniqueWord = 0; // ���������� ���������� ����
    vector<string> uniqueWords; //������ ���������� ����
    uniqueWords.resize(1);
    vector<int> repetitionWords; //� �� �������� ���������� ���������� ������� �����
    repetitionWords.resize(1);

    ifstream fin("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\input.txt", ifstream::in); // ���� �� �����
    ofstream fout("C:\\Users\\�������\\����� � ������\\������\\alex\\alex\\output.txt", ofstream::out); //����� � ����

    fin.seekg (0, fin.end); // ���������� ������� (|) � ����� �����
    int length = fin.tellg(); // �������� ��������� ������� � ��������� �� ���������� length
    fin.seekg (0, fin.beg); //���������� ������� � ������ �����

    vector<char> buffer; //buffer ��� ������ ��� ������ ���� ����� ����������� �������
    buffer.resize(length);
    fin.read (&buffer[0], length); //����������� ���������� �����
    //&buffer[0] �������� ����� ������� �������� �������, ��� ��� ��� �������������� readom ��� �����, �.�. fin.read ������� ��������� �� ������ �����, � �� ������

    for (int i = 0; i < length; i++) //���� �������� ����� �� �����
		{
			if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0') //��������, ���� ������ �� ������ � �� ������� �� ��������� ������, ������ ��� �����
			{
				wordsInput[words] += buffer[i];
			}
			else
			{

				if (wordsInput[words] != "")
				{
					wordsInput.push_back(""); //���� ������ �� 1, � ��������� ���� ������� ������ ��������
					words++; //������ ����� ���������� � ����� ������ � �������� ++
				}
			}
		}
    fin.close();

    for (int i = 1; i <= words; i++) //����������� ������������ ����� (���� ���������� �����)
	{
		bool flag = false; //����� true ���� � ������ ����������� ���������� �����

		for (int j = 0; j <= uniqueWord; j++) //���� ���������� ����
		{
			if (wordsInput[i] == uniqueWords[j])
			{
				repetitionWords[j]++;
				flag = true;
			}
		}

        if (!flag)
		{
			uniqueWords[uniqueWord] = wordsInput[i];
			repetitionWords[uniqueWord] = 1;
			uniqueWord++;
			uniqueWords.push_back("");
			repetitionWords.push_back(0);
		}
	}

	//fout.open("output.txt"); //����� ������ � ����
	for (int i = 0; i < uniqueWord; i++)
	{
		uniqueWords[i] += " - ";
		uniqueWords[i] += (repetitionWords[i] + '0');
		uniqueWords[i] += '\n';

		fout << uniqueWords[i];
	}
	fout.close();
    return 0;
}
