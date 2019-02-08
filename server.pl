use IO::Socket::INET;

my $HOST = 'localhost';
my $PORT = 5000;

my $socket = new IO::Socket::INET (
    LocalHost => $HOST,
    LocalPort => $PORT,
    Proto => 'tcp',
    Listen => 5,
    Reuse => 1
);
print "Server start...\n";

my $client_socket = $socket->accept();
$client_socket->recv(my $data, 1024);
print "Client Message: $data\n";

$client_socket->send("Hello, I'm Server.");
$socket->close();
