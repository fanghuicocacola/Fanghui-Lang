import cv2

SRC = 'yuantu.jpg'
img_rgb = cv2.imread(SRC)
img_gray = cv2.cvtColor(img_rgb,cv2.COLOR_BGR2GRAY)
img_blur = cv2.GaussianBlur(img_gray,ksize=(21,21),sigmaX=0,sigmaY=0)
img_blend = cv2.divide(img_gray,img_blur,scale=255)
cv2.imwrite('sumiao.jpg',img_blend)