print('type username')
username = input()
print('Hello', username,'!')
import inquirer
sampleQuestion = [
  inquirer.List('sample',
                message='Which sample would you like to play?',
                choices=['AardvarkRover1', 'BorgStrobe', 'MystixOverview'],
            ),
]
sampleAnswer = inquirer.prompt(sampleQuestion)

print('How many times would you like to play the sample?')
timesSampleInput = input()
timesSample = int(timesSampleInput) #maakt van de input string een interger
print('Alright, I will play ' + sampleAnswer['sample'] + ' ' + timesSampleInput + ' times!')

import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("/Users/mila/Documents/Muziek_Technologie/MT_jaar_2/CSD2/2a/Python_basics/" + sampleAnswer['sample'] + ".wav")
for x in range (timesSample):
    play_obj = wave_obj.play()
    play_obj.wait_done()
    x += 1  
    if x > timesSample:
        timesSample = 0
