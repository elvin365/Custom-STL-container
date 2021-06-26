#pragma once
#include <utility>
#include <iostream>
//RBTNode.h
enum RBTColor { Black, Red };

template<class KeyType,class R>
struct  RBTNode
{
	std::pair<KeyType, R> Element;
	//KeyType key;
	RBTColor color;
	RBTNode<KeyType,R> * left;
	RBTNode<KeyType,R> * right;
	RBTNode<KeyType,R> * parent;
	//R  info;//возможно не указатель
	//RBTNode(KeyType k, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r, R i) :
	//	key(k), color(c), parent(p), left(l), right(r),info(i){ };
	RBTNode(KeyType k, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r, R i) :
			color(c), parent(p), left(l), right(r)
	{
		Element=std::make_pair(k, i);
	};
	RBTNode(const RBTNode<KeyType,R>& source)
	{
		Element.first= source.Element.first;
		//key = source.key;//поверхностное копирование ключа
		color = source.color;
		parent = source.parent;
		right = source.right;
		left = source.left;
		Element.second = source.Element.second;
	//	info = info;
	}
	RBTNode()
	{
		//this->color = 0;
		this->left = NULL;
		this->parent = NULL;
		this->right = NULL;
	}
};
template<class KeyType>

inline bool operator<(const KeyType& left, const KeyType& right)
{
	if ((left < right) || ((left == right) && (left < right)))
		return true;
	return false;
}
template<class KeyType>
inline bool operator>(const KeyType& left, const KeyType& right)
{
	if ((left > right) || ((left == right) && (left > right)))
		return true;
	return false;
}

template<class KeyType>
inline bool operator==(const KeyType& left, const KeyType& right)
{
	if (left == right)
		return true;
	return false;
}

/*template<class KeyType>

//конструктор копирования 
RBTNode<KeyType>::RBTNode<KeyType>(const RBTNode<KeyType>& source)
{
	key = source.key;//поверхностное копирование ключа
	color = source.color;
	parent = source.parent;
	right = source.right;
	left = source.left;
	info = info;
}*/
