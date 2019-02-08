import socket

HOST = 'localhost'
PORT = 5000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
print("Server start...");
s.listen(2)

conn, addr = s.accept()
data = conn.recv(1024)
print("Client Message: " + data);

conn.sendall("Hello, I'm Server.")
conn.close()
