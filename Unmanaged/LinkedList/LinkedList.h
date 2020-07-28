#pragma once

#include "List.h"
#include <memory>
#include <iostream>

template<class T>
class LinkedList : public List<T>
{
private:
	struct Node
	{
		T mData;
		std::unique_ptr<Node> mNextNode;

		// Structure�� �����ϸ鼭�ʱ�ȭ
		Node(const T& Data)
			:mData(Data)
		{

		}
	};

	int mSizeCounter = 0;
	std::unique_ptr<Node> mHead;

public:
	LinkedList() = default;

	void Insert(const T& Data) override 
	{
		mSizeCounter++;

		if(mSizeCounter<3)
			insetDataBeginning(Data);
		else
			insertData(Data);

	}

	void Remove(const T& Data) override
	{
#if 1 
		if (!mHead) //unique_ptr null �񱳴� �ȵ�
			return;

		if (mHead->mData == Data)
		{
			//unique_ptr ������ ����
			auto newHead = std::move(mHead->mNextNode);
			mHead = std::move(newHead);
			//mHead = std::move(mHead->mNextMode); build error 
			mSizeCounter--;
		
			return;
		}

		if (!mHead->mNextNode)
		{
			std::cout << Data << "is not found in a list";
			return;
		}
		
		// unique ptr�� ���� �����͸� ��ȯ ������ ������ ���
		Node* prev = mHead.get();
		Node* next = mHead->mNextNode.get();

		while (next->mData != Data)
		{
			prev = next;
			next = next->mNextNode.get();
		}

		if (!next)
		{
			std::cout << Data << "is not found in a list";
			return;
		}

		std::unique_ptr<Node> temp = std::move(next->mNextNode);
		prev->mNextNode = std::move(temp);
#endif		
	}
	
	void TraverseList() override
	{
#if 1
		Node* node = mHead.get();

		while (node)
		{
			std::cout << node->mData << ' ';
			node = node->mNextNode.get();
		}
#endif
		std::cout << '\n';
	}

	int size()const override
	{
		return mSizeCounter;
	}
private:

	void insetDataBeginning(const T& Data)
	{
		std::unique_ptr<Node>  newNode = std::make_unique<Node>(Data);
		newNode->mNextNode = std::move(mHead);
		mHead = std::move(newNode);
	}

	void insertData(const T& Data)
	{
		if (!mHead) //unique_ptr null �񱳴� �ȵ�
		{
			std::cout << "list is empty"<<std::endl;
			return;
		}

		Node* prev = mHead.get();
		Node* next = mHead->mNextNode.get();

		while (next->mData != Data)
		{
			prev = next;
			next = next->mNextNode.get();
		}

		if (!next)
		{
			std::cout << Data << "is not in the list."<<std::endl;
			return;
		}
#if 1
		
		std::unique_ptr<Node> newNode = std::make_unique<Node>(Data);
		newNode->mNextNode = std::move(std::move(prev->mNextNode));
		prev->mNextNode = std::move(std::move(newNode));
		//prev->mNextNode = std::move(newNode);
#endif
	}

};