////////////////////////////////////////////////////////////////////////////////
//
//	BIGNUMBER	(bignumbr.h)
//	----------------------------------------------------------------------------
//	Class definition for BigNumber
//
//	Declarations:	BigNumber, BigNumber(char*), BigNumber(BigNumber)
//	Operations:		+, -, *
//	Input:			cin>>BigNumber
//	Output:			cout<<BigNumber
//
////////////////////////////////////////////////////////////////////////////////

class BigNumber
{
private:
	char *_number;																//	Contains the number string
	int length;																	//	Contains the length of number string

public:
	BigNumber();																//	Default constructor
	BigNumber(char *n);															//	Overloaded constructor
	BigNumber(const BigNumber &bn);												//	Copy constructor
	~BigNumber();																//	Destructor

	BigNumber operator+(BigNumber &bn);											//	Overload for + operator
	BigNumber operator-(BigNumber &bn);											//	Overload for - operator
	BigNumber operator*(BigNumber &bn);											//	Overload for * operator

	BigNumber &operator=(BigNumber &bn);										//	Overload for = operator

	friend std::istream &operator>>(std::istream &bnin, BigNumber &bn);			//	Overload for >> operator
	friend std::ostream &operator<<(std::ostream &bnout, BigNumber &bn);		//	Overload for << operator
};

BigNumber::BigNumber()
{
	_number = new char[10000];
	length = 0;
}

BigNumber::BigNumber(char *n)
{
	_number = n;
	_strrev(_number);
	length = strlen(_number);
}

BigNumber::BigNumber(const BigNumber &bn)
{
	length = bn.length;
	_number = new char[length + 1];

	for(int i = 0; i <= length; i++)
		_number[i] = bn._number[i];
}

BigNumber::~BigNumber()
{
	delete []_number;
}

BigNumber &BigNumber::operator=(BigNumber &bn)
{
	length = bn.length;
	strcpy(_number, bn._number);

	return *this;
}

std::istream &operator>>(std::istream &bnin, BigNumber &bn)
{
	bnin>>bn._number;
	bn.length = strlen(bn._number);
	_strrev(bn._number);
	return bnin;
}

std::ostream &operator<<(std::ostream &bnout, BigNumber &bn)
{
	BigNumber temp = bn;
	_strrev(temp._number);
	bnout<<temp._number;
	return bnout;
}

BigNumber BigNumber::operator+(BigNumber &bn)
{
	BigNumber bnsum;
	
	int maxlength = length;
	int minlength = bn.length;
	if(bn.length > maxlength)
	{
		maxlength = bn.length;
		minlength = length;
	}

	short carry = 0;
	for(int i = 0; i < minlength; i++)
	{
		short bn1 = _number[i] - 48;
		short bn2 = bn._number[i] - 48;
		
		short bn3 = (bn1 + bn2 + carry) % 10;
		carry = (bn1 + bn2 + carry) / 10;
		
		bnsum._number[i] = bn3 + 48;
	}

	if(length > bn.length)
	{
		for(int i = minlength; i < maxlength; i++)
		{
			short bn1 = _number[i] - 48;
			short bn2 = (bn1 + carry) % 10;
			carry = (bn1 + carry) / 10;

			bnsum._number[i] = bn2 + 48;
		}
	}
	else if(length < bn.length)
	{
		for(int i = minlength; i < maxlength; i++)
		{
			short bn1 = bn._number[i] - 48;
			short bn2 = (bn1 + carry) % 10;
			carry = (bn1 + carry) / 10;

			bnsum._number[i] = bn2 + 48;
		}
	}

	if(carry)
	{
		bnsum._number[maxlength] = carry + 48;
		bnsum._number[maxlength + 1] = '\0';
		bnsum.length = maxlength + 1;
	}
	else
	{
		bnsum._number[maxlength] = '\0';
		bnsum.length = maxlength;
	}

	return bnsum;
}

BigNumber BigNumber::operator-(BigNumber &bn)
{
	BigNumber bndiff;

	if(length > bn.length)
	{
		int maxlength = length;
		int minlength = bn.length;

		short carry = 0;

		for(int i = 0; i < minlength; i++)
		{
			short bn1 = _number[i] - 48;
			short bn2 = bn._number[i] - 48;
	
			short bn3;
			if(bn1 >= (bn2 + carry))
			{
				bn3 = bn1 - bn2 - carry;
				carry = 0;
			}
			else
			{
				bn3 = bn1 + 10 - bn2 - carry;
				carry = 1;
			}
			
			bndiff._number[i] = bn3 + 48;
		}

		for(int i = minlength; i < maxlength; i++)
		{
			short bn1 = _number[i] - 48;
			short bn2 = bn1 - carry;
			carry = 0;
			
			bndiff._number[i] = bn2 + 48;
		}

		bndiff._number[maxlength] = '\0';
		bndiff.length = maxlength;
	}
	else if(length < bn.length)
	{
		int maxlength = bn.length;
		int minlength = length;

		short carry = 0;

		for(int i = 0; i < minlength; i++)
		{
			short bn2 = _number[i] - 48;
			short bn1 = bn._number[i] - 48;
	
			short bn3;
			if(bn1 >= (bn2 + carry))
			{
				bn3 = bn1 - bn2 - carry;
				carry = 0;
			}
			else
			{
				bn3 = bn1 + 10 - bn2 - carry;
				carry = 1;
			}
			
			bndiff._number[i] = bn3 + 48;
		}

		for(int i = minlength; i < maxlength; i++)
		{
			short bn1 = bn._number[i] - 48;
			short bn2 = bn1 - carry;
			carry = 0;
			
			bndiff._number[i] = bn2 + 48;
		}

		bndiff._number[maxlength] = '-';
		bndiff._number[maxlength + 1] = '\0';
		bndiff.length = maxlength + 1;
	}
	else
	{
		for(int i = length-1; i > 0; i--)
		{
			if(_number[i] > bn._number[i])
			{
				short carry = 0;

				for(int i = 0; i < length; i++)
				{
					short bn1 = _number[i] - 48;
					short bn2 = bn._number[i] - 48;
	
					short bn3;
					if(bn1 >= (bn2 + carry))
					{
						bn3 = bn1 - bn2 - carry;
						carry = 0;
					}
					else
					{
						bn3 = bn1 + 10 - bn2 - carry;
						carry = 1;
					}
			
					bndiff._number[i] = bn3 + 48;
				}

				bndiff._number[length] = '\0';
				bndiff.length = length;

				break;
			}
			else if(_number[i] < bn._number[i])
			{
				short carry = 0;

				for(int i = 0; i < length; i++)
				{
					short bn2 = _number[i] - 48;
					short bn1 = bn._number[i] - 48;
	
					short bn3;
					if(bn1 >= (bn2 + carry))
					{
						bn3 = bn1 - bn2 - carry;
						carry = 0;
					}
					else
					{
						bn3 = bn1 + 10 - bn2 - carry;
						carry = 1;
					}
			
					bndiff._number[i] = bn3 + 48;
				}

				bndiff._number[length] = '-';
				bndiff._number[length + 1] = '\0';
				bndiff.length = length + 1;

				break;
			}
		}
	}

	return bndiff;
}

BigNumber BigNumber::operator*(BigNumber &bn)
{
	BigNumber bnprod;
	
	for(int i = 0; i < length; i++)
	{
		BigNumber bnsum;
		short carry = 0;
		short bn1 = _number[i] - 48;
		int k;
		for(k = 0; k < i; k++)
			bnsum._number[k] = '0';

		for(int j = 0; j < bn.length; j++)
		{
			short bn2 = bn._number[j] - 48;
			
			short bn3 = (bn1 * bn2 + carry) % 10;
			carry = (bn1 * bn2 + carry) / 10;
		
			bnsum._number[j + k] = bn3 + 48;
		}

		if(carry)
		{
			bnsum._number[bn.length + k] = carry + 48;
			bnsum._number[bn.length + k + 1] = '\0';
			bnsum.length = bn.length + k + 1;
		}
		else
		{
			bnsum._number[bn.length + k] = '\0';
			bnsum.length = bn.length + k;
		}

		bnprod = bnprod + bnsum;
	}

	return bnprod;
}