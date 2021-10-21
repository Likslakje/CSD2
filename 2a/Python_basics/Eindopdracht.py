import simpleaudio as sa #audio functions
import inquirer #user input functions
import random #random functions
import time #time functions
import threading #multithreading

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

kick_event = {
    'filename': kick,
    'instrumentname': 'kick',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'threadID': 1,
    'loop': 1,
    'playCheck': True
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'threadID': 2,
    'loop': 1,
    'playCheck' : True
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'threadID': 3,
    'loop': 1,
    'playCheck' : True
}

allSampleDict = {'kick' : kick_event, 'snare' : snare_event, 'hihat' : hihat_event} #This is a nested dictionary
bpm = 120
# def bpm_choice(): 
#     #this function let's you choose a BPM, the default is set to 120
#     print("Default BPM is set to 120, would you like to change the BPM (y/n): ")
#     bpmChoice = input()
#     if bpmChoice == "n" :
#         bpm = 120
#     elif bpmChoice == "y" :
#         bpm = int(input("Enter a new BPM: " ))
#     else :
#         print("Please enter valid input, 'y' or 'n' only")
#         bpm_choice() #If the user input doesn't match then execute the function again
#     return bpm
# bpm = bpm_choice()

def measure():
    #This function takes a user input for the measure
    #Only numeric inputs are allowed
    #if an unvalid input is entered, it tries to get an input again
    while True:
        try:
            numerator, denominator = input('set numerator and denominator ').split()
            if numerator.isnumeric() and denominator.isnumeric():
                numerator = int(numerator)
                denominator = int(denominator)
                if numerator >= 1 and numerator <= 8 and denominator >= 1 and denominator <= 8:
                    print('we cool')
                    break
                else:
                    raise ValueError
        except ValueError:
            print('Please enter valid input, integers only \nMIN is 1 \nMAX is 8')
            continue
    return numerator, denominator
numerator, denominator = measure()

def duration_16th_note(_bpm):
    #This function calculates the length of 1 sixteenth note
    return((60 / _bpm) / 4) #Whole note = 60/bpm, a sixteenth note = 1/4 of a whole note
 

def random_rythm():
    noteDurationsTypes = [1, 2, 4 , 8 ,16] #whole, half, quarter, eighth and sixteenth notes
    noteDurationsValues = [] #This array stores the note values (of noteDurationsTypes) depending on the set bpm
    numberSixteenthSteps = numerator * denominator #Number of sixteenth steps within a measure
    noteDuration16th = duration_16th_note(bpm) #Execute the function with a default BPM value
    kickArray = []
    totalTimeNoteValues = numberSixteenthSteps * noteDuration16th #Calculate the maximum time depending on the value of one 16th note and the set measure
    for i in noteDurationsTypes:
        noteDurationsValues.append(noteDuration16th * i)
    #Pick a random number
    #then check what note value it corolates with
    #append this note value to the choosen sample_event dictionary
    sum = 0
    randomNoteValue = random.random()
    for j in range(len(noteDurationsTypes)):
        if randomNoteValue >= (1 * j)/len(noteDurationsTypes) and randomNoteValue <= (1 * (j + 1))/len(noteDurationsTypes):
            kickArray.append(noteDurationsValues[j])
            sum = sum + noteDurationsValues[j]

    print(totalTimeNoteValues)
    print(noteDurationsValues)
    print(kickArray)
    print(sum)
        


random_rythm()

# def instrumentname_choice():
#     #User input multiple choice to set the instrumentname inside the dictionary
#     instrumentChoiceQuestion = [
#         inquirer.List('instrumentname', 
#                     message = 'Choose sample ',
#                     choices = ['kick', 'snare', 'hihat'],
#                     carousel = True)] #Makes scroll infinite
#     instrumentChoiceAnswer = inquirer.prompt(instrumentChoiceQuestion)
#     return instrumentChoiceAnswer['instrumentname']

# def numberSteps_noteDurations_input():
#     #This function put the user rythm input in the right sample dictionary
#     print("Choose number of steps for " + str(instrumentnameChoiceAnswer) + " drumline")
#     allSampleDict[instrumentnameChoiceAnswer]['numberSteps'] = int(input())
#     #Check if the choosen directory excits
#     if instrumentnameChoiceAnswer in allSampleDict :
#         print("Type rythmic patern for " + str(instrumentnameChoiceAnswer) + " drumline")
#         #Add as many elements (as there are numberSteps) to the noteDurations array of the sample_event within the allSampleDict
#         for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
#             allSampleDict[instrumentnameChoiceAnswer]['noteDurations'].append(float(input()))
#             i += 1

# def noteDurations_to_noteDurations16th(_noteDurations):
#     #This function transforms each element in noteDurations (of the choosen sample_event) into sixteenth notes
#     i = 0
#     for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
#         #We use float() here because we want to devide by a float number
#         allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'].append(float(_noteDurations[i]) / 0.25)
#         i += 1

# def noteDurations16th_to_timeStamps(_noteDurations16th):
#     #This function transforms the noteDuration16th (of the choosen sample_event) in to time values in milliseconds
#     #then it adds these timevalues to one and other, and puts them in the timeStamps array (of the choosen sample_event)
#     sum = 0
#     for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
#         allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'].append(float(_noteDurations16th[i] * noteDuration16th))
#         sum = sum + allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'][i]
#         allSampleDict[instrumentnameChoiceAnswer]['timeStamps'].append(sum)

# def edit_rythm():
#     editRythmQuestion = [
#         inquirer.List('editChoice',
#                     message = 'What would you like to do?',
#                     choices = ['generate new', 'overwrite'],
#                     carousel = True)]
#     editRythmAnswer = inquirer.prompt(editRythmQuestion)
#     return editRythmAnswer['editChoice']

# def sample_loop():
#     print("Type 1 to loop or 0 to unloop \nCurrent loopstate for " + instrumentnameChoiceAnswer + " is set to " + str(allSampleDict[instrumentnameChoiceAnswer]['loop']))
#     loopAnswer = int(input())
#     if loopAnswer == 0 or loopAnswer == 1:
#         allSampleDict[instrumentnameChoiceAnswer]['loop'] = loopAnswer
#     else:
#         print('Please enter valid input, 0 or 1 only')
#         sample_loop()

# class AudioPlayThread(threading.Thread):
#     #This class makes a thread that is used to play audio
#     #we get the nessesary arguments from the allSamplesDict
#     def __init__(self, threadID, timeStamps, filename, numberSteps, loop, playCheck):
#         threading.Thread.__init__(self)
#         self.threadID = threadID
#         self.timeStamps = timeStamps
#         self.filename = filename
#         self.numberSteps = numberSteps
#         self.loop = loop
#         self.playCheck = playCheck

    # def run (self):
    #     #This is a build in function to run the thread
    #     self.timeZero = time.time() #Get the current time
    #     self.i = 0
    #     #While playCheck for the choosen sample_event is True
    #     #check if it is time to play an event and check if the choosen sample_event should loop
    #     while self.playCheck: 
    #         self.timeCurrent = time.time() - self.timeZero
    #         if(self.timeCurrent >= float(self.timeStamps[self.i])):
    #             self.filename.play()
    #             self.i += 1
    #         if self.i == self.numberSteps and self.loop == 0:
    #             self.filename.wait.done()
    #         if self.i == self.numberSteps and self.loop == 1:
    #             self.i = 0
    #             self.timeZero = time.time()
    #         time.sleep(0.0001)

# while True:
#     #This loop keeps expecting an user input
#     userInput = str(input("Type edit, play, loop, stop or exit : "))
#     if userInput == 'edit':
#         editAnswer = edit_rythm()
#         if editAnswer == 'generate new':
#             instrumentnameChoiceAnswer = instrumentname_choice() #We can choose a sample_event here
#             if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#                 pass
#         elif editAnswer == 'overwrite':
#             instrumentnameChoiceAnswer = instrumentname_choice() #We can choose a sample_event here
#             if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']: #Check if the choosen sample_event exists
#                 numberSteps_noteDurations_input()
#                 noteDurations_to_noteDurations16th(allSampleDict[instrumentnameChoiceAnswer]['noteDurations'])
#                 noteDurations16th_to_timeStamps(allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'])
#     elif userInput == 'play':
#         instrumentnameChoiceAnswer = instrumentname_choice()
#         if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#             playAudioInstrument = "playAudio" + allSampleDict[instrumentnameChoiceAnswer]['instrumentname']
#             threadID = allSampleDict[instrumentnameChoiceAnswer]['threadID']
#             instrumentname = allSampleDict[instrumentnameChoiceAnswer]['instrumentname']
#             timeStamps = allSampleDict[instrumentnameChoiceAnswer]['timeStamps']
#             filename = allSampleDict[instrumentnameChoiceAnswer]['filename']
#             numberSteps = allSampleDict[instrumentnameChoiceAnswer]['numberSteps']
#             loop = allSampleDict[instrumentnameChoiceAnswer]['loop']
#             playCheck = allSampleDict[instrumentnameChoiceAnswer]['playCheck']
#             playAudioInstrument = AudioPlayThread(threadID, timeStamps, filename, numberSteps, loop, playCheck)
#             playAudioInstrument.playCheck = True
#             playAudioInstrument.start()
#     elif userInput == 'loop':
#         instrumentnameChoiceAnswer = instrumentname_choice()
#         if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#             sample_loop()
#             playAudioInstrument.loop = allSampleDict[instrumentnameChoiceAnswer]['loop']
#     elif userInput == 'stop':
#         instrumentnameChoiceAnswer = instrumentname_choice()
#         if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#             allSampleDict[instrumentnameChoiceAnswer]['playCheck'] = False
#             playAudioInstrument.playCheck = False
#     elif userInput == 'exit':
#         # playAudio.join()
#         # playAudio.isPlaying = False
#         for i in range(len(allSampleDict)):
#             #playAudio + allSampleDict[].join()
#             pass
#         break
#     else:
#         print("Please use a valid input")



