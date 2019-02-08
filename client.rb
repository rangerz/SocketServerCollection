require 'socket'

HOST = 'localhost'
PORT = 5000

socket = TCPSocket.open(HOST, PORT)
puts 'Connected'
socket.write "I'm Client"

msg, _, _, _ = socket.recvmsg(1024)
puts 'Received: ' + msg
socket.close
