/*Object Oriented Programming
Classes
* Members of a class and accessing them
* in Class/Inline definition and definition using operator ::
* cONSTRUCTOR HAS TO BE PUBLIC
* Private functions CAN access private members//TRIVIAl
* Over loading the constructor
* Overloading class functions
* Subclass and protected members
* subclass has its own constructor. But first..
the base class constructor(default one) is called and then the subclass's 

*/

#include <iostream>
#include <stdio.h>

using namespace std;
//Simple class with simple public members/Objects and functions
class Box{
public://Accessable outside the class
	int size_x = 10;
	int size_y = 20;
	int pages = 300;
	
	Box(void)
	{
		cout<< "Box(void)" << endl;
	}
	
	Box(int p)
	{
		cout << "Box(int p)" << endl;
		int secret_number = p;
		no_chapters = secret_number;
	}

	// Following are inclass inline definitions by default.
	void set_no_chp(int input)
		{
			no_chapters = input;//Private members can be accessed by member functions.
			cout << "revised chapters are " << input <<endl;
		}

	int get_no_chp()
		{
			return no_chapters;
		}

	void set_pages(int input);
	void set_pages(int input1, int input2 );

private: //Accessable only inside the class.
	int no_chapters = 25;
	void set_private_ch()
	{
		cout << "Chaptrs" << no_chapters << endl;
	}
protected: //can be accessed by subclasses
	int secret_code=100;

};

class smallbox:public Box //the  subclass
{
public:
	smallbox(int a, int b)
	{
		cout << "Im tired of this shit  a = " << a << " and b = " << b << endl;
	}
};



void Box::set_pages(int input)
{
	pages = input;
}

void Box::set_pages(int input1, int input2 )
{
	pages = input1+input2;
}

int main()
{
	Box Box1;//Creating two instances of a class
	Box Box2(500);//Overloading Constructor
	cout << Box1.size_x << " is the height of book" << endl;//Accessing a class member using ().();
	cout << " No of chapters in Box1 " << Box1.get_no_chp() << endl;
	cout << " No of chapters in Box2 " << Box2.get_no_chp() << endl;

	Box1.set_no_chp(30);
	Box1.set_pages(500);
	cout << Box1.pages << " are the no of pages " << endl;
	//cout<<Box1.secret_number<<endl;
	Box1.get_no_chp();

	
	smallbox Box3(); 
		//smallbox Box4(54);
	    smallbox Box5(4, 5); cout << Box5.size_x << endl;
}

