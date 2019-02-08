<?php
$HOST = 'localhost';
$PORT = 5000;

$socket = socket_create(AF_INET, SOCK_STREAM, 0);
socket_bind($socket, $HOST, $PORT);
socket_listen($socket, 2);
echo "Server start...\n";

$spawn = socket_accept($socket);
$data = socket_read($spawn, 1024);
echo "Client Message: " . trim($data) . "\n";

$msg = "Hello, I'm Server.";
socket_write($spawn, $msg, strlen($msg));
socket_close($spawn);
socket_close($socket);
?>
