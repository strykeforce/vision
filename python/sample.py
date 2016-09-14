#!/usr/bin/env python3

import cv2
import time

camera = cv2.VideoCapture(1)
camera.set(cv2.CAP_PROP_BRIGHTNESS, 0.0)
time.sleep(1.0)

for i in range(5):
    _, frame = camera.read()
    cv2.imshow("Captured", frame)
    cv2.waitKey(0)
    cv2.imwrite("sample_{}.jpg".format(i), frame)
    time.sleep(5)

camera.release()
cv2.destroyAllWindows()
