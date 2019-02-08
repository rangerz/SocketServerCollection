<?php
$HOST = "localhost";
$PORT  = 5000;
$socket = socket_create(AF_INET, SOCK_STREAM, 0);
socket_connect($socket, $HOST, $PORT);
echo "Connected\n";
$msg = "Hello, I'm Client";
socket_write($socket, $msg, strlen($msg));

$data = socket_read ($socket, 1024);
echo "Received: " . $data . "\n";
socket_close($socket);
?>
