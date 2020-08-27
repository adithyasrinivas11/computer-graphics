import cv2
import numpy as np
#from skimage.util import random_noise
#  a,b,c :: 3/8, 2/8,3/8
#(0.299r(x,y)+0.587g(x,y)+0.114b(x,y)),
img = cv2.imread("lena.png")
#cv2.imshow('original image',img)
#img = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)


X=img.shape[0]	#x coordinate
Y=img.shape[1]	#y coordinate

print(X,Y);

a=3/8
b=2/8
c=3/8

new_img=[[0 for i in range(Y)] for j in range(X)]
new_img1=[[0 for i in range(Y)] for j in range(X)]
comp=[[0 for i in range(Y)] for j in range(X)]

p=[[0 for i in range(Y)] for j in range(X)]
z=[[0 for i in range(Y)] for j in range(X)]

avg=[[0 for i in range(Y)] for j in range(X)]   #average error
avg1=[[0 for i in range(Y)] for j in range(X)]   #average error
for i in range(X):					#even-even
	for j in range(Y):
		new_img[i][j]=(img[i][j][0]*0.299)+(img[i][j][1]*0.587)+(img[i][j][2]*0.114)
		new_img1[i][j]=(img[i][j][0]*0.299)+(img[i][j][1]*0.587)+(img[i][j][2]*0.114)
		if (new_img[i][j]<=127):
			p[i][j]=0
			z[i][j]=0
		else:
			p[i][j]=255
			z[i][j]=0

new_img1 = np.array(new_img1, dtype = 'uint8')
cv2.imwrite("2_output_fdash.jpg", new_img1)
for i in range(X):					#even-even
	for j in range(Y):
		if(i+1 <X and j+1< Y):
			if (new_img[i][j]<=127):
				p[i][j]=0
				#print("54")
			else:
				p[i][j]=255
				
			e=new_img[i][j]-p[i][j]
			#print(e)
			a=0.375
			b=0.25
			c=0.375

			q=new_img[i+1][j+1]
			qq=new_img[i][j+1]
			new_img[i+1][j]= new_img[i+1][j]+(a*e)
			new_img[i+1][j+1] +=b*e
			new_img[i][j+1]+=c*e
			#print(c,e,c*e)
			#print("::",qq-new_img[i][j+1])
		#if (new_img[i][j]<=127):
		#	p[i][j]=0
		#else:
		#	p[i][j]=255
			#if (new_img[i+1][j]<=127):
			#	p[i+1][j]=0
			#	#print("54")
			#else:
			#	p[i+1][j]=255
			#if (new_img[i+1][j+1]<=127):
			#	p[i+1][j+1]=0
				#print("59")
			#else:
			#	p[i+1][j+1]=255
			#if (new_img[i][j+1]<=127):
			#	p[i][j+1]=0
			#	#print("64")
			#else:
			#	p[i][j+1]=255

for i in range(X):					#even-even
		for j in range(Y):
			comp[i][j]=new_img[i][j]-p[i][j]					

comp = np.array(comp, dtype = 'uint8')
cv2.imwrite("2_output_comp.jpg", comp)

p = np.array(p, dtype = 'uint8')
cv2.imwrite("2_output_B2.jpg", p)

for i in range(X):					#even-even
	for j in range(Y):
		a1=new_img[i][j]-p[i][j]
		if(i-1>0 and j-1>0 and i+1<X and j+1<Y):				#middle points
			a2=new_img[i-1][j-1]-p[i-1][j-1]
			a3=new_img[i-1][j]-p[i-1][j]
			a4=new_img[i][j-1]-p[i][j-1]
			a5=new_img[i-1][j+1]-p[i-1][j+1]
			a6=new_img[i+1][j-1]-p[i+1][j-1]
			a7=new_img[i+1][j]-p[i+1][j]
			a8=new_img[i][j+1]-p[i][j+1]
			a9=new_img[i+1][j+1]-p[i+1][j+1]
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1<0 and j-1>0 and i+1<X and j+1<Y):				#points in column 1
			a2=0
			a3=0
			a4=new_img[i][j-1]-p[i][j-1]
			a5=0
			a6=new_img[i+1][j-1]-p[i+1][j-1]
			a7=new_img[i+1][j]-p[i+1][j]
			a8=new_img[i][j+1]-p[i][j+1]
			a9=new_img[i+1][j+1]-p[i+1][j+1]
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1<0 and i+1<X and j+1<Y):				#points in 1st row
			a2=0
			a3=new_img[i-1][j]-p[i-1][j]
			a4=0
			a5=new_img[i-1][j+1]-p[i-1][j+1]
			a6=0
			a7=new_img[i+1][j]-p[i+1][j]
			a8=new_img[i][j+1]-p[i][j+1]
			a9=new_img[i+1][j+1]-p[i+1][j+1]
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1<0 and j-1<0 and i+1<X and j+1<Y):				#points like 0,0
			a2=0
			a3=0
			a4=0
			a5=0
			a6=0
			a7=new_img[i+1][j]-p[i+1][j]
			a8=new_img[i][j+1]-p[i][j+1]
			a9=new_img[i+1][j+1]-p[i+1][j+1]
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1>X and j+1>Y):				# points like X,Y
			a2=new_img[i-1][j-1]-p[i-1][j-1]
			a3=new_img[i-1][j]-p[i-1][j]
			a4=new_img[i][j-1]-p[i][j-1]
			a5=0
			a6=0
			a7=0
			a8=0
			a9=0
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1<X and j+1>Y):				#Last row
			a2=new_img[i-1][j-1]-p[i-1][j-1]
			a3=new_img[i-1][j]-p[i-1][j]
			a4=new_img[i][j-1]-p[i][j-1]
			a5=0
			a6=new_img[i+1][j-1]-p[i+1][j-1]
			a7=new_img[i+1][j]-p[i+1][j]
			a8=0
			a9=0
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1>X and j+1<Y):				#last column
			a2=new_img[i-1][j-1]-p[i-1][j-1]
			a3=new_img[i-1][j]-p[i-1][j]
			a4=new_img[i][j-1]-p[i][j-1]
			a5=new_img[i-1][j+1]-p[i-1][j+1]
			a6=0
			a7=0
			a8=new_img[i][j+1]-p[i][j+1]
			a9=0
			avg[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9

avg= np.array(avg, dtype = 'uint8')
cv2.imwrite("2_output_avg_b2.jpg", avg)


for i in range(X):					#even-even
	for j in range(Y):
		a1=new_img[i][j]-z[i][j]
		if(i-1>0 and j-1>0 and i+1<X and j+1<Y):				#middle points
			a2=new_img[i-1][j-1]-z[i-1][j-1]
			a3=new_img[i-1][j]-z[i-1][j]
			a4=new_img[i][j-1]-z[i][j-1]
			a5=new_img[i-1][j+1]-z[i-1][j+1]
			a6=new_img[i+1][j-1]-z[i+1][j-1]
			a7=new_img[i+1][j]-z[i+1][j]
			a8=new_img[i][j+1]-z[i][j+1]
			a9=new_img[i+1][j+1]-z[i+1][j+1]
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1<0 and j-1>0 and i+1<X and j+1<Y):				#points in column 1
			a2=0
			a3=0
			a4=new_img[i][j-1]-z[i][j-1]
			a5=0
			a6=new_img[i+1][j-1]-z[i+1][j-1]
			a7=new_img[i+1][j]-z[i+1][j]
			a8=new_img[i][j+1]-z[i][j+1]
			a9=new_img[i+1][j+1]-z[i+1][j+1]
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1<0 and i+1<X and j+1<Y):				#points in 1st row
			a2=0
			a3=new_img[i-1][j]-z[i-1][j]
			a4=0
			a5=new_img[i-1][j+1]-z[i-1][j+1]
			a6=0
			a7=new_img[i+1][j]-z[i+1][j]
			a8=new_img[i][j+1]-z[i][j+1]
			a9=new_img[i+1][j+1]-z[i+1][j+1]
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1<0 and j-1<0 and i+1<X and j+1<Y):				#points like 0,0
			a2=0
			a3=0
			a4=0
			a5=0
			a6=0
			a7=new_img[i+1][j]-z[i+1][j]
			a8=new_img[i][j+1]-z[i][j+1]
			a9=new_img[i+1][j+1]-z[i+1][j+1]
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1>X and j+1>Y):				# points like X,Y
			a2=new_img[i-1][j-1]-z[i-1][j-1]
			a3=new_img[i-1][j]-z[i-1][j]
			a4=new_img[i][j-1]-z[i][j-1]
			a5=0
			a6=0
			a7=0
			a8=0
			a9=0
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1<X and j+1>Y):				#Last row
			a2=new_img[i-1][j-1]-z[i-1][j-1]
			a3=new_img[i-1][j]-z[i-1][j]
			a4=new_img[i][j-1]-z[i][j-1]
			a5=0
			a6=new_img[i+1][j-1]-z[i+1][j-1]
			a7=new_img[i+1][j]-z[i+1][j]
			a8=0
			a9=0
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9
		if(i-1>0 and j-1>0 and i+1>X and j+1<Y):				#last column
			a2=new_img[i-1][j-1]-z[i-1][j-1]
			a3=new_img[i-1][j]-z[i-1][j]
			a4=new_img[i][j-1]-z[i][j-1]
			a5=new_img[i-1][j+1]-z[i-1][j+1]
			a6=0
			a7=0
			a8=new_img[i][j+1]-z[i][j+1]
			a9=0
			avg1[i][j]=(a1+a2+a3+a4+a5+a6+a7+a8+a9)/9

avg1= np.array(avg1, dtype = 'uint8')
cv2.imwrite("2_output_avg_b1.jpg", avg1)


