import socket

HOST = 'localhost'
PORT = 5000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
print("Connected")
s.sendall("Hello, I'm Client");

data = s.recv(1024)
print("Received: " + data)
s.close()
