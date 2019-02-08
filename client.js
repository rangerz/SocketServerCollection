var HOST = 'localhost';
var PORT = 5000;

var net = require('net');
var client = new net.Socket();
client.connect(PORT, HOST, function() {
    console.log('Connected');
    client.write("Hello, I'm Client.");
});

client.on('data', function(data) {
    console.log('Received: ' + data);
    client.destroy();
});