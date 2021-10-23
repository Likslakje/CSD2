import simpleaudio as sa #audio functions
import inquirer #user input functions
import random #random functions
import time #time functions
import threading #multithreading

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

# def create_event(filename, instrumentname, timestamps, threadID):
#     return {
#     'filename': filename,
#     'instrumentname': instrumentname,
#     'timestamps':timestamps,
#     'threadID': threadID,
#     'playcheck' : True 
#     }

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

# def rythm_generation(instrumentname):
#     while True:
#         try:
#             numerator, denominator = input('set numerator and denominator for ' + instrumentname + ' ').split()
#             if numerator.isnumeric() and denominator.isnumeric():
#                 numerator = int(numerator)
#                 denominator = int(denominator)
#                 break
#             else:
#                 raise ValueError
#         except ValueError:
#             print('Please enter valid input, integers only \nMIN is 1 \nMAX is 8')
#             continue
#     # simple euclidean example, without rotation
#     num_pulses = numerator
#     num_notes = denominator
#     # calculate duration of a note, expressed in 16th
#     dur = int(num_pulses / num_notes)
#     # fill list num_notes times with the duration value
#     sequence = [dur] * num_notes
#     # calculate the rest value and distribute these amongst the stored durations
#     rest_value = num_pulses - (num_notes * dur)
#     for i in range(rest_value):
#         sequence[i] += 1
#     #print(sequence)

#     #Whole note = 60/bpm, a sixteenth note = 1/4 of a whole note
#     sixteenthnote = (60 / bpm) / 4 
#     #print(sixteenthnote)
#     sum = 0
#     timestamps = []
#     for i in range(len(sequence)):
#         #formula appends sum to timestamps array
#         #first it takes an element from sequence[] ten transforms this elemnt into 16th then into a 16th timestamp 
#         sum = sum + ((sequence[i] / 0.25) * sixteenthnote)
#         timestamps.append(sum)
#     print(timestamps)
#     return timestamps


# events = []
# events.append(create_event(kick, 'kick', rythm_generation('kick'), 0))
# events.append(create_event(snare, 'snare', rythm_generation('snare'), 1))
# events.append(create_event(hihat, 'hihat', rythm_generation('hihat'), 2))
events = [{'instrumentname': 'kick', 'timestamps': [1.5, 2, 2.5, 3]},
            {'instrumentname': 'snare', 'timestamps': [0.5, 1.5, 2.5, 3.5, 4]},
            {'instrumentname': 'hihat', 'timestamps': [1, 1.5, 2, 2.5]}
        ]

class AudioPlayThread(threading.Thread):
    #This class makes a thread which is used to play audio
    #we get the nessesary arguments from the allSamplesDict
    def __init__(self, events):
        threading.Thread.__init__(self)
        self.events = events
        self.i = 0

    def run (self):
        #This is a build in function to run the thread
         #Get the current time
        timeZero = time.time()
        #While playCheck for the choosen sample_event is True
        #check if it is time to play an event and check if the choosen sample_event should loop
        while True: 
            timeCurrent = time.time() - timeZero
            time.sleep(0.001)



    def sort_event():
        #this function sorts every intrument based on its timestamp
        #make dictionaries of the timestamp arrays, this way they will have a key(instrumentname) per timestamp
        events_unsorted = {}
        for i in range(len(events)):
            for j in range(len(events[i]['timestamps'])):
                #print(events[i]['instrumentname'], events[i]['timestamps'][j])
                new_key = events[i]['instrumentname'] + str(j)
                events_unsorted[new_key] = events[i]['timestamps'][j]
        events_sorted = dict(sorted(events_unsorted.items(), key=lambda item: item[1]))
        return events_sorted
    # def restart(self):
    #     self.i = 0
    #     self.is_playing = True

# playAudio = AudioPlayThread(events)
# playAudio.start()