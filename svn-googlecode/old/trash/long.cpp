longint::longint(int b)
{
	a.clear();
	a.push_back(b);
	norm();
}

longint::longint(vector<long long>& b)
{
	a = b;
	len = a.size();
	norm();
}

long long longint::operator[](int pos) const
{
	return a[pos];
}

longint& longint::operator=(const longint& b)
{
	a = b.a;
	len = b.len;
	return *this;
}

bool longint::operator>(const longint& b) const
{
	if (len != b.len)
		return len > b.len;
	for (int i = len - 1; i >= 0; i--)
		if (a[i] != b.a[i])
			return a[i] > b.a[i];
	return false;
}

bool longint::operator==(const longint& b) const
{
	return a == b.a;
}

bool longint::operator<(const longint& b) const
{
	return b > *this;
}

bool longint::operator>=(const longint& b) const
{
	return *this > b || *this == b;
}

bool longint::operator<=(const longint& b) const
{
	return *this < b || *this == b;
}

bool longint::operator!=(const longint& b) const
{
	return !(*this == b);
}


istream& operator>>(istream& is, longint& val) 
{
	string s;
	vector<long long> a;
	is >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0; i -= base_length)
		if (i >= base_length)
			a.push_back(atol(s.substr(i - base_length + 1,base_length).c_str()));
		else
			a.push_back(atol(s.substr(0, i + 1).c_str()));
	val = longint(a);
	return is;
}

ostream& operator<<(ostream& os, const longint& val)
{
	os << val.a.back();
	for (int i = val.a.size() - 2; i >= 0; i--)
	{
		long long now = val.a[i];
		long long now2 = now;
		int len = 0;
		for (len = 0; now2 > 9; now2 /=10, len++);
		for (int i = 0; i < base_length - len - 1; i++)
			os << "0";
		os << now;
	}
	return os;
}

void longint::norm(vector<long long>& a, bool need_shorten = true) const
{
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		if (a[i] < 0) {
			a[i] += base;
			a[i + 1]--;
		}
		a[i + 1] += a[i] / base;
		a[i] %= base;
	}
	while (need_shorten && a.back() == 0 && a.size() > 1) 
		a.pop_back();
}

void longint::norm()
{
	norm(a);
	len = a.size();
}

longint longint::operator+(const longint& b) const
{
	vector<long long> res(max(a.size(), b.a.size()) + 1, 0);
	for (size_t i = 0; i < b.a.size(); i++)
		res[i] += b[i];
	for (size_t i = 0; i < a.size(); i++)
		res[i] += a[i];
	return longint(res);
}

longint longint::operator-(const longint& b) const
{
	vector<long long> res(max(a.size(), b.a.size()) + 1, 0);
	for (size_t i = 0; i < b.a.size(); i++)
		res[i] -= b[i];
	for (size_t i = 0; i < a.size(); i++)
		res[i] += a[i];
	return longint(res);
}

longint longint::operator*(const longint& b) const
{
	vector<long long> res(len + b.len + 1, 0);
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < b.len; j++)
			res[i + j] += a[i] * b[j];
		if (i % 8 == 0)
			norm(res, false);
	}
	return longint(res);
}

longint longint::operator/(const long long& b) const
{
	vector<long long> res = a;
	for (int i = len - 1; i >= 1; i--)
	{
		res[i - 1] += (res[i] % b) * base;
		res[i] /= b;
	}
	res[0] /= b;
	return longint(res);
}

longint longint::operator/(const longint& b) const
{
	longint l(0);
	longint r = *this + longint(1);
	longint one = 1;
	while (l + one < r)
	{
		longint c = (l + r) / 2;
		//~ std::cerr << l << " " << r << " " << (b * c) << "\n";
		if (b * c > *this)
			r = c;
		else
			l = c;
	}
	return l;
}
