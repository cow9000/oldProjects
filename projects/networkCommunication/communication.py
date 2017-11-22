from threading import Thread
import os
from socket import *

class myClassA(Thread):
	def __init__(self):
		Thread.__init__(self)
		self.daemon = True
		self.start()
	def run(self):
		while True:
			host = ""
			port = 13000
			buf = 1024
			addr = (host, port)
			UDPSock = socket(AF_INET, SOCK_DGRAM)
			UDPSock.bind(addr)
			print("Waiting to receive messages...")
			while True:
				(data, addr) = UDPSock.recvfrom(buf)
				print("Received message: " + data.decode("utf-8"))
				if data == "exit":
					break
			UDPSock.close()
			os._exit(0)

class myClassB(Thread):
	def __init__(self):
		Thread.__init__(self)
		self.daemon = True
		self.start()
	def run(self):
		while True:
			#Dereks laptop - 10.226.2.237
			host2 = "10.226.40.91" # set to IP address of target computer
			port2 = 13000
			addr2 = (host2, port2)
			UDPSock2 = socket(AF_INET, SOCK_DGRAM)
			while True:
				data2 = input("Enter message to send or type 'exit': ")
				UDPSock2.sendto(data2.encode("utf-8"), addr2)
				if data2 == "exit":
					break
			UDPSock.close()
			os._exit(0)

myClassA()
myClassB()
while True:
	pass
