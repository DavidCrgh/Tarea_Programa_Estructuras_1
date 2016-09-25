#include "ventanaprincipal.h"
#include <QApplication>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

void insertion_sort(int arrNum[], string arrStr[], int length);
void print_array(int arrayNum[], string arrStr[], int size);

int main(int argc, char *argv[])
{
    //int array[5]= {5,4,3,2,1};
    int arrayNum[4] = {40,20,10,30};
    string arrayStr[4] = {"A","B","C","D"};
    insertion_sort(arrayNum,arrayStr,4);

     return 0;
    /*QApplication a(argc, argv);
    VentanaPrincipal w;
    w.show();

    return a.exec();*/
}

void insertion_sort(int arrNum[],string arrStr[], int length) {
 int i, j ,tmp1;
 string tmp2;
 for (i = 1; i < length; i++) {
 j = i;
 while (j > 0 && arrNum[j - 1] > arrNum[j]) {
 tmp1 = arrNum[j];
 tmp2 = arrStr[j];
 arrNum[j] = arrNum[j - 1];
 arrStr[j] = arrStr[j - 1];
 arrNum[j - 1] = tmp1;
 arrStr[j - 1] = tmp2;
 j--;
 }//end of while loop
 print_array(arrNum,arrStr,4);
 }//end of for loop
 }//end of insertion_sort.

void print_array(int arrayNum[],string arrayStr[], int size){

 cout<< "sorting: ";
 int j;
 for (j=0; j<size;j++)
 for (j=0; j<size;j++){
    cout <<" "<< arrayNum[j];
    cout <<" "<< arrayStr[j];
}
 cout << endl;
 }//end of print_array
