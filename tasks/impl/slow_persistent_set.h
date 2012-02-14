#ifndef slow_persistent_set_h
#define slow_persistent_set_h

#include "persistent_set.h"
#include <map>
#include <set>
#include <vector>

namespace geom
{

template<typename T, typename cmp = std::less<T> >
struct slow_persistent_set : persistent_set<T, cmp> 
{
	slow_persistent_set() : 
		revision(0),
		revisions(1),
		current(revisions[0])
	{
		real_ids[0] = 0;
	}

	void insert(const T& val)
	{	current.insert(val);}

	void erase(const T& val)
	{	current.erase(val);}

	bool empty() const 
	{	return current.empty();}

	size_t size() const
	{	return current.size();}

	void clear() 
	{	current.clear();}

	void tag_revision(size_t id)
	{	
		revision++;
		revisions.push_back(std::set<T>(current));
		real_ids[id] = revision;
		current = revisions[real_ids[id]];
	}

	void restore_revision(size_t id)
	{
		current = revisions[real_ids[id]];
	}

	struct iterator : public set<T>::iterator
	{
		typename std::set<T>::iterator it;
	
		iterator(const typename std::set<T>::iterator& it) : it(it)
		{}

		iterator(const iterator& i) : it(i.it)
		{}

		iterator& operator=(const iterator& i)
		{
			it = i.it;
			return *this;
		}
	
		iterator& operator++()
		{
			++it;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp(it++);
			return tmp;
		}

		iterator& operator--()
		{
			--it;
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp(it--);
			return tmp;
		}

		typename set<T>::iterator::reference operator*()
		{	return *it;}

		typename set<T>::iterator::pointer operator->()
		{	return &(*this);}

		bool operator==(const iterator& i) const
		{	return it == i.it;}

		bool operator!=(const iterator& i) const
		{	return it != i.it;}
	};

	iterator begin()
	{	return iterator(current.begin());}

	iterator end()
	{	return iterator(current.end());}

private:
	size_t revision;
	std::vector<std::set<T> > revisions;
	std::map<size_t, size_t> real_ids;
	std::set<T>& current;
};

} // geom

#endif // slow_persistent_set
