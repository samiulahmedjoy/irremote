/*
Author: Samiul Ahmed Joy
Date: February 10, 2025
Necessary Library: Arduino Irremote library
External Library link: https://github.com/Arduino-IRremote/Arduino-IRremote
*/

/* Description/Usage
It's basically a turn off/on switch but with remote, you
can integrate this project into any code that requires you to
turn off/on switches, but more smartly with remote.

I made this thing because I wanted to turn off the wifi from my bed at night
so that I don't have to get up at night. Turns out, adding this project to simple
things like lights and ceiling fans can be of great help for old people because they have
restricted movement. So this can really help them out.
*/

#include <IRremote.hpp>
#include <stdbool.h>

#define IR_RECEIVE_PIN 5
#define RELAY_PIN 3

const unsigned short int on_val = 25; // remote value for on
const unsigned short int off_val = 69; //remote value for off

bool w = 0;

void setup() {
	IrReceiver.begin(IR_RECEIVE_PIN, 0); // the 0 is for no constant blinking of led
	pinMode(RECEIVE_PIN, INPUT);
	pinMode(RELAY_PIN, OUTPUT);
}

void wifi_off() {
	digitalWrite(RELAY_PIN, LOW);
	w=0;
}

void wifi_on() {
	digitalWrite(RELAY_PIN, HIGH);
	w=0;
}

void loop() {
  
	if (IrReceiver.decode()) {

    switch(IrReceiver.decodedIRData.command) {
			case on_val:
				wifi_on();
				break ;
			case off_val:
				wifi_off();
				break ;
			default:
			if (w==1) {
				digitalWrite(LED_BUILTIN, HIGH);
				delay(500);
				digitalWrite(LED_BUILTIN, LOW);
			}
			break ;
		}
	}
	IrReceiver.resume();
	// Add 2 s delay so that arduino doesn't get too much hot
	// because the IrReceiver function runs in a constant loop, this prevents it
	delay(2000);
}
