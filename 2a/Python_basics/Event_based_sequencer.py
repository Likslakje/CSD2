import simpleaudio as sa # audio functionaliteiten
import inquirer # user input functionaliteiten
import time # time

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
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'numberSteps': 0,
    'noteDurations': [],
    'noteDurations16th': [],
    'noteDurations16thMilis': [],
    'timeStamps': [],
}

allSampleDict = {'kick' : kick_event, 'snare' : snare_event, 'hihat' : hihat_event} # dit is een nested dictionary

bpm = 120

def bpm_choice(): 
    #functie voor de y/n vraag voor bpm
    print("Default BPM is set to 120, would you like to change the BPM (y/n): ")
    bpmChoice = input()
    if bpmChoice == "n" :
        bpm = 120
        return bpm
    elif bpmChoice == "y" :
        bpm = int(input("Enter a new BPM: " ))
        return bpm
    else :
        print("Please enter valid input, 'y' or 'n' only")
        bpm_choice() #als input niet matched dan voer de functie choice opnieuw uit
bpm_choice()

def duration_16th_note(_bpm):
    # de lengte van 1 16de noot wordt uitgereknd aan de hand van het bpm
    return((60 / _bpm) / 4)# hele noot = 60/bpm, 16de = 1/4 van een hele noot
noteDuration16th = duration_16th_note(bpm)

def instrumentname_choice():
    # multiple choice voor de instrumentname
    instrumentChoiceQuestion = [
        inquirer.List('instrumentname', 
                    message = 'Which sample would you like to edit?',
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


def sample_player(waveSample):
    playSample = waveSample.play()
    print("Default loop is on: \n Type l to loop \n Type ^l to unloop")
    timeZero = time.time()
    i = 0
    while True:
        timeCurrent = time.time() - timeZero
        if(timeCurrent >= float(allSampleDict[instrumentnameChoiceAnswer]['timeStamps'][i])):
            waveSample.play()
            i += 1
        if i == allSampleDict[instrumentnameChoiceAnswer]['numberSteps']:
            i = 0

    #time.sleep(000.1)

def do_everything():
    # voer alle functies in relatie tot het afspelen van de samples uit
    instrumentname_choice()
    numberSteps_noteDurations_input()
    noteDurations_to_noteDurations16th(allSampleDict[instrumentnameChoiceAnswer]['noteDurations'])
    noteDurations16th_to_timeStamps(allSampleDict[instrumentnameChoiceAnswer]['noteDurations16th'])
    sample_player(allSampleDict[instrumentnameChoiceAnswer]['filename'])

def handle_input(_input):
    # afhangkelijk van de het ingeven commando, voer bepaalde functies uit
    if _input == 'sample.edit':
        do_everything()
    elif _input == 'bpm.edit':
        print("we gaan die bpm editten a niffau")
        bpm_choice()
    else:
        print("Please use a valid command")
        handle_input()
handle_input(str(input("Type 'sample.edit' to start programming a drumline\nType 'bpm.edit' to change the bpm\n")))
