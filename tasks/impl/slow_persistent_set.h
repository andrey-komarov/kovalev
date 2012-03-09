#ifndef slow_persistent_set_h
#define slow_persistent_set_h

#include <map>
#include <set>
#include <vector>
#include <functional>
#include <cstddef>

namespace geom
{

template<typename T, typename cmp = std::less<T> >
struct slow_persistent_set
{
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

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

	struct iterator
	{
                typedef std::bidirectional_iterator_tag iterator_category;
                typedef slow_persistent_set::value_type value_type;
                typedef slow_persistent_set::size_type size_type;
                typedef slow_persistent_set::difference_type difference_type;
                typedef slow_persistent_set::pointer pointer;
                typedef slow_persistent_set::const_pointer const_pointer;
                typedef slow_persistent_set::reference reference;
                typedef slow_persistent_set::const_reference const_reference;

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

		const_reference operator*()
		{	return *it;}

		pointer operator->()
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
