#pragma once
#ifndef utilsH
#define utilsH

#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <stdexcept>
#include "big_int.h"
#include "function.h"

namespace utils
{
	struct construct_big_int_impl
	{
		template<typename T>
		struct result
		{
			typedef big_int type;
		};
		template<typename T>
		big_int operator()(T) const;
	};
	
	struct pow_impl
	{
		template<typename T, typename K>
		struct result
		{
			typedef big_int type;
		};
		template<typename T, typename K>
		big_int operator()(T, K) const;
	};
	
	struct func_impl
	{
		template<typename T, typename K>
		struct result
		{
			typedef big_int type;
		};
		template<typename T, typename K>
		big_int operator()(T, K) const;
	};
}

boost::phoenix::function<utils::construct_big_int_impl>& construct_big_int();
boost::phoenix::function<utils::pow_impl>& pow();
boost::phoenix::function<utils::func_impl>& func();

#include "utils.tpp"

#endif /* utilsH */
