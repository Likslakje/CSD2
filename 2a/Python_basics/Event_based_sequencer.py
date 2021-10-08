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

noteDuration16th = []
def make_note_durations_16th(_noteDurations):
    i = 0
    for i in range(len(noteDurations)):
        noteDuration16th.append(float(_noteDurations[i]) / 0.25)
        i += 1
make_note_durations_16th(noteDurations)

print(noteDuration16th)

# def handle_sample_event(event):
#     print(event['instrumentname'])
#     event['filename'].play()
# handle_sample_event(kick_event)
# time.sleep(1)
# handle_sample_event(snare_event)
# time.sleep(1)