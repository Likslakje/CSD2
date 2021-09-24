import simpleaudio as sa
import time

print ("wats die bpm a zebi")
bpmInput = input()
bpm = int(bpmInput)

print("How many steps shoukd the sequence have?")
numberNotesInput = input()
numberNotes = int(numberNotesInput)

print("choose " + numberNotesInput + " note durations")
noteDurations = []
for i in range(numberNotes):
    noteDurationsInput = input()
    noteDurations.append(float(noteDurationsInput))#voeg telkens de ingeven waarde toe aan de array
print(noteDurations)

timeStamps16th = [] #een inital 0 voor de eerste step in de sequence
def durationsToTimestamps16th(_noteDurations): #nieuwe naam want we willen een array passen (noteDuration)
    sum = 0
    for i in range (len(_noteDurations)): #forloop met aantal elementen in de lijst noteDurations
        timeStamps16th.append(int(sum / 0.25)) #voeg aan timeStamps16th steeds de optelleing van de lijst noteDurations toe. Deel die door een 16de (0.25) en  maar er een int van, dit is de step
        sum = sum + noteDurations[i]
durationsToTimestamps16th(noteDurations) #pass de lijst met noteDurations naar de functie durationsToTimestamps16th

timeStamps = []
def sixteenthTimeStampsToSeconds (_timeStamps16th, _bpm): #_timeStamps16th (andere naam) want je wil de lijst timeStamps16th passen naar de functie
    quaternoteDuration = 60 / _bpm
    sixteenthnoetDuration = quaternoteDuration / 4
    for i in _timeStamps16th:
        timeStamps.append(i * sixteenthnoetDuration)
sixteenthTimeStampsToSeconds(timeStamps16th, bpm) #pass de lijst met timeStamps16th naar de functie sixteenthTimeStampsToSeconds
print(timeStamps)
