#ifndef set_h
#define set_h
#include <cstddef>
#include <functional>
#include <iterator>

namespace geom 
{

template<typename T, class cmp = std::less<T> >
struct set
{
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	virtual void insert(const_reference) = 0;
	virtual void erase(const T&) = 0;
	virtual bool empty() const = 0;
	virtual size_type size() const = 0;
	virtual void clear() = 0;

	struct iterator
	{
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef set::value_type value_type;
		typedef set::size_type size_type;
		typedef set::difference_type difference_type;
		typedef set::pointer pointer;
		typedef set::const_pointer const_pointer;
		typedef set::reference reference;
		typedef set::const_reference const_reference;

		virtual reference operator*();
		virtual pointer operator->();
		virtual iterator& operator++();
		virtual iterator operator++(int);
		virtual iterator& operator--();
		virtual iterator operator--(int);
		virtual iterator& operator=(const iterator&);
		virtual bool operator==(const iterator&) const;
		virtual bool operator!=(const iterator&) const;
	};

	virtual iterator begin() = 0;
	virtual iterator end() = 0;
//	iterator find() const = 0;
};

} // geom

#endif // set_h
