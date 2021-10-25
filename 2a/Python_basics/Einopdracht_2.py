import simpleaudio as sa #audio functions
import inquirer #user input functions
import random #random functions
import time #time functions
import threading #multithreading
import numpy as np #to sort arrays
from midiutil import MIDIFile #to write midi file to disk

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

def bpm_choice(): 
    #this function let's you choose a BPM, the default is set to 120
    #Class is used for a custom try -> exceptions
    class BpmQuestionError(Exception):
        pass

    class BpmNumberError(Exception):
        pass
    
    def bpm_question_yes():
        #This function is used if the bpmQuestion equals yes because we can't put a Try While loop within a Try While loop
        while True:
            try:
                bpm_number = input("Enter a new BPM: " )
                if bpm_number.isnumeric() and int(bpm_number) >= 10 and int(bpm_number) <= 400:
                    bpm = int(bpm_number)
                    break
                else:
                    raise BpmNumberError
            except BpmNumberError:
                print("Please enter a valid input, intergers between 10 and 400 only")
        return bpm
        
    while True:
            try:
                bpm_question = input("Default BPM is set to 120, would you like to change the BPM (y/n): ")
                if bpm_question == 'n':
                    bpm = 120
                    break
                elif bpm_question == 'y':
                    bpm = bpm_question_yes()
                    break
                else:
                    raise BpmQuestionError
            except BpmQuestionError:
                print("Please enter valid input, 'y' or 'n' only")
    return bpm
bpm = bpm_choice()

def rythm_generation(instrumentname):
    while True:
        try:
            numerator, denominator = input('set numerator ["space"] denominator for ' + instrumentname + ' ').split()
            if numerator.isnumeric() and denominator.isnumeric():
                numerator = int(numerator)
                denominator = int(denominator)
                #if numerator >= 1
                break
            else:
                raise ValueError
        except ValueError:
            print('Please enter valid input, integers only \nMIN : 2 \nMAX : don`t go too crazy please')
            continue
    # simple euclidean example BY CISKA (https://github.com/ciskavriezenga/CSD_21-22/blob/master/csd2a/theorie/6_euclidean_norotation.py)
    num_pulses = numerator
    num_notes = denominator
    # calculate duration of a note, expressed in 16th
    dur = int(num_pulses / num_notes)
    # fill list num_notes times with the duration value
    sequence = [dur] * num_notes
    # calculate the rest value and distribute these amongst the stored durations
    rest_value = num_pulses - (num_notes * dur)
    for i in range(rest_value):
        sequence[i] += 1
    print(sequence)

    #Whole note = 60/bpm, a sixteenth note = 1/4 of a whole note
    bpm = 120
    sixteenthnote = (60 / bpm) / 4 
    #print(sixteenthnote)
    sum = 0
    timestamps = []
    for i in range(len(sequence)):
        #formula appends sum to timestamps array
        #first it takes an element from sequence[] ten transforms this elemnt into 16th then into a 16th timestamp 
        timestamps.append(sum)
        sum = sum + ((sequence[i] / 0.25) * sixteenthnote)
    print(timestamps)
    return timestamps

def create_event(filename, instrumentname, midi_number, timestamps, threadID):
    return {
    'filename': filename,
    'instrumentname': instrumentname,
    'midinumber': midi_number,
    'timestamps':timestamps,
    'threadID': threadID,
    'playcheck' : True 
    }

events = []
events.append(create_event(kick, 'kick', 36, rythm_generation('kick'), 0))
events.append(create_event(snare, 'snare', 38, rythm_generation('snare'), 1))
events.append(create_event(hihat, 'hihat', 44, rythm_generation('hihat'), 2))
bpm = 120
# events = [{'filename': kick, 'instrumentname': 'kick', 'timestamps': [0, 1, 2, 3, 4], 'midinumber': 36 },
#             {'filename': snare, 'instrumentname': 'snare', 'timestamps': [0, 1, 2, 3, 4], 'midinumber': 38},
#             {'filename': hihat, 'instrumentname': 'hihat', 'timestamps': [0, 1, 2, 3, 4], 'midinumber': 44}
#         ]

def sort_event():
    #this function sorts every intrument based on its timestamp
    def split_files_timestamp():
        #make an array with timestamps of every event
        #and an array with files of every event
        event_files = []
        event_names = []
        event_timestamps = []
        for i in range(len(events)):
            for j in range(len(events[i]['timestamps'])):
                event_files.append(events[i]['filename'])
                event_names.append(events[i]['instrumentname'])
                event_timestamps.append(events[i]['timestamps'][j])
        return event_files, event_timestamps, event_names
    event_files_unsorted, event_timestamps_unsorted, event_names_unsorted = np.array(split_files_timestamp())
    
    
    def selection_sort(ts, files, names):
        #https://jakevdp.github.io/PythonDataScienceHandbook/02.08-sorting.html
        #sort the timestamp array from small to big 
        #also sort the file arry with the same index
        for i in range(len(ts)):
            swap = i + np.argmin(ts[i:])
            (ts[i], ts[swap]) = (ts[swap], ts[i])
            (files[i], files[swap]) = (files[swap], files[i])
            (names[i], names[swap]) = (names[swap], names[i])
        return ts, files, names
    event_timestamps_sorted, event_files_sorted, event_names_sorted = selection_sort(event_timestamps_unsorted, event_files_unsorted, event_names_unsorted)
    return event_timestamps_sorted, event_files_sorted, event_names_sorted

    def mute_instrument():
        pass
event_timestamps_sorted, event_files_sorted, event_names_sorted = sort_event()
print(event_timestamps_sorted, event_files_sorted, event_names_sorted)

class AudioPlayThread(threading.Thread):
    #This class makes a thread which is used to play audio
    #we get the nessesary arguments from the allSamplesDict
    def __init__(self, timestamps, names):
        threading.Thread.__init__(self)
        self.timestamps = timestamps
        self.names = names
        self.i = 0
        self.playCheck = True

    def run (self):
        #This is a build in function to run the thread
        #Get the current time
        self.timeZero = time.time()
        #While playCheck is True
        #check if it is time to play a sample at the index of i
        while self.playCheck: 
            timeCurrent = time.time() - self.timeZero
            if timeCurrent >= float(self.timestamps[self.i]):
                self.names[self.i].play()
                self.i += 1
                if self.i == len(self.timestamps):
                    self.i = 0
                    self.timeZero = time.time()
            time.sleep(0.001)
        

    # def restart(self):
    #     self.i = 0
    #     self.is_playing = True

playAudio = AudioPlayThread(event_timestamps_sorted, event_files_sorted)
playAudio.start()

def create_midi_file():
    #example BY CISKA (https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2a/theorie/6_writeMIDI)
    #create MIDI object
    mf = MIDIFile(1)     # only 1 track
    track = 0   # the only track
    channel = 0 # midi channel 1
    time_beginning = 0    # start at the beginning
    velocity = 127
    kick_midi_number = 36 # midi numbers for each instrument
    snare_midi_number = 38
    hihat_midi_number = 44
    midi_number = [kick_midi_number, snare_midi_number, hihat_midi_number]

    mf.addTrackName(track, time_beginning, "Drumloop Track")
    mf.addTempo(track, time_beginning, bpm)

    for i in range(len(events)):
        # this loop adds midi notes to the midi file
        # it loops as many times as there are events
        # within this loop it also scrolls through the timestamps related to the event
        time = 0
        dur = 0
        for j in range(len(events[i]['timestamps'])):
            if j < len(events[i]['timestamps']) - 1:
                print('klein genoeg', j)
                time = events[i]['timestamps'][j] # timestamp is directly added to midi file
                dur = events[i]['timestamps'][j + 1] - events[i]['timestamps'][j] # the duration is calculated and then added
                mf.addNote(track, channel, midi_number[i], time, dur, velocity)
                time = time + dur
                print(time, dur)
    # write it to disk
    with open("drumloop.mid",'wb') as outf:
        mf.writeFile(outf)
create_midi_file()

while True:
    #This loop keeps expecting an user input
    userInput = str(input("Type edit, play, loop, stop or exit : "))
    if userInput == 'edit':
        pass
        # if editAnswer == 'generate new':
        #     instrumentnameChoiceAnswer = instrumentname_choice() #We can choose a sample_event here
        #     if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']:
        #         pass
        # elif editAnswer == 'overwrite':
        #     instrumentnameChoiceAnswer = instrumentname_choice() #We can choose a sample_event here
        #     if instrumentnameChoiceAnswer == allSampleDict[instrumentnameChoiceAnswer]['instrumentname']: #Check if the choosen sample_event exists
        #         numberSteps_noteDurations_input()
    elif userInput == 'play':
        pass
    elif userInput == 'loop':
        pass
    elif userInput == 'stop':
        pass
    elif userInput == 'exit':
        break
    else:
        print("Please use a valid input")
