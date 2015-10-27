/*Data Structures
*Defining structs
*Short define
*Accessing its members
*Passing to functions as variables and pointers
*Accessing struct pointer members using ->
*/

#include <iostream>
#include <stdio.h>

using namespace std;


struct data_struct
{
	int int_var;
	int int_arr[20]; // What about variable size arrays? How to define them in structs?
	int char_arr[50];
	
}DS; //IGNORE:: Misleading thing This name acts as alias to the struct.

void func_var_struct_input(data_struct var_struct)
{
		cout << var_struct.int_var << ":in the int variable" << endl;
		var_struct.int_var = 20;
}

void func_pointer_struct_input(data_struct *var_struct)
{
	cout << var_struct->int_var << ":in the int variable" << endl;
	var_struct->int_var = 20;
}


int main()
{
	struct data_struct Struct1;
	//struct DS Struct2; Invalid definition.
	data_struct Struct3;
	//DS Struct4; Invalid Declaration
	Struct3.int_var = 30;
	func_var_struct_input(Struct3);
	cout << "after var_function" << Struct3.int_var << endl;
	
	data_struct *Struct_pointer; //Struct Pointers
	Struct_pointer = &Struct3;   //Struct Pointers
	func_pointer_struct_input(Struct_pointer);
	cout << "after pointer_function" << Struct_pointer->int_var << endl; // Members accessed from pointers
	
	
	
	
}



