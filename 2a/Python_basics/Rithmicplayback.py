

print("beetje later")
print("What BPM should the sequence be?")
bpmInput = input()
bpm = int(bpmInput)
bpmSeconds = 60/bpm #kwartnoot in 4/4, 1 beat

print("How many steps should the sequence have?")
steps = input()
numberSteps = int(steps) #maak een interger van de input

print("Insert rythmic patern * use point for floats, not comma *")
durationStepsArray = [] #maak een lege array om het ritme in op te slaan
for x in range(numberSteps): #een forloop zolang als het aantal steps
    durationStepsInput = input() #vraag nu voor elke element in de lijst (zolang als numberSteps) een input (duration)
    durationSteps = float(durationStepsInput) #omzetten naar float want komma getallen
    durationStepsArray.append(durationSteps)
    x =+ 1

import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("../samples/Kick.wav")
for x in range(numberSteps):
    play_obj = wave_obj.play()
    play_obj.wait_done()
    import time
    time.sleep(bpmSeconds * x)
    x =+ 1