import simpleaudio as sa
import time

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

kick_event = {
    'filename': kick,
    'instrumentname': 'kick',
    'timestamp': 1000,
    'duration': 100,
    'velocity': 127,
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'timestamp': 2000,
    'duration': 200,
    'velocity': 127,
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'timestamp': 3000,
    'duration': 300,
    'velocity': 127,
}

bpm = 120
noteDurations = [0.5, 1, 2, 1, 2]

def duration_16th_note(_bpm):
    return((60 / _bpm) / 4)# hele noot = 60/bpm, 16de = 1/4 van een hele noot
noteDuration16th = duration_16th_note(bpm)

noteDurationArray16th = []
def noteDurations_to_noteDurations16th(_noteDurations):
    # zet voor het aantal elementen in noteDurations elk element om in een 16de
    i = 0
    for i in range(len(noteDurations)):
        noteDurationArray16th.append(float(_noteDurations[i]) / 0.25)
        i += 1
noteDurations_to_noteDurations16th(noteDurations)

timeStamps = []
def noteDurations16th_to_timeStamps(_noteDurationArray16th):
    #sum = 0
    for i in range(len(noteDurations)):
        timeStamps.append(float(_noteDurationArray16th[i] * noteDuration16th))
noteDurations16th_to_timeStamps(noteDurationArray16th)
print(timeStamps)

# def handle_sample_event(event):
#     print(event['instrumentname'])
#     event['filename'].play()
# handle_sample_event(kick_event)
# time.sleep(1)
# handle_sample_event(snare_event)
# time.sleep(1)