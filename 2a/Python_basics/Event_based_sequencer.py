import simpleaudio as sa # audio functionaliteiten
import inquirer # user input functionaliteiten
import time # time

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

kick_event = {
    'filename': kick,
    'instrumentname': 'kick',
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'velocity': 127,
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'velocity': 127,
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
    'velocity': 127,
}

allSampleDict = {'kick' : kick_event, 'snare' : snare_event, 'hihat' : hihat_event} # dit is een nested dictionary
bpm = 120

# def bpmchoice(): 
#     #functie voor de y/n vraag voor bpm
#     bpmChoice = input("Default BPM is set to 120, would you like to change the BPM (y/n): ")
#     if bpmChoice == "n" :
#         bpm = 120
#         return bpm
#     elif bpmChoice == "y" :
#         bpm = int(input("Enter a new BPM: " ))
#         return bpm
#     else :
#         print("Please enter valid input, 'y' or 'n' only")
#         bpmchoice() #als input niet matched dan voer de functie choice opnieuw uit
# bpm = bpmchoice() #bpm is gelijk aan het resultaat van de functie choice

def duration_16th_note(_bpm):
    # de lengte van 1 16de noot wordt uitgereknd aan de hand van het bpm
    return((60 / _bpm) / 4)# hele noot = 60/bpm, 16de = 1/4 van een hele noot
noteDuration16th = duration_16th_note(bpm)

def instrumentname_choice():
    # multiple choice voor de instrumentname
    instrumentChoiceQuestion = [
        inquirer.List('instrumentname', 
                       message = 'Choose instrument',
                       choices = ['kick', 'snare', 'hihat'],
                       carousel = True)] # zorgt voor infinite scroll
    instrumentChoiceAnswer = inquirer.prompt(instrumentChoiceQuestion)
    return instrumentChoiceAnswer['instrumentname']
instrumentnameChoiceAnswer = instrumentname_choice()

print("Choose number of steps for " + str(instrumentnameChoiceAnswer) + " drumline")
numberSteps = int(input())

print("Type rythmic patern for " + str(instrumentnameChoiceAnswer) + " drumline")
def noteDurations_input():
    # stop het ingegeven rithme in de juiste sample dictionary
    # check of de gekozen dictionary bestaat
    if instrumentnameChoiceAnswer in allSampleDict :
        # voeg zoveel elementen (als er numberSteps zijn) aan de noteDurations array, van sample_event binnen allSampleDict, toe 
        for i in range(numberSteps):
            allSampleDict[instrumentnameChoiceAnswer]['noteDurations'].append(float(input()))
            i += 1
noteDurations_input()

def noteDurations_to_noteDurations16th(_noteDurations):
    # zet voor elke step de noteDurations input, van het gekozen sample_event, om in een 16de
    i = 0
    for i in range(numberSteps):
        allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'].append(float(_noteDurations[i]) / 0.25)
        i += 1
noteDurations_to_noteDurations16th(allSampleDict[instrumentnameChoiceAnswer]['noteDurations'])

def noteDurations16th_to_timeStamps(_noteDurations16th):
    # zet noteDuration16th om naar tijdswaardes van 16de noten in milisecondes, daarna tel deze waardes bij elkaar op voor timeStamps
    sum = 0
    # Voor het elke step, zet de 16de noot om in milisecondes. Tel deze milisecondes bij elkaar op
    for i in range(numberSteps):
        allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'].append(float(_noteDurations16th[i] * noteDuration16th))
        sum = sum + allSampleDict[instrumentnameChoiceAnswer]['noteDurations16thMilis'][i]
        allSampleDict[instrumentnameChoiceAnswer]['timeStamps'].append(sum)
        print(sum)
noteDurations16th_to_timeStamps(allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'])
print(allSampleDict[instrumentnameChoiceAnswer])

# def handle_sample_event(event):
#     print(event['instrumentname'])
#     event['filename'].play()
# handle_sample_event(kick_event)
# time.sleep(1)
# handle_sample_event(snare_event)
# time.sleep(1)