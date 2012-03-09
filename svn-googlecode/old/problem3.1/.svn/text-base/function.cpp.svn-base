#ifndef functionCPP
#define functionCPP

#include "function.h"

function_t::function_t()
{
}

function_t::function_t(const std::string& name, big_int(*f)(big_int)):
	name_(name),
	f_(f)
{
}

std::string function_t::get_name() const
{
	return name_;
}

big_int function_t::operator()(big_int a) const
{
	return f_(a);
}

std::map<std::string, function_t>& get_functions()
{
	static std::map<std::string, function_t> functions_;
	return functions_;
}

#endif /* functionCPP */
