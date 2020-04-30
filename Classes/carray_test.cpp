/*
 * file: carray_test.cpp
 * cArray class declaration
 * written: 29/11/2019
 */
#include "carray.h"

int main() {
	//constructor
	cout << "Consructor:" << endl;
	cArray *arr = new cArray;
	cArray *temp = NULL;
	cout << endl << "Size = "<< arr->Getsize()<<" Count = "<<arr->Getcount() << " Upperbound = "<< arr->Getupperbound() << endl;
	arr->printArr();

	cout << endl << "Setsize():" << endl;

	//-8
	arr->SetSize(15);
	for (int i = 0; i < arr->Getsize() - 5; i++) {
		//SetAt()
		arr->SetAt(i, i);
	}
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();
	
	cout << "FreeExtra():" << endl;
	//freeextra()
	arr->FreeExtra();
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	//add()
	cout << "Add():" << endl;
	arr->Add(220);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	//Get at
	cout << "GetAt():" << endl;
	cout << "Get at -  " << arr->GetAt(5) << endl << endl;

	//removeall
	cout << "RemoveAll:" << endl;
	arr->RemoveAll();
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();
	//fill
	for (int i = 0; i < arr->Getsize(); i++) {
		//SetAt()
		arr->SetAt(i, i);
	}
	cout << "arr:" << endl;
	arr->SetSize(5);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();
	
	cArray* arr2 = new cArray;
	cout << "arr2:" << endl;
	arr2->SetSize(15);
	for (int i = 0; i < arr2->Getsize(); i++) {
		arr2->SetAt(i, i);
	}
	arr2->printArr();

	//append
	cout << "Apend():" << endl;
	arr->Append(arr2);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	cout << "Copy():" << endl;
	//arr->Copy(NULL);
	arr->Copy(arr2);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	cout << "Opertaor [] ";
	cout << (*arr)[14] << endl << endl;

	cout << "InsertAt():" << endl;
	arr->InsertAt(23,2);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	cout << "RemoveAt():" << endl;
	arr->RemoveAt(2);
	cout << endl << "Size = " << arr->Getsize() << " Count = " << arr->Getcount() << " Upperbound = " << arr->Getupperbound() << endl;
	arr->printArr();

	return 0;
}