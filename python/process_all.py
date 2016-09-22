#!/usr/bin/env python3

import cv2
import glob
import os.path


def process_hsv(dir):
    hsv_target_color = (178 // 2, 1.0 * 255, .61 * 255)
    hsv_target_lower = (hsv_target_color[0] - 5, 100, 100)
    hsv_target_upper = (hsv_target_color[0] + 5, 255, 255)

    for img in glob.glob(dir + "*.jpg"):
        print(img)
        bgr_image = cv2.imread(img)
        hsv_image = cv2.cvtColor(bgr_image, cv2.COLOR_BGR2HSV)
        hsv_blurred_image = cv2.GaussianBlur(hsv_image, (5, 5), 0)
        hsv_inrange_image = cv2.inRange(hsv_blurred_image, hsv_target_lower,
                                        hsv_target_upper)
        _, contours, _ = cv2.findContours(hsv_inrange_image.copy(),
                                          cv2.RETR_LIST,
                                          cv2.CHAIN_APPROX_SIMPLE)

        target_contour = sorted(contours, key=cv2.contourArea, reverse=True)[0]

        bgr_image_copy = bgr_image.copy()
        cv2.drawContours(bgr_image_copy, [target_contour], -1, (0, 0, 255), 2)
        cv2.imwrite("/tmp/process_hsv/" + os.path.basename(img),
                    bgr_image_copy)

if __name__ == '__main__':
    process_hsv("../2016_RealFullField/")
