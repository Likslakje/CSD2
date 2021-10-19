import simpleaudio as sa # audio functionaliteiten
import inquirer # user input functionaliteiten
import time # time
import threading # voor multithreading

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
    'loop' : 1
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'loop' : 1
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'loop' : 1
}

allSampleDict = {'kick' : kick_event, 'snare' : snare_event, 'hihat' : hihat_event} # dit is een nested dictionary
loopinput = 1

bpm = 120
def bpm_choice(): 
    #functie voor de y/n vraag voor bpm
    print("Default BPM is set to 120, would you like to change the BPM (y/n): ")
    bpmChoice = input()
    if bpmChoice == "n" :
        bpm = 120
    elif bpmChoice == "y" :
        bpm = int(input("Enter a new BPM: " ))
    else :
        print("Please enter valid input, 'y' or 'n' only")
        bpm_choice() #als input niet matched dan voer de functie choice opnieuw uit
    return bpm

def duration_16th_note(_bpm):
    # de lengte van 1 16de noot wordt uitgereknd aan de hand van het bpm
    return((60 / _bpm) / 4)# hele noot = 60/bpm, 16de = 1/4 van een hele noot
noteDuration16th = duration_16th_note(bpm) #voer functie uit met default bpm waarde

def instrumentname_choice():
    # multiple choice voor de instrumentname
    instrumentChoiceQuestion = [
        inquirer.List('instrumentname', 
                    message = 'Choose sample ',
                    choices = ['kick', 'snare', 'hihat'],
                    carousel = True)] # zorgt voor infinite scroll
    instrumentChoiceAnswer = inquirer.prompt(instrumentChoiceQuestion) 
    global instrumentnameChoiceAnswer
    instrumentnameChoiceAnswer = instrumentChoiceAnswer['instrumentname']

def numberSteps_noteDurations_input():
    # stop het ingegeven rithme in de juiste sample dictionary
    print("Choose number of steps for " + str(instrumentnameChoiceAnswer) + " drumline")
    allSampleDict[instrumentnameChoiceAnswer]['numberSteps'] = int(input())
    # check of de gekozen dictionary bestaat
    if instrumentnameChoiceAnswer in allSampleDict :
        print("Type rythmic patern for " + str(instrumentnameChoiceAnswer) + " drumline")
        # voeg zoveel elementen (als er numberSteps zijn) aan de noteDurations array, van sample_event binnen allSampleDict, toe 
        for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
            allSampleDict[instrumentnameChoiceAnswer]['noteDurations'].append(float(input()))
            i += 1

def noteDurations_to_noteDurations16th(_noteDurations):
    # zet voor elke step de noteDurations input, van het gekozen sample_event, om in een 16de
    i = 0
    for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
        allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'].append(float(_noteDurations[i]) / 0.25)
        i += 1

def noteDurations16th_to_timeStamps(_noteDurations16th):
    # zet noteDuration16th om naar tijdswaardes van 16de noten in milisecondes, daarna tel deze waardes bij elkaar op voor timeStamps
    sum = 0
    # Voor het elke step, zet de 16de noot om in milisecondes. Tel deze milisecondes bij elkaar op
    for i in range(allSampleDict[instrumentnameChoiceAnswer]['numberSteps']):
        allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'].append(float(_noteDurations16th[i] * noteDuration16th))
        sum = sum + allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'][i]
        allSampleDict[instrumentnameChoiceAnswer]['timeStamps'].append(sum)

def sample_loop():
    print("Type 1 to loop or 0 to unloop \nCurrent loopstate for " + instrumentnameChoiceAnswer + " is set to " + str(allSampleDict[instrumentnameChoiceAnswer]['loop']))
    allSampleDict[instrumentnameChoiceAnswer]['loop'] = int(input())
    playAudio.playCheck = allSampleDict[instrumentnameChoiceAnswer]['loop']

class AudioPlayThread(threading.Thread):
    def __init__(self, threadID, name, playCheck):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.playCheck = playCheck
        print(playCheck)

    def sample_player(self):
        self.timeZero = time.time()
        self.i = 0
        while True:
            self.timeCurrent = time.time() - self.timeZero
            if(self.timeCurrent >= float(allSampleDict[instrumentnameChoiceAnswer]['timeStamps'][self.i])):
                allSampleDict[instrumentnameChoiceAnswer]['filename'].play()
                self.i += 1
            if self.i == allSampleDict[instrumentnameChoiceAnswer]['numberSteps'] and allSampleDict[instrumentnameChoiceAnswer]['loop'] == 1:
                self.i = 0
                self.timeZero = time.time()
            time.sleep(0.0001)
playAudio = AudioPlayThread(1, "AudioThread", 0)
playAudio.start()

# class UserInputThread(threading.Thread):
#     def __init__(self, threadID, name):
#         threading.Thread.__init__(self)
#         self.threadID = threadID
#         self.name = name

#     def user_input(self):
#         while True:
#             self.userInput = str(input("Type edit, play, loop, stop, bpm or exit : "))
#             if self.userInput == 'edit':
#                     instrumentname_choice() #retrunt de gekozen sample in instrumentnameChoiceAnswer
#                     if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']: # als de gekozen sample voor komt in de allSampleDict dictionary dan...
#                         numberSteps_noteDurations_input() # voer deze functie uit (-> bepaald het aantal steps en notedurations)
#                         noteDurations_to_noteDurations16th(allSampleDict[instrumentnameChoiceAnswer]['noteDurations']) # zet de noteDuartions uit de dictionary om naar 16de noten
#                         noteDurations16th_to_timeStamps(allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th']) # zet de noteDurations16th om naar timestamps
#                         print(allSampleDict)
#             elif self.userInput == 'play':
#                 instrumentname_choice()
#                 if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#                     playAudio.sample_player()
#             elif self.userInput == 'loop':
#                 instrumentname_choice()
#                 sample_loop()
#                 print(allSampleDict)
#             elif self.userInput == 'stop':
#                 instrumentname_choice()
#                 if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
#                     print('lets stop ' + instrumentnameChoiceAnswer)
#             elif self.userInput == 'bpm':
#                 bpm = bpm_choice()
#                 noteDuration16th = duration_16th_note(bpm)
#                 print(bpm)
#                 print(noteDuration16th)
#             elif self.userInput == 'exit':
#                 break
#             else:
#                 print("Please use a valid input")
# awaitUserInput = UserInputThread(2, "UserThread")
# awaitUserInput.user_input()

while True:
    userInput = str(input("Type edit, play, loop, stop, bpm or exit : "))
    if userInput == 'edit':
            instrumentname_choice() #retrunt de gekozen sample in instrumentnameChoiceAnswer
            if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']: # als de gekozen sample voor komt in de allSampleDict dictionary dan...
                numberSteps_noteDurations_input() # voer deze functie uit (-> bepaald het aantal steps en notedurations)
                noteDurations_to_noteDurations16th(allSampleDict[instrumentnameChoiceAnswer]['noteDurations']) # zet de noteDuartions uit de dictionary om naar 16de noten
                noteDurations16th_to_timeStamps(allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th']) # zet de noteDurations16th om naar timestamps
                print(allSampleDict)
    elif userInput == 'play':
        instrumentname_choice()
        if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
            playAudio.sample_player()
    elif userInput == 'loop':
        instrumentname_choice()
        sample_loop()
        print(allSampleDict)
    elif userInput == 'stop':
        instrumentname_choice()
        if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
            print('lets stop ' + instrumentnameChoiceAnswer)
    elif userInput == 'bpm':
        bpm = bpm_choice()
        noteDuration16th = duration_16th_note(bpm)
        print(bpm)
        print(noteDuration16th)
    elif userInput == 'exit':
        break
    else:
        print("Please use a valid input")


