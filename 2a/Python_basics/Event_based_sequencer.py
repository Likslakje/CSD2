import simpleaudio as sa
import time

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")

kick_event = {
    'filename': Kick
    'instrumentname': 'kick'
    'timestamp': 1000
    'duration': 100
    'velocity': 127
}

snare_event = {
    'filename': Snare
    'instrumentname': 'snare'
    'timestamp': 2000
    'duration': 200
    'velocity': 127
}

hihat_event = {
    'filename': Hihat
    'instrumentname': 'hihat'
    'timestamp': 3000
    'duration': 300
    'velocity': 127
}