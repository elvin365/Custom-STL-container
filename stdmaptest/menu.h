#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Map.h"
#include <fstream>
#include<iostream>
#include <algorithm>
//#include<string>
using namespace std;

class menu
{
private:

	static void upp(string& str);
public:
	template<class T, class R>
	static void addpet(Map<T,R> &mymap);
	template<class T, class R>
	static void showpets(Map<T, R> &mymap);
	template<class T, class R>
	static void findpet(Map<T, R>& mymap);
	template<class T, class R>
	static void countpets(Map<T, R>& mymap);
	template<class T, class R>
	static void droppet(Map<T, R>& mymap);
	static char choose();
	template<class T, class R>
	static void loadfile(Map<T, R>& mymap);
	template<class T, class R>
	static void r_showpets(Map<T, R> &mymap);
};
void menu::upp(string& str)
{
	//unsigned k = str.length();
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	/*for (unsigned i = 0; i < k; i++)
	{
		str[i] = toupper(str[i]);
	}*/

}
template<class T, class R>
void menu::addpet(Map<T, R> &mymap)
{
	std::pair<T,R> l_inf;
	cout << "Please enter name of pet: " << endl;
	cin.ignore(32767, '\n');
	getline(std::cin, l_inf.first);//index to insert
	cout << "Please enter pet kind: " << endl;//info by this index
	getline(std::cin, l_inf.second);
	upp(l_inf.first);
	upp(l_inf.second);
	mymap.insert(l_inf);
}
template<class T, class R>
void menu::showpets(Map<T, R> &mymap)
{
	if (mymap.empty())
	{
		cerr << "No entries!";
	}
	else
		//.Traverse();
	{
		//auto it = mymap.begin();
		typename Map<T, R>::MyIterator it = mymap.begin();
		for (; it != mymap.end(); /*++it*/++it)
		{
			cout << it->first << " is a " << it->second << '\n';
		}//[begin,end) поэтому до¬ыводим
		it = mymap.end();
		cout << it->first << " is a " << it->second << '\n';
	}

}
template<class T, class R>
void menu::findpet(Map<T, R>& mymap)
{

	std::pair<T, R> l_inf;

	
	if (mymap.empty())
	{
		cerr << "No entries!";
		return;
	}

	
	cout << "Please enter name of pet: " << endl;
	cin.ignore(32767, '\n');
	getline(std::cin, l_inf.first);//index to insert
	cout << "Please enter pet kind: " << endl;//info by this index
	getline(std::cin, l_inf.second);
	upp(l_inf.first);
	upp(l_inf.second);


	cout << l_inf.first << " " << l_inf.second << " ";
	typename Map<T, R>::MyIterator it = mymap.find(l_inf.first);
	if (it.first!="\0")
	{
		cout << "is a member!" << endl;
	}
	else
		cout << "is not a member!" << endl;

}
template<class T, class R>
void menu::countpets(Map<T, R>& mymap)
{
	cout << "There are " << mymap.size() << " pets" << endl;
}
template<class T, class R>
void menu::droppet(Map<T, R>& mymap)
{
	std::pair<T, R> l_inf;


	if (mymap.empty())
	{
		cerr << "No entries!";
		return;
	}

	cout << "Please enter name of pet you wish to delete: " << endl;
	//std:sin >> temp.Name;
	cin.ignore(32767, '\n');
	getline(std::cin, l_inf.first);
	cout << "Please enter pet kind: " << endl;
	getline(std::cin, l_inf.second);
	upp(l_inf.first);
	upp(l_inf.second);
	cout << l_inf.first << " " << l_inf.second;

	if (mymap.erase(l_inf.first))
	{
		cout << " is deleted from the club" << endl;
	}
	else
		cout << " is not a member" << endl;


}

char menu::choose()
{
	char ch;
	cout << "Nerfville Pet Club Membership Program" << endl;
	cout << "Enter the letter corresponding to your choice:" << endl;
	cout << "a) add a pet          l) show list of pets" << endl;
	cout << "n) number of pets     f) find pets" << endl;
	cout << "d) delete a pet       q) quit" << endl;
	cout << "p)load from file      r) show list of pets reverse"<< endl;

	string letters = "alrfndq";
	while (1)
	{
		cin >> ch;
		//cin.ignore(32767, '\n');
		ch = tolower(ch);
		if (!(letters.find_first_of(ch, 1)))
		{
			cerr << "Please enter an a,l,n,f,d,q";
		}
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';

	return ch;
}
template<class T, class R>
void menu::loadfile(Map<T, R>& mymap)
{
	string str;
	char* forstr;
	pair<T, R> l_inf;
	
	ifstream myfile("C:\\Users\\Elvin\\source\\repos\\chtomnedelat1\\petsdata.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, str, '\n'))
		{
			char *cstr = new char[str.length() + 1];
			strcpy(cstr, str.c_str());
			// do stuff
			forstr = strtok(cstr, " ");
			while (forstr)
			{
				if (l_inf.first != "\0")
				{
					l_inf.second = forstr;

				}
				if (l_inf.first == "\0")
				{
					l_inf.first = forstr;
				}

				forstr = strtok(NULL, " ");
			}
			upp(l_inf.first);
			upp(l_inf.second);
			mymap.insert(l_inf);
			l_inf.first = "\0";
			l_inf.second = "\0";
			delete[] cstr;
		}

		myfile.close();
	}
}

template<class T, class R>
void menu::r_showpets(Map<T, R>& mymap)
{
	if (mymap.empty())
	{
		cerr << "No entries!";
	}
	else
		//.Traverse();
	{
		//auto it = mymap.begin();
		typename Map<T, R>::r_MyIterator rit = mymap.rbegin();
		for (; rit != mymap.rend(); rit++)
		{
			cout << rit->first << " is a " << rit->second << '\n';
		}//[begin,end) поэтому до¬ыводим
		rit = mymap.rend();
		cout << rit->first << " is a " << rit->second << '\n';
	}

}
