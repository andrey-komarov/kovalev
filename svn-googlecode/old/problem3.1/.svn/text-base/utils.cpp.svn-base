#ifndef utilsCPP
#define utilsCPP

#include "utils.hpp"

boost::phoenix::function<utils::construct_big_int_impl>& construct_big_int()
{
	static boost::phoenix::function<utils::construct_big_int_impl> f;
	return f;
}

boost::phoenix::function<utils::pow_impl>& pow()
{
	static boost::phoenix::function<utils::pow_impl> f;
	return f;
}

boost::phoenix::function<utils::func_impl>& func()
{
	static boost::phoenix::function<utils::func_impl> f;
	return f;
}

#endif /* utilsCPP */
