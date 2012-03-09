#ifndef functionH
#define functionH

#include <string>
#include <map>
#include <stdexcept>
#include "big_int.h"

struct function_t
{
	function_t();
	function_t(const std::string&, big_int(*f)(big_int));
	std::string get_name() const ;
	big_int operator()(big_int a) const;
private:
	std::string name_;
	big_int(*f_)(big_int);
};

std::map<std::string, function_t>& get_functions();

#define add_function(name, f) namespace{struct initializer##f{initializer##f(){get_functions()[name] = function_t(name, f);	}};	initializer##f a##f;};

#endif /* functionH */
