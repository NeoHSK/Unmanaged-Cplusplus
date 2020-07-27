#pragma once

#include "List.h"
#include <memory>
#include <iostream>

template<class T>
class LinkedList : public List<T>
{
	struct Node
	{
		T mData;
		std::unique_ptr<Node> mNextNode;

		Node(const Node& Data)
			:mData(Data)
		{

		}
	};

	int mSizeCounter = 0;
	std::unique_ptr<Node> mHead;

public:
	LinkedList() = default;

	void Insert(const T& data) override 
	{
		mSizeCounter++;

	}

	void Remove(const T& data) override
	{
		if (!mHead)
			return;

		if (mHead->mData == data)
		{
			auto newHead = std::move(mHead->mNextNode);
			mSizeCounter--;
		}
	}
	//virtual void TraverseList() = 0;
	//virtual int size()const = 0;
private:
	void InsetDataBegin(const T& Data)
	{
		std::unique_ptr<Node> NewNode = std::make_unique<Node>(Data);
		NewNode->mNextNode = std::move(mHead);
	}

};