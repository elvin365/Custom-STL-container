//test.cpp
#include"RBTree.h"
//#include"RBTree.h"
#include<iostream>
#include <string>
//#include<vector>
//#include<iterator>
#include"Map.h"
//#include <map>
#include<conio.h>
using namespace std;
//template<class RBTree>

int main()
{
	Map<int, string>::MyIterator iter,iter2;

	
	Map<int,string> mymap;
	Map<int, string> mymap1;

	



	/*operator[] test*/
	mymap[0];
	mymap[4] = "Benny";

	/*first type of insert test*/
	mymap.insert(std::pair<int, string>(13, "Brian"));
	mymap.insert(std::pair<int, string>(8, "Kyle"));
	mymap.insert(std::pair<int, string>(1, "Floyd"));
	mymap.insert(std::pair<int, string>(11, "Jessica"));
	mymap.insert(std::pair<int, string>(6, "Bill"));
	mymap.insert(std::pair<int, string>(17, "Kate"));
	mymap.insert(std::pair<int, string>(15, "Cortney"));
	mymap.insert(std::pair<int, string>(25, "John"));
	mymap.insert(std::pair<int, string>(22, "Mike"));
	mymap.insert(std::pair<int, string>(22, "Coco"));
	
	/*erasing by range*/ //&& 	/*find test*/
	iter = mymap.find(15);
	iter2 = mymap.find(17);
	mymap.erase(iter, iter2);


	//возвраит и проверка по .second
	std::pair<Map<int, string>::MyIterator, bool> ret;
	ret = mymap.insert(std::pair<int, string>(8, "Kyle"));
	if (ret.second == false)
	{
		cout << "This element is already exist!!!\n";
	}
	/*second inser type test*/
	Map<int, string>::MyIterator it = mymap.begin();
	mymap.insert(it, std::pair<int, string>(27, "Erl"));
	mymap.insert(it, std::pair<int, string>(30, "Dordan"));

	

	
	/*empty test*/
	while (!mymap.empty())
	{
		cout << "There is simething \n";
		break;
	}



	//Map<int, string>::MyIterator i;
	/*begin test*/

	Map<int, string>::MyIterator i=mymap.begin();
	/*begin and end test */
	for (i; i != mymap.end(); i++)
	{
		cout << i->first << "=>" << i->second << '\n';
	}
	/*rbegin and rend test*/
	puts("\n");
	for (Map<int, string>::r_MyIterator rit=mymap.rbegin(); rit != mymap.rend(); rit++)
	{
		cout << rit->first << "=>" << rit->second << '\n';

	}
	/*size test*/
	cout <<"The size is: "<<mymap.size() << '\n';
	
	
	/*copy construct test*/
	mymap1 = mymap;// конструктор копирования или присваивания



		/*lower_bound test*/
	Map<int, string>::MyIterator itlow, itup,i2;
	itlow = mymap.lower_bound(1);//указывает точно на 1
	itup = mymap.upper_bound(4);//укажет на 6
	mymap.erase(itlow, itup);

	/*first type of erase by iterator*/
	it = mymap.find(22);
	mymap.erase(it);
	/*erase by key returning 1 or 0*/
	mymap.erase(22);
	mymap.erase(22);
	
	

	/*max size test*/
	if (mymap.max_size() > 50)
	{
		for (int i = 0; i < 50; i++) mymap[i] = "Empty";

	}
	else
		cout << "The map cant hold 50 elements \n";
	

	//------------------------------Now testing other types--------------------///---------------------------------------------------------

	



	Map<string, string>::MyIterator iter3, iter4;


	Map<string, string> mymap2;
	Map<string, string> mymap3;





	/*operator[] test*/
	mymap2["Big"];
	mymap2["Harris"] = "Benny";

	/*first type of insert test*/
	mymap2.insert(std::pair<string, string>("Sierra", "Brian"));
	mymap2.insert(std::pair<string, string>("Davis", "Kyle"));
	mymap2.insert(std::pair<string, string>("Moore", "Floyd"));
	mymap2.insert(std::pair<string, string>("Anderson", "Jessica"));
	mymap2.insert(std::pair<string, string>("Cox", "Bill"));
	mymap2.insert(std::pair<string, string>("Torres", "Kate"));
	mymap2.insert(std::pair<string, string>("Gray", "Cortney"));
	mymap2.insert(std::pair<string, string>("Brooks", "John"));
	mymap2.insert(std::pair<string, string>("Ramirez", "Mike"));
	mymap2.insert(std::pair<string, string>("Rivera", "Coco"));
	//mymap2.erase("Davis");
	/*erasing by range*/ //&& 	/*find test*/
	/*iter3 = mymap2.find("Brooks");
	iter4 = mymap2.find("Harris");
	mymap2.erase(iter3, iter4);*/


	//возвраит и проверка по .second
	std::pair<Map<string, string>::MyIterator, bool> ret2;
	ret2 = mymap2.insert(std::pair<string, string>("Cox", "Bill"));
	if (ret2.second == false)
	{
		cout << "this element is already exist!!!\n";
	}
	/*second inser type test*/
	Map<string, string>::MyIterator it99 = mymap2.begin();
	mymap2.insert(it99, std::pair<string, string>("Price", "Erl"));
	mymap2.insert(it99, std::pair<string, string>("Wood", "Dordan"));




	/*empty test*/
	while (!mymap2.empty())
	{
		cout << "There is simething \n";
		break;
	}



	//Map<int, string>::MyIterator i;
	/*begin test*/

	Map<string, string>::MyIterator i12 = mymap2.begin();
	/*begin and end test */
	for (i12; i12 != mymap2.end(); i12++)
	{
		cout << i12->first << "=>" << i12->second << '\n';
	}
	/*rbegin and rend test*/
	puts("\n");
	for (Map<string, string>::r_MyIterator rit = mymap2.rbegin(); rit != mymap2.rend(); rit++)
	{
		cout << rit->first << "=>" << rit->second << '\n';

	}
	///*size test*/
	cout << "The size is: " << mymap2.size() << '\n';


	///*copy construct test*/
	mymap3 = mymap2;// конструктор копирования или присваивания



		/*lower_bound test*/
	Map<string, string>::MyIterator itlow99, itup99, i88;
	itlow99 = mymap2.lower_bound("Anderson");
	itup99 = mymap2.upper_bound("Cox");
//	mymap2.erase(itlow99, itup99);

	/*first type of erase by iterator*/
	i88 = mymap2.find("Gray");
	mymap2.erase(i88);
	/*erase by key returning 1 or 0*/
	mymap2.erase("Harris");
	mymap2.erase("Harris");



	///*max size test*/
	//if (mymap.max_size() > 50)
	//{
	//	for (int i = 0; i < 50; i++) mymap[i] = "Empty";

	//}
	//else
	//	cout << "The map cant hold 50 elements \n";

















	/*Map<int, string>::r_MyIterator rit;
	for (rit = mymap.rbegin(); rit != mymap.rend(); rit++)
	{
		//i->second = "Benny";
		cout << rit->first << "=>" << rit->second << '\n';
	}
	Map<int, string>::MyIterator i = mymap.begin();
	for (i = mymap.begin(); i != mymap.end(); i++)
	{
		//i->second = "Benny";
		cout << i->first << "=>" << i->second << '\n';
	}
	puts("\n");
	mymap.insert(i, std::pair<int, string>(16, "Kilom"));
	//mymap.insert(i, std::pair<int, string>(0, "Andy"));
	//mymap.insert(std::pair<int, string>(16, "Andy"));
	Map<int, string>::MyIterator it;
	//it = mymap.find(15);
	//mymap.erase(it);
	it = mymap.find(17);
	mymap.erase(it, mymap.end());
	mymap.erase(17);
	for (it=mymap.begin(); it != mymap.end(); it++)
	{
		cout << it->first << "=>" << it->second << '\n';
	}
	Map<int, string>::MyIterator itlow, itup;
	itlow = mymap.lower_bound(17);
	itup = mymap.upper_bound(25);
	/*cout<<mymap.find(22)->second << '\n';
	Map<int, string>::MyIterator it;
	it = mymap.find(22);
	if (it != mymap.end())
	{
		printf("Here");
	}*/
	/*mymap.clear();
	cout << "mymap.size() is " << mymap.size() << '\n';
	mymap[2] = "Benny";
	Map<int, string>::MyIterator i3 = mymap.begin();
	for (i3 = mymap.begin(); i3 != mymap.end(); i3++)
	{
		//i->second = "Benny";
		cout << i3->first << "=>" << i3->second << '\n';
	}
	if (!mymap.empty())
	{
		cout << "Not empty" << '\n';
	}
	cout << mymap.max_size() << '\n';
	//i++;
	//printf("%d", (*i).first);
	//printf("%d",i->first);
	/*Map<int, string>::MyIterator i2 = mymap1.begin();
	mymap.insert(i2, std::pair<int, string>(16, "Kilom"));*/
	/*Map<int, string>::MyIterator i1 = mymap.end();
	mymap.insert(i1, std::pair<int, string>(16, "Kilom"));

	printf("%d", i1->first);

	//std::map<char, int> mymap;
	
	//mymap.insert(std::pair<int, string>(100,"Racoon"));

	/*std::pair<Map<int, string>::MyIterator, bool> ret;
	ret = mymap.insert(std::pair<int, string>(4, "Benny"));
	cout << ret.second;*/
	//Map<int, string>::MyIterator it = mymap.begin();
	
	//mymap.insert(it, std::pair<int, string>(100, "Barry"));
	

	//cout << ret.first->second;
	//Map<int, string>::iterator1 rt
	//printf("%d",rt.)
	//int k1 = 0;
	//_getch();
	//mymap.insert()
	/*std::map<int, std::string> myMap1;
	myMap1.insert(make_pair(3, "me"));

	std::map<int, std::string> myMap;
	myMap.insert(std::make_pair(3, "cat"));
	myMap.insert(std::make_pair(2, "dog"));
	myMap.insert(std::make_pair(5, "chicken"));
	myMap.insert(std::make_pair(4, "lion"));
	myMap.insert(std::make_pair(1, "spider"));

	std::map<int, std::string>::const_iterator it; // объявляем итератор
	it = myMap.begin(); // присваиваем ему начало вектора
	*/
	/*while (it != myMap.end()) // пока итератор не достигнет конца
	{
		std::cout << it->first << "=" << it->second << " "; // выводим значение элемента, на который указывает итератор
		++it; // и переходим к следующему элементу
	}*/










	/*vector<int> nums{ 10,40,30,60,90,70,20,50,80,100 };
	RBTree<int> tree;
	for (auto num : nums)
		tree.insert(num);
	tree.preOrder();
	cout << endl;
	tree.inOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	cout << "Find the node with a key of 30: \n";
	cout << endl << tree.search(30)->key << endl;
	cout << "Delete the node with a key of 100\n";
	tree.remove(100);
	tree.preOrder();
	cout << endl;
	cout << "\n red black tree details: \n";
	tree.print();
	cin.get();*/
	return 0;
}