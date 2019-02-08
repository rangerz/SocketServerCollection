require 'socket'

HOST = 'localhost'
PORT = 5000

server = TCPServer.open(HOST, PORT)
puts "Server start..."

client = server.accept
msg, _, _, _ = client.recvmsg(1024)
puts "Client Message: " + msg

client.puts "Hello, I'm Server."
client.close
server.close
