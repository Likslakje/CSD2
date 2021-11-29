#include <iostream>
using namespace std;
/*
For frequencies:
fn = f0 * 2^(n/12)
Where: n = the frequency to be calculated
    f0 = the base frequency which is A4 or 440Hz

For midinote numbers:
fn = 440 * 2^((nm - 69) / 12)
Where: nm = the midinote to be calculated
    440 is the base frequency or A4
*/

float fn;
float nm = 80;

int main(){
    fn = 440 * pow(2.0, (nm - 69.0) / 12.0);
    cout<< fn <<endl;

}