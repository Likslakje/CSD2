#include <iostream>
using namespace std;

int main(){
    //een varibale met een memory adress en een waarde van int 8
    int var = 8;
    // int* ptr points naar het memory adress van var met &
    int* ptr = &var;
    //krijg de waarde van ptr op het memory adress van var
    cout<< *ptr <<endl;
}