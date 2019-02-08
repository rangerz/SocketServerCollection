use IO::Socket::INET;

my $HOST = 'localhost';
my $PORT = 5000;

my $socket = new IO::Socket::INET (
    PeerHost => $HOST,
    PeerPort => $PORT,
    Proto => 'tcp',
);
print "Connected\n";
$socket->send("I'm Client");

$socket->recv(my $response, 1024);
print "Received: $response\n";
$socket->close();
