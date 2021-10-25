import AudioPlayThread as apt
import simpleaudio as sa # audio functions
import inquirer # user input functions
import random # random functions
import time #t ime functions
import numpy as np #to sort arrays
from midiutil import MIDIFile # to write midi file to disk

kick = sa.WaveObject.from_wave_file("samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("samples/Hihat.wav")

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
                if bpm_number.isnumeric() and int(bpm_number) >= 10 and int(bpm_number) <= 500:
                    bpm = int(bpm_number)
                    break
                else:
                    raise BpmNumberError
            except BpmNumberError:
                print("Please enter a valid input, intergers between 10 and 500 only")
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

    #Whole note = 60/bpm, a sixteenth note = 1/16 of a whole note
    sixteenthnote = (60 / bpm) / 16 
    sum = 0
    timestamps = []
    for i in range(len(sequence)):
        #formula appends sum to timestamps array
        #first it takes an element from sequence[] ten transforms this elemnt into 16th then into a 16th timestamp 
        timestamps.append(sum)
        sum = sum + ((sequence[i] / 0.25) * sixteenthnote)
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

def event_dict_arr():
    events = []
    events.append(create_event(kick, 'kick', 36, rythm_generation('kick'), 0))
    events.append(create_event(snare, 'snare', 38, rythm_generation('snare'), 1))
    events.append(create_event(hihat, 'hihat', 44, rythm_generation('hihat'), 2))
    return events
events = event_dict_arr()

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
event_timestamps_sorted, event_files_sorted, event_names_sorted = selection_sort(
            event_timestamps_unsorted, event_files_unsorted, event_names_unsorted)

def instrumentname_choice():
    #User input multiple choice
    instrumentname_choice_question = [
        inquirer.List('instrumentname', 
                    message = 'Choose sample ',
                    choices = ['kick', 'snare', 'hihat'],
                    carousel = True)] #Makes scroll infinite
    instrumentname_choice_answer = inquirer.prompt(instrumentname_choice_question)
    return instrumentname_choice_answer['instrumentname']

def edit_rythm_choice():
    #User input multiple choice
    edit_rythm_choice_question = [
        inquirer.List('algorythm', 
                    message = 'Choose algorythm ',
                    choices = ['rotate', 'chaos', 'back to normal'],
                    carousel = True)] #Makes scroll infinite
    edit_rythm_choice_answer = inquirer.prompt(edit_rythm_choice_question)
    return edit_rythm_choice_answer['algorythm']

def edit_rythm():
        algorythm = edit_rythm_choice()
        if algorythm == 'rotate':
            while True:
                try:
                    num_rotations = input("Enter number of rotations: ")
                    # Convert np.array to list with .tolist()
                    event_files_rotated = event_files_sorted.tolist()
                    event_names_rotated = event_names_sorted.tolist()
                    if num_rotations.isnumeric():
                        num_rotations = int(num_rotations)
                        if(num_rotations < len(event_files_rotated)):
                            for i in range(num_rotations):
                                # for the number of rotations, pop the first element and append it
                                event_files_first = event_files_rotated.pop(0)
                                event_files_rotated.append(event_files_first)
                                event_names_first = event_names_rotated.pop(0)
                                event_names_rotated.append(event_names_first)
                            break
                        else:
                            raise ValueError
                    else:
                        raise ValueError
                except ValueError:
                    print("Please enter a valid input, intergers between 0 and " + str(len(event_files_rotated) - 1))
                    continue
            return event_timestamps_sorted, event_files_rotated, event_names_rotated
        elif algorythm == 'chaos':
            # Chaos randomly shuffles the index of the event_files_sorted,
            # This way the timestamps stay in place but a different sample is played at the index
            # https://pynative.com/python-random-shuffle/#h-shuffle-two-lists-at-once-with-same-order
            # To Shuffle two List at once with the same order
            mapIndexPosition = list(zip(event_files_unsorted, event_names_unsorted))
            random.shuffle(mapIndexPosition)
            # make list separate
            event_files_shuffled, event_names_shuffled = zip( * mapIndexPosition)
            return event_timestamps_sorted, event_files_shuffled, event_names_shuffled
        elif algorythm == 'back to normal':
            return event_timestamps_sorted, event_files_sorted, event_names_sorted

playAudio = apt.AudioPlayThread(event_timestamps_sorted, event_files_sorted, event_names_sorted)
playAudio.start()

def create_midi_file(ts, files, names):
    # after example BY CISKA (https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2a/theorie/6_writeMIDI)
    # create MIDI object
    mf = MIDIFile(1)     # only 1 track
    track = 0   # the only track
    channel = 0 # midi channel 1
    time_beginning = 0    # start at the beginning
    velocity = 127
    # midi numbers for each instrument
    hihat_midi_number = 44
    kick_midi_number = 36
    snare_midi_number = 38
    midi_number = [kick_midi_number, snare_midi_number, hihat_midi_number]
    # Some hardcoded variables for the making of the MIDI file
    mf.addTrackName(track, time_beginning, "Drumloop Track")
    mf.addTempo(track, time_beginning, bpm)
    # Sort the names and timestamp list
    # In this case names has the leading index
    names_sorted, ts_sorted = zip( * sorted(zip(names, ts)))
    # timestamps for each instrument
    kick_ts = []
    snare_ts = []
    hihat_ts = []
    intrument_ts = [hihat_ts, kick_ts, snare_ts]
    # Split the ts_sorted list into new list for each intrument
    for i in range(len(intrument_ts)):
        for j in range(len(ts_sorted)):
            if names_sorted[j] == events[i]['instrumentname']:
                intrument_ts[i].append(ts_sorted[j])
    # Append the sorted timestamp list for each intrument to the MIDI file
    for k in range(len(intrument_ts)):
        for l in range(len(intrument_ts[k])):
            if l < len(intrument_ts[k]) - 1:
                # the time stamp for the specific intrument is put directly into addNote
                time = intrument_ts[k][l] 
                # the duartion of a note equals the next timestamp minus the current timestamp
                dur = intrument_ts[k][l + 1] - intrument_ts[k][l] 
                mf.addNote(track, channel, midi_number[k], time, dur, velocity)
    # Finally, write the MIDI file to disk
    with open("drumloop.mid",'wb') as outf:
        mf.writeFile(outf)
    # You're probably wodering why all of the code above splits the array with all the timestamp 
    # eventhough there is an earlier function called split_files_timestamp()
    # This would have worked if the chaos algorithm had not been used
    # Because the chaos algorythm scrambles the intruments NOT the array with all the timestamps

while True:
    #This loop keeps expecting an user input
    user_input = str(input("Type 'help' for options and explanation\nWhat would you like to do? : "))
    if user_input == 'edit':
        playAudio.playCheck = False
        playAudio.i = 0
        playAudio.timestamps, playAudio.files, playAudio.names = edit_rythm()
        #give new list to class 
    elif user_input == 'play':
        # If play: the index of i is 0 so it will start at the beginning of the note sequence
        # Then we set the timeZero so we can check the timestamps later (in the AudioPlayThread class)
        # (Defining both i and timeZero only become relevant after the sequence had been stoped once)
        playAudio.i = 0
        playAudio.timeZero = time.time()
        playAudio.playCheck = True
    elif user_input == 'stop':
        playAudio.playCheck = False
    elif user_input == 'wait':
        # If else toggles between wait = True of False
        if playAudio.wait:
            playAudio.wait = False
        else:
            playAudio.wait = True
    elif user_input == 'reset':
        # First make sure no audio is being played
        # Then empty the events array 
        # this is done because the append finction is used, to add to this array
        # if we would not empty it first, the function would keep appending to it
        # and it would become too long.
        # Then re-execute the initial setup functions
        # At last they're givven back to the AudioPlayThread
        playAudio.i = 0
        playAudio.timeZero = time.time()
        playAudio.playCheck = False
        events.clear()
        bpm = bpm_choice()
        events = event_dict_arr()
        event_files_unsorted, event_timestamps_unsorted, event_names_unsorted = np.array(split_files_timestamp())
        event_timestamps_sorted, event_files_sorted, event_names_sorted = selection_sort(
            event_timestamps_unsorted, event_files_unsorted, event_names_unsorted)
    elif user_input == 'save':
        # Get the current info for the events before creating a midi file
        # this is nessecary because whenever the edit function is used, the values for these events change
        event_timestamps_midi = playAudio.timestamps
        event_files_midi = playAudio.files
        event_names_midi = playAudio.names
        create_midi_file(event_timestamps_midi, event_files_midi, event_names_midi)
    elif user_input == 'exit':
        playAudio.exit = True
        playAudio.join()
        break
    elif user_input == 'help':
        print("Type :\t'edit' to edit the rythm of a sample")
        print("\t'play' to start playing a sample")
        print("\t'stop' to stop playing a sample")
        print("\t'wait' toggles between waitng for the last sample to end")
        print("\t'reset' let`s you reset the initial values")
        print("\t'save' to write the MIDI file to disk")
        print("\t'exit' will stop the program")
    else:
        print("Please use a valid input")
