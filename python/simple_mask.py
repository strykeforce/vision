import cv2
import sys
import os


def simple_threshold(path, thresh):
    # read in the image
    img = cv2.imread(path)

    # display the image and wait for key press
    cv2.imshow('original', img)
    cv2.waitKey(0)

    # http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # http://docs.opencv.org/2.4/modules/imgproc/doc/filtering.html#gaussianblur
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    # http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#threshold
    (T, thresholded) = cv2.threshold(blurred, thresh, 255, cv2.THRESH_BINARY)

    # display the image and wait for key press
    cv2.imshow('thresholded image', thresholded)
    cv2.waitKey(0)

# usage: python ex_002.py path/to/image.jpg threshold
# example: python ex_002.py ~/Projects/sf/notebooks/RealFullField/245.jpg 99
if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("usage: python ex_002.py path/to/image.jpg threshold")
        sys.exit()

    imgPath = sys.argv[1]
    if not os.path.isfile(imgPath):
        print("Image file not found.")
        sys.exit()

    threshold = sys.argv[2]
    if not threshold.isdigit():
        print("Enter a digit for threshold")
        sys.exit()

    simple_threshold(imgPath, float(threshold))
