import cv2
import queue
import threading
import time


class VideoCapture:
    def __init__(self, ind):
        self.cap = cv2.VideoCapture(ind)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)
        self.q = queue.Queue()
        t = threading.Thread(target=self._reader)
        t.daemon = True
        t.start()

    def _reader(self):
        while True:
            ret, frame = self.cap.read()
            if not ret:
                break
            if not self.q.empty():
                try:
                    self.q.get_nowait()
                except queue.Empty:
                    pass
            self.q.put(frame)

    def read(self):
        img = self.q.get()
        gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        gray_img = us_crop(gray_img)
        return gray_img


def us_crop(img):
    img = img[107:903, 389:1553]
    img = cv2.resize(img, [400, 400])
    # assert img.size[0] == 400 and img.size[1] == 400, 'image size should be 400 * 400.'
    return img


def shot():
    vid = VideoCapture(0)
    img = vid.read()
    cv2.imwrite(f'target.png', img)


if __name__ == '__main__':
    shot()
