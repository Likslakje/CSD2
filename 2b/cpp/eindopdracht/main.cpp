//All credits for writeToFile and sine go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#include <iostream>
// #include "oscillator.h"
#include "sine.h"
#include "input.h"
#include "writeToFile.h"
using namespace std;

int main(){
  
    UserInput userInput;
    // if(userInput.choiceCheck){
      Sine sine(220);
    //   std::cout << "Sine frequency: " << sine.getFrequency() << "\n";
    //   sine.setFrequency(10);
    //   std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

    //   // write 1 second of samples to file
    //   // second parameter - overwrite is set to true
    //   WriteToFile fileWriter("output.csv", true);
    //   for(int i = 0; i < SAMPLERATE; i++) {
    //       fileWriter.write(std::to_string(sine.getSample()) + "\n");
    //       sine.tick();
    //   }
    // }

  // end of program
  return 0;
}



// int main(){
//     input();
//     while (true) {
//         for(int i = 0; i < 4; i++){
//             try{
//                 if(inputWaveform != waveforms[i]){
//                     if(i == 3){
//                         cout<< inputWaveform << " does not exist" <<endl;
//                         input();
//                     }
//                 }else{
//                     throw(inputWaveform);
//                 }
//             }
//             catch(string waveformCatch){
//                 cout<< inputWaveform << " exists" <<endl;
//                 break;
//             }
//         }
//         break;
//     }
//     return 0;
// }