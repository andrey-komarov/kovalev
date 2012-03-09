#ifndef calculatorCPP
#define calculatorCPP

#include "calculator.h"

namespace
{
	template <typename Iterator>
	calculator<Iterator>::calculator() : calculator<Iterator>::base_type(s)
	{
		unsigned_number = +(ascii::digit);
		function_name = +(ascii::alpha);
		number = unsigned_number[_val = construct_big_int()(_1)];
		expr = 
			number[_val = _1]
			| (lit("-") >> expr)[_val = -_1]
			| (lit("+") >> expr)[_val = _1]			
			| (lit("(") >> sum >> lit(")"))[_val = _1]
			| (function_name >> lit("(") >> sum >> lit(")"))[_val = func()(_1, _2)];
		sum = product[_val = _1] >> *(
			(lit("+") >> product)[_val += _1]
			| (lit("-") >> product)[_val -= _1]
		);
		product = power[_val = _1] >> *(
			(lit("*") >> power)[_val *= _1]
			| (lit("/") >> power)[_val /= _1]
		);
		power = expr[_val = _1] >> -(lit("^") >> power)[_val = pow()(_val, _1)];
		s %= sum > qi::eoi;
	}

	calculator<std::string::const_iterator>& get_grammar()
	{
		static calculator<std::string::const_iterator> calc;
		return calc;
	}
}

big_int calculate(const std::string& s)
{
	big_int ans;
	std::string::const_iterator begin = s.begin(), end = s.end();
	if (qi::phrase_parse(begin, end, get_grammar(), ascii::space, ans))
		return ans;
	else
		throw bad_expression();
}

#endif /* calculatorCPP */
