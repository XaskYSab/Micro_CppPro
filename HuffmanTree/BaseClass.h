#pragma once
class BaseClass
{
public:

	BaseClass();

	virtual ~BaseClass();

	virtual int big(const BaseClass*base) const = 0;

	virtual int small(const BaseClass*base) const = 0;

	int operator >(const BaseClass &base) const
	{
		return big(&base);
	}

	int operator ==(const BaseClass &base) const
	{
		return small(&base);
	}

};

