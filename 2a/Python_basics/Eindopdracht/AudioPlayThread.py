import time #time functions
import threading # multithreading

class AudioPlayThread(threading.Thread):
    #This class makes a thread which is used to play audio
    #we get the nessesary arguments from the allSamplesDict
    def __init__(self, timestamps, files, names):
        threading.Thread.__init__(self)
        self.timestamps = timestamps
        self.files = files
        self.names = names
        self.files_wait_done = 0
        self.i = 0
        self.playCheck = False
        self.exit = False
        self.wait = True
        #Get the current time
        self.timeZero = time.time()

    def run (self):
        # This is a build in function to run the thread
        # While playCheck is True
        # check if it is time to play a sample at the index of i
        while True: 
            if self.playCheck:
                timeCurrent = time.time() - self.timeZero
                if self.i < len(self.timestamps):
                    if timeCurrent >= float(self.timestamps[self.i]):
                        # Play the sample from the names array at the index of i
                        self.files[self.i].play()
                        self.i += 1
                elif self.exit == False:
                    # If the last element in the timestamps array is reached
                    # Make a new play object is made from the last element in the names array
                    # so we can execute the wait_done() function
                    # Then we reset the index of i and timeZero
                    # so the loop can start over again
                    if self.wait:
                        self.files_wait_done = self.files[- 1].play()
                        self.files_wait_done.wait_done()
                        self.i = 0
                        self.files_wait_done = 0
                        self.timeZero = time.time()
                    else:
                        self.i = 0
                        self.timeZero = time.time()
                if self.exit:
                    # On exit wait untill the last sample is finished playing
                    self.files_wait_done = self.files[self.i].play()
                    self.files_wait_done.wait_done()
                    break
            if self.exit:
                break
            else:
                time.sleep(0.001)