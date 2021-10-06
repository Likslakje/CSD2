import simpleaudio as sa
import time

def choice(): #maak een functie voor de y/n vraag voor bpm
    bpmChoice = input("Default BPM is set to 120, would you like to change the BPM (y/n): ")
    if bpmChoice == "n" :
        bpm = 120
        return bpm
    elif bpmChoice == "y" :
        bpm = int(input("Enter a new BPM: " ))
        return bpm
    else :
        print("Please enter valid input, 'y' or 'n' only")
        choice() #als input niet matched dan voer de functie choice opnieuw uit
bpm = choice() #bpm is gelijk aan het resultaat van de functie choice

print("How many steps should the sequence have?")
numberNotes = int(input())

print("choose " + str(numberNotes) + " note durations")
noteDurations = []
for i in range(numberNotes):
    noteDurations.append(float(input()))#voeg telkens de ingeven waarde toe aan de array

timeStamps16th = [] #een inital 0 voor de eerste step in de sequence
def durationsToTimestamps16th(_noteDurations): #nieuwe naam want we willen een array passen (noteDuration)
    sum = 0
    for i in range (len(_noteDurations)): #forloop met aantal elementen in de lijst noteDurations
        timeStamps16th.append(int(sum / 0.25)) #voeg aan timeStamps16th steeds de optelleing van de lijst noteDurations toe. Deel die door een 16de (0.25) en  maar er een int van, dit is de step
        sum = sum + noteDurations[i]
durationsToTimestamps16th(noteDurations) #pass de lijst met noteDurations naar de functie durationsToTimestamps16th
print(timeStamps16th)

timeStamps = []
def sixteenthTimeStampsToSeconds (_timeStamps16th, _bpm): #_timeStamps16th (andere naam) want je wil de lijst timeStamps16th passen naar de functie
    quaternoteDuration = 60 / _bpm
    sixteenthnoetDuration = quaternoteDuration / 4
    for i in _timeStamps16th:
        timeStamps.append(i * sixteenthnoetDuration)
sixteenthTimeStampsToSeconds(timeStamps16th, bpm) #pass de lijst met timeStamps16th naar de functie sixteenthTimeStampsToSeconds
print(timeStamps)
# timeStamps = [0.0, 0.25, 0.75, 0.875, 1.125, 1.625, 1.75, 1.875]

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
timeZero = time.time()
i = 0
while True:
    timeCurrent = time.time() - timeZero
    if(timeCurrent >= float(timeStamps[i])):
        kick.play()
        i += 1
        print (i)
        if(i == len(timeStamps)):
         break
    time.sleep(000.1)