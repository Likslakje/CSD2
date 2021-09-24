import simpleaudio as sa
import time

print ("wats die bpm a zebi")
#bpmInput = input()
#bpm = int(bpmInput)
#bpm = 120
noteDurations = [0.25, 0.5, 0.25, 1, 0.5, 0.25, 0.25, 0.5] # wordt _noteDurations in de functie durationsToTimestamps16th
timeStamps16th = [] #een inital 0 voor de eerste step in de sequence
timeStamps = []

def durationsToTimestamps16th(_noteDurations): #nieuwe naam want we willen een array passen (noteDuration)
    sum = 0
    for i in range (len(_noteDurations)): #forloop met aantal elementen in de lijst noteDurations
        timeStamps16th.append(int(sum / 0.25)) #voeg aan timeStamps16th steeds de optelleing van de lijst noteDurations toe. Deel die door een 16de (0.25) en  maar er een int van, dit is de step
        sum = sum + noteDurations[i]
        #return _noteDurations
durationsToTimestamps16th(noteDurations) #pass de lijst met noteDurations naar de functie durationsToTimestamps16th

def sixteenthTimeStampsToSeconds (_timeStamps16th, bpmInput): #_timeStamps16th (andere naam) want je wil de lijst timeStamps16th passen naar de functie
    bpm = int(bpmInput)
    quaternoteDuration = 60 / bpm
    sixteenthnoetDuration = quaternoteDuration / 4
    for i in _timeStamps16th:
        timeStamps.append(i * sixteenthnoetDuration)
sixteenthTimeStampsToSeconds(timeStamps16th, input()) #pass de lijst met timeStamps16th naar de functie sixteenthTimeStampsToSeconds
print(timeStamps)