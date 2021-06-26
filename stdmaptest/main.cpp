#define _CRT_SECURE_NO_WARNINGS
#include"Map.h"
#include"menu.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{
	
	Map<string, string> hash_table;
	char choise;
	while ((choise = menu::choose()) != 'q')
	{
		switch (choise)
		{
		case 'a': menu::addpet(hash_table); break;
		case'l': menu::showpets(hash_table); break;
		case'f': menu::findpet(hash_table); break;
		case'd':menu::droppet(hash_table); break;
		case'n':menu::countpets(hash_table); break;
		case'p':menu::loadfile(hash_table); break;
		case'r':menu::r_showpets(hash_table); break;
		default: cout << ("Switching error"); break;
		}
	}
	//mytree.~BinTree();




	//menu::addpet(mytree);
	return 0;
}