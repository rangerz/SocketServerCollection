var HOST = 'localhost';
var PORT = 5000;

var net = require('net');
var server = net.createServer(function(socket) {
    socket.on('data', function(data) {
        var address = socket.address();
        console.log('Client Message: ' + data);
        socket.write("Hello, I'm Server.");
        server.close();
    });
});

server.listen(PORT, HOST, function() {
    console.log('Server start...');
});
