//Chin Ho Mitchell Lam
//11/4/2019
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<string> ReadFile(string FileName);

int main()
{
	//check run time
	//auto start = high_resolution_clock::now();

	vector<string> _data;

	string s;
	while (getline(cin,s))
	{
		_data.push_back(s);
	}

	//_data = ReadFile("strings1000.txt");

	map<string, vector<string>> Output;

	for (auto i : _data)//check target
	{
		for (auto j : _data)//check others
		{
			if (i.length() == j.length() && i != j)//if same length
			{
				int Sameletter = 0;//track how many letters are the same

				for (int index = 0; index < i.length(); index++)//each letter i
				{
					if (i[index] == j[index])//if same letter
					{
						Sameletter++;
					}
					else
					{
						continue;
					}
				}

				//if only one letter is different
				if (Sameletter == i.length() - 1)
				{
					Output.insert(pair<string, vector<string>>(i, vector<string>()));//init target as key, and an empty vector as value
					Output[i].push_back(j);// insert value
				}
			}
		}
	}

	for (auto i : Output)
	{
		cout << i.first << " ";
		for (auto j : i.second)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	//auto stop = high_resolution_clock::now();
	//
	//auto duration = duration_cast<seconds>(stop - start);
	//
	//cout << duration.count() << endl;

	getchar();
	getchar();
	return 0;
}

vector<string> ReadFile(string FileName)
{
	ifstream myfile;
	string line;
	vector<string> temp;
	myfile.open(FileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			temp.push_back(line);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to read file" << endl;
	}

	return temp;
}