#ifndef calculatorH
#define calculatorH

#include <string>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include "big_int.h"
#include "utils.hpp"

struct bad_expression{};

big_int calculate(const std::string&);

namespace
{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;
	using qi::lit;
	using qi::_1;
	using qi::_2;
	using qi::_val;

	template <typename Iterator>
	struct calculator : qi::grammar<Iterator, big_int(), ascii::space_type>
	{
		calculator();
	private:
		qi::rule<Iterator, big_int(), ascii::space_type> sum, product, power, expr, s, number, function;
		qi::rule<Iterator, std::string(), ascii::space_type> unsigned_number, function_name;
	};
	
	calculator<std::string::const_iterator>& get_grammar();
}

#endif /* calculatorH */
