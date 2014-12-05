os.system('sudo gphoto2 --auto-detect')
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
arduino.open()
graph = GraphAPI('XXX')
fanpageid = 'XXX'
fanpage_token = ''
accounts = graph.get('me/accounts')
album_id = 'XXX'
for account in accounts['data']:
	if account['id'] == fanpageid or account['name'] == fanpageid :
     		fanpage_token = account['access_token']
graph = GraphAPI(fanpage_token)

while 1:
	reponse = arduino.readline()
	if reponse :
		print reponse
         	os.system('sudo ./usbreset /dev/bus/usb/001/012')
		"""
		a usb reset script written in C, that you will compile in order to fix some bugs in the raspberry pi
		"""
		os.system('sudo gphoto2 --capture-image-and-download --filename="photobooth.JPG"') 

		fg = 'logo.png'
		bg = 'photobooth.JPG'
		with Image(filename=bg) as bg_img:
			with Image(filename=fg) as fg_img:
				bg_img.composite(fg_img, left=1400, top=1100)
    			bg_img.save(filename='photobooth.JPG')
		picid = graph.post(
    			path = album_id+'/photos',
	    		source = open('photobooth.JPG'),
    			message = '',
			aid = album_id,
			no_story = 0,
			access_token = fanpage_token
		)
		
		os.remove("photobooth.JPG")
		time.sleep(1)
		arduino.write('f')
		print picid

