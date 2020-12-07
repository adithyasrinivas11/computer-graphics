import cv2
import numpy as np
from PIL import Image

#from numpy import asarray
image = cv2.imread('/root/Desktop/computer-graphics/lab11/lenna.png')
cv2.imshow('orginal',image)
h=image.shape[0]
w=image.shape[1]


h1=h/4
h2=3*h/4

w1=w/4
w2=3*w/4
print(h1,h2,w1,w2)

data = np.zeros((h,w, 3), dtype=np.uint8)
m=0
n=0
for i in range (w1,w2):
	for j in range (h1,h2):
		#for k in range (0,3):
		data[i][j]=image[i][j]
			


img = Image.fromarray(data, 'RGB')
img.show()

#cv2.imshow(img)

