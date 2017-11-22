#TODO: Import filter to be superimposed on face
#backup code
#attach filter to face
#Resize filter
#optimize runtime
#do rotation with eyes
#resize entire frame
#on/off key
#calculate range with face size used as a form of feducial marker to
#properly size image
#have development mode turn on/off with a keypress

# import the necessary packages
import time
import cv2

# initialize the camera and set peramaters
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(640, 480))

#setup dev mode toggle
toggle = 0
justChanged = 0

f = cv2.imread("hat.png", -1)
origFilterWidth, origFilterHeight = f.shape[:2]
#import cascade for face
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
fps = time.time()
# allow the camera to warmup
time.sleep(0.1)
#coolShades = cv2.imread("filter.png")
# capture frames from the camera, process, and display
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
        fps = time.time()
        
        # grab the raw NumPy array representing the image, then initialize the timestamp
	# and occupied/unoccupied text
        image = frame.array
        #bring in the background to be drawn on top of
        #blackness = cv2.imread("Betterblack.jpg",0)
        #blackness = frame.array
        #TESTING UNCOMMENT THIS
        blackness = cv2.imread("transparent.png")
        
        #convert frame to grayscale
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        #find faces in the frame
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)        
	# add face markers to frame
        for (x,y,w,h) in faces:



                filterWidth = w
                filterHeight = filterWidth * origFilterWidth * 2 / origFilterHeight
                x1 = x - (filterWidth/4)
                x2 = x + w + (filterWidth/2)
                y1 = y + h - (filterHeight/2)
                y2 = y + h + (filterHeight/2)
                
                fil = cv2.resize(f, (filterWidth, filterHeight), interpolation = cv2.INTER_AREA)
                
                #cv2.rectangle(blackness,(x,y),(x+w,y+h),(255,0,0),2)
                #rows, cols, channels = fil.shape
                #roi = blackness[0:rows, 0:cols]
                #img2gray = cv2.cvtColor(fil, cv2.COLOR_BGR2GRAY)
                #ret, mask = cv2.threshold(img2gray, 10, 255, cv2.THRESH_BINARY)
                #mask_inv = cv2.bitwise_not(mask)
                #blackness_bg = cv2.bitwise_and(roi,roi,mask = mask_inv)
                #f_fg = cv2.bitwise_and(fil, fil, mask = mask)
                #dst = cv2.add(blackness_bg, f_fg)
                #blackness[y1:y2, x1:x2] = fil
                
                x_offset=50
                y_offset=50
                for c in range(0,3):
                        blackness[y:y+fil.shape[0],x:x+fil.shape[1], c] = fil[:,:,c] * (fil[:,:,3]/255.0) + blackness[y:y+fil.shape[0], x:x+fil.shape[1],c] * (1.0 - fil[:,:,3]/255.0)
                        #blackness[y_offset:y_offset+fil.shape[0],x_offset:x_offset+fil.shape[1], c] = fil[:,:,c] * (fil[:,:,3]/255.0) + blackness[y_offset:y_offset+fil.shape[0], x_offset:x_offset+fil.shape[1],c] * (1.0 - fil[:,:,3]/255.0)
                        #blackness[y:y+f.shape[0], x:x+f.shape[1]] = f
                
                #roi[0:x,0:y] = dst
                if toggle == 1:
                        cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)
                
        #draw the frame
        fps -= time.time()
        fps = (1/fps) * -1
        stringFps = str(fps)

        



        cv2.putText(image, stringFps[0] + stringFps[1] + stringFps[2] + stringFps[3], (10,400), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,255,255), 2)
        cv2.imshow("No Background", blackness)
        
        #Shows the camera feed. Uncomment to help with debugging.
        #latency increases when this is active
        if toggle == 1:
                cv2.imshow("Background", image)
        
	key = cv2.waitKey(1) & 0xFF

	# clear the stream in preparation for the next frame
	rawCapture.truncate(0)

        
        #dev mode function toggle with the d key "MAY NOT WORK!!!"
	if key == ord("d"):
                if toggle == 1:
                        toggle = 0
                        cv2.destroyWindow("Background")
                        justChanged = 1
                if toggle == 0:
                        if justChanged == 0:
                                toggle = 1
                justChanged = 0

	# if the `q` key was pressed, break from the loop
	if key == ord("q"):
		break
