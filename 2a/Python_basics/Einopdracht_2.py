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
    #print(sequence)

    #Whole note = 60/bpm, a sixteenth note = 1/4 of a whole note
    sixteenthnote = (60 / bpm) / 4 
    #print(sixteenthnote)
    sum = 0
    timestamps = []
    for i in range(len(sequence)):
        #formula appends sum to timestamps array
        #first it takes an element from sequence[] ten transforms this elemnt into 16th then into a 16th timestamp 
        sum = sum + ((sequence[i] / 0.25) * sixteenthnote)
        timestamps.append(sum)
    print(timestamps)
    return timestamps

def create_event(filename, instrumentname, timestamps, threadID):
    return {
    'filename': filename,
    'instrumentname': instrumentname,
    'timestamps':timestamps,
    'threadID': threadID,
    'playcheck' : True 
    }

events = []
events.append(create_event(kick, 'kick', rythm_generation('kick'), 0))
events.append(create_event(snare, 'snare', rythm_generation('snare'), 1))
events.append(create_event(hihat, 'hihat', rythm_generation('hihat'), 2))
# events = [{'filename': kick, 'timestamps': [1.5, 2, 2.5, 3]},
#             {'filename': snare, 'timestamps': [0.5, 1.5, 2.5, 3.5, 4]},
#             {'filename': hihat, 'timestamps': [1, 1.5, 2, 2.5]}
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
    def __init__(self, events, timestamps, names):
        threading.Thread.__init__(self)
        self.events = events
        self.timestamps = timestamps
        self.names = names
        self.i = 0
        self.playCheck = True

    def run (self):
        #This is a build in function to run the thread
        #Get the current time
        timeZero = time.time()
        #While playCheck is True
        #check if it is time to play a sample at the index of i
        while self.playCheck: 
            timeCurrent = time.time() - timeZero
            if timeCurrent >= float(self.timestamps[self.i]):
                self.names[self.i].play()
                self.i += 1
            time.sleep(0.001)
        

    # def restart(self):
    #     self.i = 0
    #     self.is_playing = True

playAudio = AudioPlayThread(events, event_timestamps_sorted, event_files_sorted)
playAudio.start()

def create_midi_file():
    #example BY CISKA (https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2a/theorie/6_writeMIDI)
    # create your MIDI object
    mf = MIDIFile(1)     # only 1 track
    track = 0   # the only track
    time = 0    # start at the beginning
    mf.addTrackName(track, time, "Drumloop Track")
    mf.addTempo(track, time, bpm)


    # add some notes
    channel = 0
    volume = 60
    print("Volume:",volume)

    pitch = 60           # C4 (middle C)
    time = 0             # start on beat 0
    duration = 1         # 1 beat long
    mf.addNote(track, channel, pitch, time, duration, volume)

    volume += 30
    print("Volume:",volume)

    pitch = 64           # E4
    time = 2             # start on beat 2
    duration = 1         # 1 beat long
    mf.addNote(track, channel, pitch, time, duration, volume)

    volume += 30
    print("Volume:",volume)

    pitch = 67           # G4
    time = 4             # start on beat 4
    duration = 1         # 1 beat long
    mf.addNote(track, channel, pitch, time, duration, volume)

    # write it to disk
    with open("drumloop.mid",'wb') as outf:
        mf.writeFile(outf)

