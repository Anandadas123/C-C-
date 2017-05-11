import cv2
import os
from find_obj import filter_matches,explore_match
import sys

#homedir=os.environ['HOME']
#print homedir
img1 = cv2.imread('160317_134844_16363225_color_l_031.jpg',0)          
img2 = cv2.imread('160317_134844_16363225_color_l_081.jpg',0) 

# Initiate SIFT detector
#orb = cv2.ORB_create()
orb = cv2.ORB(nfeatures=100000) #(nfeatures=100000)

#orb = cv2.ORB_create()
#os.getcwd()   base path of linux



# find the keypoints and descriptors with SIFT
kp1, des1 = orb.detectAndCompute(img1,None)
kp2, des2 = orb.detectAndCompute(img2,None)


#print kp2
img1kp=cv2.drawKeypoints(img1,kp1,color=(0,255,0),flags=0)
img2kp=cv2.drawKeypoints(img2,kp2,color=(0,255,0),flags=0)

cv2.imwrite('m_img1.jpg',img1kp)
cv2.imwrite('m_img2.jpg',img2kp)

#img1 = cv2.imread('m_img1.jpg')
#img2 = cv2.imread('m_img2.jpg')
#cv2.imshow('img',img1)
#cv2.imshow('ig2',img2)

#f=open('f1.txt','w')
#for ele in kp1:
#    f.write(ele+'\n')
#
#f.close()
print len(kp1)
#print kp1
#print kp1[len(kp1)-1]
alist =[]
for keypoint in kp1:
     alist.append(keypoint.pt)
     alist.append(keypoint.size)
     alist.append(keypoint.angle)
     alist.append(keypoint.response)
     alist.append(keypoint.octave)
     alist.append(keypoint.class_id)
    

#print kp2[len(kp2)-1]
print len(alist)



outfile = open("file_path.txt", "a+")
print >> outfile, "\n".join(str(i) for i in alist)
print >> outfile,"".join("2nd case")
#print >> outfile, "\n".join(str(i.pt) for i in kp2)

outfile.close()
#print type(kp1[0])
#print dir(cv2)

# create BFMatcher object
bf = cv2.BFMatcher(cv2.NORM_HAMMING)#, crossCheck=True

matches = bf.knnMatch(des1, trainDescriptors = des2, k = 2)
p1, p2, kp_pairs = filter_matches(kp1, kp2, matches)
explore_match('find_obj', img1,img2,kp_pairs)#cv2 shows image

cv2.waitKey(0)
cv2.destroyAllWindows()




