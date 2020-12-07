import cv2
import numpy as np 
image = cv2.imread('/root/Desktop/computer-graphics/lab10/photo.jpg') 

# Store height and width of the image 
height=image.shape[0] 
width = image.shape[1]

tx=30
ty=30

T = np.float32([[1, 0, tx], [0, 1, ty]]) 

img_translation = cv2.warpAffine(image, T, (width, height))

angle=46

image_center = tuple(np.array(image.shape[1::-1]) / 2)
rot_mat = cv2.getRotationMatrix2D(image_center, angle, 1.0)
img_rotation = cv2.warpAffine(image, rot_mat, image.shape[1::-1], flags=cv2.INTER_LINEAR)

img_scaling=cv2.resize(image, (780, 540), 3,3 ,interpolation = cv2.INTER_NEAREST) 


cv2.imshow("Originalimage", image) 
cv2.imshow("Translation", img_translation)
cv2.imshow("Rotation", img_rotation) 
cv2.imshow("scaling", img_scaling) 
cv2.waitKey() 

cv2.destroyAllWindows() 

