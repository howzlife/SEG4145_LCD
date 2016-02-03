/*----------------------------------------------------------------------------
 * lcd.c
 *
 * @author Nicolas Dubus 3811637
 *----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "serial.h"

// Port Handles for Serial and LCD
extern xComPortHandle xSerialPort;


// Constants

uint8_t const START_CHAR = 0xFE;
uint8_t const TOP_ROW = 0x80;
uint8_t const BOTTOM_ROW = 0xC0;
uint8_t const SET_BOTH_ROWS = 0x38;
uint8_t const CLEAR_LCD = 0x01;

// Private methods

static void sendChar(uint8_t command);
static void sendString(char* message);
static void flush();

/*----------------------------------------------------------------------------
 * Description:
 * 		Performs all initialization for the LCD screen display
 *----------------------------------------------------------------------------*/
void initLCD()
{
	// Initialize the serial port handle for the LCD
	xSerialPort = xSerialPortInitMinimal(USART1, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);

	// Set the LCD to display 2 rows and clear it
	sendChar(SET_BOTH_ROWS);
	sendChar(CLEAR_LCD);

	// The task is now initialized
	xSerialxPrint_P(&xSerialPort, PSTR("Initialized LCD Module\n"));
}

/*----------------------------------------------------------------------------
 * Description:
 * 		Displays one message of up to 32 characters
 *----------------------------------------------------------------------------*/

void displayOneMessage(char* message) {

	// Truncate the string if it's over 32 characters
	if (sizeof(message) > 32) message[32] = '\0';

	sendChar(CLEAR_LCD);

	sendString(message);

	flush();
}

/*----------------------------------------------------------------------------
 * Description:
 * 		Displays first string on top row, second as bottom row, max 16 chars each
 *----------------------------------------------------------------------------*/

void displayTwoMessages(char* topMessage, char* bottomMessage) {

	// Truncate the strings if they are over 16 characters
	if (sizeof(topMessage) > 16) topMessage[16] = '\0';
	if (sizeof(bottomMessage) > 16) bottomMessage[16] = '\0';

	sendChar(CLEAR_LCD);

	sendChar(TOP_ROW);
	sendString(topMessage);

	sendChar(BOTTOM_ROW);
	sendString(bottomMessage);

	flush();
}

/*----------------------------------------------------------------------------
 * Description:
 * 		Sends single character to the LCD, for message passing. Useful for
 * 		various operations and behavior, e.g. print to top row, print to
 * 		bottom row, clear LCD, etc.
 *----------------------------------------------------------------------------*/
static void sendChar(uint8_t hexChar) {
	avrSerialxPrintf_P(&xSerialPort,PSTR("%c"), START_CHAR);
	avrSerialxPrintf_P(&xSerialPort,PSTR("%c"), hexChar);
}

/*----------------------------------------------------------------------------
 * Description:
 * 		Sends a string to the LCD display.
 *----------------------------------------------------------------------------*/

static void sendString(char* message) {
	avrSerialxPrintf_P(&xSerialPort,PSTR("%s"), message);
}

static void flush() {
	xSerialFlush(&xSerialPort);
}

