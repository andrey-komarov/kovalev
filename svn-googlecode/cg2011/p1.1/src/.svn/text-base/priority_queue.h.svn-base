#ifndef priority_queueH
#define priority_queueH

#include <cstddef>
#include <algorithm>

template<int capacity, typename T>
struct priority_queue
{
	priority_queue() : size_(0)
	{}
	
	size_t size()
	{	return size_;}

	void push(const T& element)
	{	
		if (element != 0)
			values[size_++] = element;
	}

	T& pop()
	{
		T res(values[0]);
		size_t index = 0;
		for (size_t i = 1; i < size_; i++)
			if (res < values[i])
			{
				res = values[i];
				index = i;
			}
		std::swap(values[index],values[--size_]);
		return values[size_];
	}

	

private:
	T values[capacity];
	size_t size_;
};

#endif
