/*Classes_Friend_functions

*A friend can be a function, function template, or member function,
 or a class or class template, in which case the entire class 
 and all of its members are friends.




*/

#include <iostream>
#include <stdio.h>

using namespace std;

class base
{
	public:
		int pub_mem = 10;
	
	base() //constructor
	{
		cout << " constructor base() " << endl;
	}

	base(int a, int b) //over-loaded constructor
	{
		pub_mem = a;
		pri_mem = b; 
		cout << " constructor base(int a, int b) " << endl ;
	}

	base(const base &obj) //copy_constructor;
	{
		
		cout << " copy_constructor " << endl;
	}
	
	friend void ami_func(base Base);
	
	void base_public( int a)
 		{
			cout<<" function base_public" << endl;
			//return pri_mem;
		}
	
	friend void ami_pub(base Base);
	
	private:
		int pri_mem = 20;

		void base_private(int a)
		{
			cout << " function base_private" << endl;
		}
		friend void ami_pri(int a, base Base);
		
	protected:
		int pro_mem = 30;
		
		void base_protected(int a)
		{
			cout << " function base_protected" << endl;
		}
		friend void ami_pro(base Base);
		
};


class sub_pub:public base
{
	public: 
		int pub_mem = 10;
	
	private:
		int pri_mem = 20;

	protected:
		int pro_mem = 30;
};

class sub_pri :private base
{
public:
	int pub_mem = 10;

	private:
		int pri_mem = 20;

protected:
	int pro_mem = 30;
};

class sub_pro :protected base
{
public:
	int pub_mem = 10;

	private:
		int pri_mem = 20;

protected:
	int pro_mem = 30;
};

void ami_pub(base Base)
{
	cout<< "ami_pub " << endl;
	//cout << "int a : " << a << "int b :" << b << endl;
	cout << "pub_mem :" << Base.pub_mem << endl;
	cout << "pri_mem :" << Base.pri_mem << endl;
	cout << "pro_mem :" << Base.pro_mem << endl;
} 


void ami_pri(int a, base Base)
{
	cout<< "ami_pri " << endl;
	//cout << "int a : " << a << "int b :" << b << endl;
	cout << "pub_mem :" << Base.pub_mem << endl;
	cout << "pri_mem :" << Base.pri_mem << endl;
	cout << "pro_mem :" << Base.pro_mem << endl;
} 

void ami_pro(base Base)
{
	cout<< "ami_function " << endl;
	//cout << "int a : " << a << "int b :" << b << endl;
	cout << "pub_mem :" << Base.pub_mem << endl;
	cout << "pri_mem :" << Base.pri_mem << endl;
	cout << "pro_mem :" << Base.pro_mem << endl;
} 
int main()
{
	base BASE1(5,15);
	base BASE2 = BASE1;
	BASE2.pub_mem = 150;
	cout<< " BASE1 pub_mem " << BASE1.pub_mem << endl;
}

/*#include <iostream>

using namespace std;

class Line
{
   public:
      int getLength( void );
	  void setLength( int len);
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
   ptr = obj.ptr; // point to pointer.
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}


void display(Line obj)
{
   cout << "Length of line : " << obj.getLength() <<endl;
}

void Line::setLength( int len )
{
	*ptr = len;
}
// Main function for the program
int main( )
{
   Line line1(10);

   int a=0;
   int* p;
   p=&a;
   
  int* p2;
   p2=p;
   
   cout<<"p2 value :" << *p2 <<endl;
   
   Line line2 = line1; // This also calls copy constructor
   
   
   display(line1);
   display(line2);

	line1.setLength(20);
	line2.setLength(30);
	
	display(line1);
	display(line2);
   
   return 0;
}
*/