#pragma once
#include"RBTNode.h"
#include"RBTree.h"

template<class T,class R>
class Map 
{
	

public:
	Map();
	~Map();
	R& operator[](T index)
	{
		return tree.searchOperator(index);
	}
	size_t size()
	{
		return tree.Size();
	}
	size_t max_size() const
	{
		return std::numeric_limits<size_t>::max();
		/*Это значение обычно равно std::numeric_limits<size_type>::max(), и отражает теоретический предел на размер контейнера. 
		Ввиду ограничений на доступную оперативную память, во время исполнения это значение может быть ниже чем max_size().*/
	}
	bool empty()const
	{
		if (tree.Size()==0)
		{
			return 1;
		}
		else
			return 0;
	}
	
	
	class MyIterator : public iterator<bidirectional_iterator_tag, RBTNode<T, R>>
	{
	
		friend class Map;
		public:
		MyIterator(RBTNode<T, R> *it)
		{
			second = it->Element.second;
			first = it->Element.first;
			temp = it;
		}
		MyIterator()
		{
			
		}
		/*~MyIterator()
		{
			//temp = NULL;
			//first = '\0';
			//second = '\0';
		}*/
		MyIterator& operator=(const MyIterator& it) 
		{
			temp = NULL;
			first = it.first;
			second = it.second;
			temp = it.temp;
			return (*this);
		}
		bool operator!=(const MyIterator& it)
		{
			return this->first != it.first;//достаточно сравнить ключи
		}
		bool operator==(const MyIterator& it)
		{
			return this->first == it.first;
		}
		MyIterator& operator*()
		{
			
			return (*this);
		}
		MyIterator(const MyIterator& source)
		{
			first = source.first;
			second = source.second;
			temp = source.temp;
		
		}
		/*MyIterator(const RBTNode<T, R>& source)
		{
			first = source.Element.first;
			second = source.Element.second;
			temp = source;
		}*/
		MyIterator operator++(int) 
		{//Post ++
			
			if (temp->right != NULL)
			{
				/*temp = temp->right;
				if (temp->left == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->left)
					{
						temp = temp->left;
					}
				}*/
				
				temp=minimum(temp->right);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;
			}
			
			RBTNode<T, R>* loc_node = temp->parent;
				while (loc_node != NULL && temp == loc_node->right)
				{
					temp = loc_node;
					loc_node = loc_node->parent;
				}
			temp = loc_node;
			
			
			first = temp->Element.first;
			second = temp->Element.second;
			return *this;
		}
		MyIterator& operator++()
		{//Front ++

			if (temp->right != NULL)
			{
				/*temp = temp->right;
				if (temp->left == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->left)
					{
						temp = temp->left;
					}
				}*/

				temp = minimum(temp->right);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;
			}

			RBTNode<T, R>* loc_node = temp->parent;
			while (loc_node != NULL && temp == loc_node->right)
			{
				temp = loc_node;
				loc_node = loc_node->parent;
			}
			temp = loc_node;


			first = temp->Element.first;
			second = temp->Element.second;
			return *this;
		}
		MyIterator operator--(int)
		{//Post--
			if (temp->left != NULL)
			{
				/*temp = temp->left;
				if (temp->right == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->right)
					{
						temp = temp->right;
					}
				}*/
				temp = maximum(temp->left);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;

			}
			
			RBTNode<T, R>* loc_node = temp->parent;
				while (loc_node != NULL && temp == loc_node->left)
				{
					temp = loc_node;
					loc_node = loc_node->parent;
				}
				temp = loc_node;
			

			first = temp->Element.first;
			second = temp->Element.second;
			return *this;
			
		}
		MyIterator& operator--()
		{//Front--
			if (temp->left != NULL)
			{
				/*temp = temp->left;
				if (temp->right == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->right)
					{
						temp = temp->right;
					}
				}*/
				temp = maximum(temp->left);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;

			}

			RBTNode<T, R>* loc_node = temp->parent;
			while (loc_node != NULL && temp == loc_node->left)
			{
				temp = loc_node;
				loc_node = loc_node->parent;
			}
			temp = loc_node;


			first = temp->Element.first;
			second = temp->Element.second;
			return *this;

		}
		MyIterator *operator->() 
		{
			// 
			return (this);
		}
		/*static bool operator<(const MyIterator& it1, const MyIterator& it2)//ограничиваю перегрузку сравнения только этим файлом
		{
			return it1.first < it2.first;
		}
		static bool operator>(const MyIterator& it1, const MyIterator& it2)//ограничиваю перегрузку сравнения только этим файлом
		{
			return it1.first > it2.first;
		}*/
		
	public:
		T first;
		R second;
	private:
		RBTNode<T, R>* temp;
		RBTNode<T, R>* minimum(RBTNode<T, R>*);
		RBTNode<T, R>* maximum(RBTNode<T, R>*);

	};
	MyIterator begin()
	{
		RBTNode<T, R>* pt = tree.f_begin();
		MyIterator temp(pt);
		 
		return temp;
	}
	MyIterator end()
	{
		RBTNode<T, R>* pt = tree.l_end();
		MyIterator temp(pt);

		return temp;
	}
	pair<MyIterator, bool> insert(const std::pair<T,R> tempo)// first insert function
	{
		std::pair<MyIterator, bool> returnable;
		if (!tree.search(tempo.first))// проверка на уникальность
		{
			//RBTNode<T, R> tempnode;
			
			tree.insert(tempo.first, tempo.second);
			MyIterator ret(tree.search(tempo.first));//конструктор,чтобы знать ноду
			returnable.first = ret;
			returnable.second = 1;
			return returnable;
		}
		else 
		{
			MyIterator ret(tree.search(tempo.first));//конструктор,чтобы знать ноду
			returnable.first = ret;
			returnable.second = 0;
			return returnable;
		}

		
		//return ret;
	}
	
	MyIterator insert(MyIterator it,  const std::pair<T, R> tempo)//second insertation function
	{
		
		if (it.first < tempo.first)
		{
			for (; it != end(); it++)
			{
				if (it.first == tempo.first)
				{
					return it;
				}
				if (it.first < tempo.first)
				{
					continue;
				}
				else
				{
					tree.insert(tempo.first, tempo.second);
					it--;
					break;
				}
			}
			return it;

		}
		else
		{
			for (; it != begin(); it--)
			{
				if (it.first == tempo.first)
				{
					return it;
				}
				if (it.first > tempo.first)///!!!!!!!!!!!!!!!!!!!!!!!!!
				{
					continue;
				}
				else
				{
					tree.insert(tempo.first, tempo.second);
					it++;
					break;
				}
			}
			return it;
		}
		
	}
	MyIterator lower_bound(T index)
	{
		MyIterator ret(tree.search(index));//конструктор,чтобы знать ноду
		return ret;
	}
	MyIterator upper_bound(T index)
	{
		MyIterator ret(tree.search(index));
		if(ret!=end())
			ret++;

		return ret;
	}
	MyIterator find(T index)
	{
		MyIterator ret(tree.search(index));
		return ret;
	}
	void clear()
	{
		//tree.~RBTree();
		
	}
	void erase(MyIterator& index)//erase (1)
	{
		tree.remove(index.first);
		//index = end();
		index.~MyIterator();
	}
	size_t erase(const T key)//(2)
	{
		if (tree.search(key))
		{
			tree.remove(key);
			return 1;
		}
		else
			return 0;
			
	}
	void erase(MyIterator f_it, MyIterator s_it)
	{
		
		while (f_it != s_it)
		{
			T key = f_it.first;
			f_it++;
			tree.remove(key);
			
		}
		T key = s_it.first;
		tree.remove(key);
	}
	//реверc итератор
	class r_MyIterator :public MyIterator
	{
		
	public:
		r_MyIterator(RBTNode<T, R> *it)
		{
			second = it->Element.second;
			first = it->Element.first;
			temp = it;
		}
		r_MyIterator()
		{

		}
		~r_MyIterator()
		{
			temp = NULL;
			first = '\0';//0;
			second = '\0';
		}
		r_MyIterator& operator=(const r_MyIterator& it)
		{
			temp = NULL;
			first = it.first;
			second = it.second;
			temp = it.temp;
			return (*this);
		}
		bool operator!=(const r_MyIterator& it)
		{
			return this->first != it.first;//достаточно сравнить ключи
		}
		bool operator==(const r_MyIterator& it)
		{
			return this->first == it.first;
		}
		r_MyIterator& operator*()
		{

			return (*this);
		}
		r_MyIterator(const r_MyIterator& source)
		{
			first = source.first;
			second = source.second;
			temp = source.temp;
		}
		r_MyIterator operator--(int)
		{//Post --(revers)

			/*if (temp->right != NULL)
			{
				temp = temp->right;
				if (temp->left == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->left)
					{
						temp = temp->left;
					}
				}
			}
			else
			{
				RBTNode<T, R>* loc_node = temp->parent;
				while (loc_node != NULL && temp == loc_node->right)
				{
					temp = loc_node;
					loc_node = loc_node->parent;
				}
				temp = loc_node;
			}

			first = temp->Element.first;
			second = temp->Element.second;
			return *this;*/
			if (temp->right != NULL)
			{

				temp = minimum1(temp->right);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;
			}

			RBTNode<T, R>* loc_node = temp->parent;
			while (loc_node != NULL && temp == loc_node->right)
			{
				temp = loc_node;
				loc_node = loc_node->parent;
			}
			temp = loc_node;


			first = temp->Element.first;
			second = temp->Element.second;
			return *this;
		}
		r_MyIterator operator++(int)
		{//Post++(revers)
			/*if (temp->left != NULL)
			{
				temp = temp->left;
				if (temp->right == NULL)
				{
					int k = 0;
				}
				else
				{
					while (temp->right)
					{
						temp = temp->right;
					}
				}
			}
			else
			{
				RBTNode<T, R>* loc_node = temp->parent;
				while (loc_node != NULL && temp == loc_node->left)
				{
					temp = loc_node;
					loc_node = loc_node->parent;
				}
				temp = loc_node;
			}

			first = temp->Element.first;
			second = temp->Element.second;
			return *this;*/
			if (temp->left != NULL)
			{
				
				temp = maximum1(temp->left);
				first = temp->Element.first;
				second = temp->Element.second;
				return *this;

			}

			RBTNode<T, R>* loc_node = temp->parent;
			while (loc_node != NULL && temp == loc_node->left)
			{
				temp = loc_node;
				loc_node = loc_node->parent;
			}
			temp = loc_node;


			first = temp->Element.first;
			second = temp->Element.second;
			return *this;

		}
		r_MyIterator *operator->()
		{
			// 
			return (this);
		}
		
	public:
		T first;
		R second;
	private:
		RBTNode<T, R>* temp;
		RBTNode<T, R>* minimum1(RBTNode<T, R>*);
		RBTNode<T, R>* maximum1(RBTNode<T, R>*);
	};
	r_MyIterator rbegin()
	{
		RBTNode<T, R>* pt = tree.l_end();
		r_MyIterator temp(pt);

		return temp;
	}
	r_MyIterator rend()
	{
		RBTNode<T, R>* pt = tree.f_begin();
		r_MyIterator temp(pt);

		return temp;
	}
private:
	  RBTree<T,R> tree;
	 
	//RBTNode<T, R> tempnode;
};

template <class T,class R>
Map<T, R>::Map() {

	
}
template <class T, class R>
Map<T,R>::~Map()
{

}

/*template<class T, class R>
RBTNode<T,R>* Map<T, R>::Get_Next(T key)
{
	return tree.search(key);
}*/

/*template<class T, class R>
Map<T,R>::iterator1 Map<T, R>::begin()
{
	tempnode = tree.f_begin();
	return iterator1(tree.f_begin());
}


template<class T, class R>
Map<T, R>::iterator1 Map<T, R>::end()
{
	return iterator1(tree.l_end());
}

template<class T, class R>
Map<T, R>::const_iterator Map<T, R>::begin() const
{
	return const_iterator(tree.f_begin());
}

template<class T, class R>
Map<T, R>::const_iterator Map<T, R>::end() const
{
	return const_iterator(tree.l_end());
}*/


/*template <class T, class R>
Map<T, R>& Map<T, R>::operator=(const Map& source) const
{
	RBTree(source.tree);//копируем само дерево
	//RBTNode(source.tree.);//копируем ноды этого дерева
	return *this;
}*/

template<class T, class R>
RBTNode<T, R>* Map<T, R>::MyIterator::minimum(RBTNode<T, R>* node)
{
	if (node->left == NULL)
		return node;
	return minimum(node->left);
}

template<class T, class R>
RBTNode<T, R>* Map<T, R>::MyIterator::maximum(RBTNode<T, R>* node)
{
	if (node->right == NULL)
		return node;
	return maximum(node->right);
}

template<class T, class R>
 RBTNode<T, R>* Map<T, R>::r_MyIterator::minimum1(RBTNode<T, R>* node)
{
	 if (node->left == NULL)
		 return node;
	 return minimum1(node->left);

}

template<class T, class R>
 RBTNode<T, R>* Map<T, R>::r_MyIterator::maximum1(RBTNode<T, R>*node)
{
	 if (node->right == NULL)
		 return node;
	 return maximum1(node->right);
}
