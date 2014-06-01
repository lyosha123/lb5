#include <vector>
#include <time.h>
#include <iostream>
using namespace std;


class C_Char
{
private:
	///Class value
	char Symbol;
public:
	C_Char();
	~C_Char();
	///Constructor
	/// @param char value
	C_Char(char value);
	///Constructor
	///@param C_Char class object
	C_Char(const C_Char& ch);
	///Overloading of > operator
	bool          operator>(C_Char& a);
	///Overloading of < operator
	bool          operator<(C_Char& a);
	///Overloading of = operator
	C_Char&       operator=(C_Char& a);
	///Overloading of = operator
	C_Char&       operator=(char a);
	/// Swap values of two objects
	/// @param Second object
	void          swap(C_Char& a);
	/// Display the value
	void          print();

};

C_Char::C_Char() : Symbol(' ')
{  }


C_Char::~C_Char(void)
{  }

C_Char::C_Char(char value) : Symbol(value)
{    }

C_Char::C_Char(const C_Char& ch) : Symbol(ch.Symbol)
{    }

bool      C_Char::operator>(C_Char& a)
{
	return Symbol > a.Symbol;
}

bool      C_Char::operator<(C_Char& a)
{
	return Symbol < a.Symbol;
}

C_Char&   C_Char:: operator=(C_Char& a)
{
	if (this == &a) return *this;

	Symbol = a.Symbol;
	return *this;

}

C_Char&    C_Char::operator=(char a)
{
	Symbol = a;
	return *this;
}


void C_Char::swap(C_Char& a)
{
	char temp = Symbol;
	Symbol = a.Symbol;
	a.Symbol = temp;
	return;
}

void C_Char::print()
{
	cout << Symbol << "  ";
}

class Float
{
public:
	Float();
	///Constructor
	/// @param float value
	Float(float value);
	///Constructor
	///@param Float class object
	Float(const Float& f);
	///Overloading of > operator
	bool             operator>(Float& a);
	///Overloading of < operator
	bool             operator<(Float& a);
	///Overloading of = operator
	Float&           operator=(Float& a);
	///Overloading of = operator
	Float&           operator=(int a);
	///Overloading of = operator
	Float&           operator=(float a);
	/// Swap values of two objects
	/// @param Second object
	void             swap(Float& a);
	/// Display the value
	void             print();

private:
	///Class value
	float Number;

};

Float::Float() : Number(0)
{	}
Float::Float(float value) : Number(value)
{    }
Float::Float(const Float& f) : Number(f.Number)
{    }

bool      Float::operator>(Float& a)
{
	return Number > a.Number;
}

bool      Float::operator<(Float& a)
{
	return Number < a.Number;
}

Float&   Float:: operator=(Float& a)
{
	if (this == &a) return *this;

	Number = a.Number;
	return *this;

}

Float&    Float::operator=(int a)
{
	Number = (float)a;
	return *this;
}

Float&    Float::operator=(float a)
{
	Number = a;
	return *this;
}


void Float::swap(Float& a)
{
	float temp = Number;
	Number = a.Number;
	a.Number = temp;
	return;
}

void Float::print()
{
	cout << Number << "  ";
}

bool swapFl(Float& a, Float& b)
{
	a.swap(b);
	return true;
}
template <class T>
void sort(T* Array, int first, int last, bool(*swap)(T&a, T&b))
{
	int i = first, j = last;
	T middle = Array[(first + last) / 2];

	do {
		while (Array[i] < middle) i++;
		while (Array[j] > middle) j--;

		if (i <= j)
		{
			if (i < j) (*swap)(Array[i], Array[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		sort(Array, i, last, swap);
	if (first < j)
		sort(Array, first, j, swap);
}


bool swapSymbols(C_Char& a, C_Char& b)
{
	a.swap(b);
	return true;
}

int main()
{
	Float arr[10];
	C_Char sym[10];
	bool(*ptr)(Float&, Float&);
	bool(*Sptr)(C_Char&, C_Char&);

	srand(time(NULL));

	for (int itr = 0; itr < 10; itr++)
	{
		arr[itr] = (float)(rand() % 200 / 3.14 - 10);
		sym[itr] = rand() % 26 + 65;
		arr[itr].print();
	}
	cout << endl;

	for (int itr = 0; itr < 10; itr++)
		sym[itr].print();

	cout << endl << endl << "///////////////////////////////////////////////" << endl << endl;

	ptr = swapFl;
	Sptr = swapSymbols;
	sort(arr, 0, 9, ptr);
	sort(sym, 0, 9, Sptr);


	for (int itr = 0; itr < 10; itr++)
		arr[itr].print();
	cout << endl << endl;

	for (int itr = 0; itr < 10; itr++)
		sym[itr].print();

	cout << endl << endl;

	system("pause");
	return 0;
}
