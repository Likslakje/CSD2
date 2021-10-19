import threading

class audioThread(threading.Thread):
    def __init__(self, playCheck):
        threading.Thread.__init__(self)
        self.playCheck = playCheck

    def playSound(self):
        if self.playCheck == 1:
            print("lets play audio")
        elif self.playCheck == 0:
            print("lets stop audio")
        else:
            print("do nothing")
executeAudioThread = audioThread(0)
executeAudioThread.start()

executeAudioThread.playCheck = 1
executeAudioThread.playSound()