import cv2
from time import *
import pyaudio

import wave
from PIL import ImageGrab
from datetime import *
import numpy as np
import threading
from moviepy.editor import *

class ScreenRecord(object):


    def __init__(self):
        self.recording = True


    def record_audio(self):
        recordaudio = pyaudio.PyAudio()

        stream = recordaudio.open(format=pyaudio.paInt16,channels=2,rate=48000,input=True,frames_per_buffer=124)


        wavefile = wave.open(self.audio_filename,'wb')
        wavefile.setnchannels(2)
        wavefile.setsampwidth(recordaudio.get_sample_size(pyaudio.paInt16))
        wavefile.setframerate(48000)
        while self.recording:
            data = stream.read(124)
            wavefile.writeframes(data)

        wavefile.close()
        stream.stop_stream()
        stream.close()
        recordaudio.terminate()


    def record_video(self):
        screen = ImageGrab.grab()
        video = cv2.VideoWriter(self.record_video_filename,cv2.VideoWriter_fourcc(*'XVID'), 20, screen.size)

        while self.recording:
            screen = ImageGrab.grab()
            screen = cv2.cvtColor(np.array(screen), cv2.COLOR_RGB2BGR)
            video.write(screen)
        video.release()


    def run(self):
        print('三秒后开始录制视频，输入‘quit’结束')
        sleep(3)
        self.now = str(datetime.now())[:19].replace(':','_').replace('-','_').replace(' ','-')
        self.audio_filename = "{}.wav".format(self.now)
        self.record_video_filename = "{}_video.avi".format(self.now)
        self.video_filename = "{}.mp4".format(self.now)
        t1 = threading.Thread(target=self.record_audio)
        t2 = threading.Thread(target=self.record_video)
        for t in [t1, t2]:
            t.start()
        while True:
            if input() == 'quit':
                break
        self.recording = False
        for t in [t1, t2]:
            t.join()

        audio = AudioFileClip(self.audio_filename)
        video = VideoFileClip(self.record_video_filename)
        totalvideo = video.set_audio(audio)
        totalvideo.write_videofile("result.mp4", codec="libx264", fps=25)


if __name__ == "__main__":
    screenrecord = ScreenRecord()
    screenrecord.run()
