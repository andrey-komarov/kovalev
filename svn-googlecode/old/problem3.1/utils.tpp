#ifndef utilsTPP
#define utilsTPP

template<typename T>
big_int utils::construct_big_int_impl::operator()(T a) const
{
	return big_int(a);
}

namespace {
	big_int power(const big_int& a, const big_int& b)
	{
		if (b == 0)
			return 1;
		if (b % 2 == 1)
			return a * power(a, b - 1);
		big_int tmp = power(a, b / 2);
		return tmp * tmp;
	}
}

template<typename T, typename K>
big_int utils::pow_impl::operator()(T a, K b) const
{
	if (a == 0 && b == 0)
		throw std::runtime_error("0^0");
	if (b < 0)
		throw std::runtime_error("Negative power");
	return power(a, b);
}

template<typename T, typename K>
big_int utils::func_impl::operator()(T a, K b) const
{
	return get_functions()[a](b);
}

#endif
