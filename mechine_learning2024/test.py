import threading
import cv2
 
 
class OpcvCapture(threading.Thread):
    def __init__(self, win_name, cam_name):
        super().__init__()
        self.cam_name = cam_name
        self.win_name = win_name
 
    def run(self):
        capture = cv2.VideoCapture(self.cam_name)
        while (True):
            # 获取一帧
            ret, frame = capture.read()
            cv2.imshow(self.win_name, frame)
            cv2.waitKey(1)
 
 
if __name__ == "__main__":
    camera1 = OpcvCapture("camera1", 1)
    camera1.start()
    run_code = 0