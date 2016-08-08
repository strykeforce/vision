import cv2
import numpy as np
import os.path
import sys

imgPath = 'images/python.jpg'

if not os.path.isfile(imgPath):
    print("Run this file from the examples/python directory.")
    sys.exit()

# Read Image
img = cv2.imread(imgPath)

# Display the image in a window
cv2.imshow('image', img)

# Press any key to continue
cv2.waitKey(0)

# Applying Grayscale filter to image
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Display the image in a window
cv2.imshow('grayscale python', gray)

# Press any key to continue
cv2.waitKey(0)

# close windows
cv2.destroyAllWindows()

# Saving filtered image to new file
cv2.imwrite('gray_python.jpg', gray)
