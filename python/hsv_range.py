#!/usr/bin/env python3

import cv2
import numpy as np


def mouse_handler(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        print_hsv_range(x, y)


def print_hsv_range(x, y):
    target = np.uint8([[image[x, y]]])
    hsv = cv2.cvtColor(target, cv2.COLOR_BGR2HSV)
    print("x = {}, y = {}, hsv = {}".format(x, y, hsv))


image = cv2.imread("../2016_RealFullField/20.jpg")
cv2.namedWindow("image")
cv2.setMouseCallback('image', mouse_handler)

while True:
    cv2.imshow("image", image)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
