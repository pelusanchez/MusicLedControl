'use strict';

// Copyright David Iglesias
// REQUIRE SERIALPORT AND SOCKET.IO!

const SerialPort = require('serialport');
const port = new SerialPort('/dev/ttyACM0');
var io = require('socket.io').listen("8080");

io.on('connection', function(socket) {
	port.on('open', function() {
  		console.log('Port Opened');
	});

    socket.on("d", function(data){
    	console.log(data);
    	port.write(data);
    });
});