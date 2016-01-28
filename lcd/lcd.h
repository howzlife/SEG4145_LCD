/*
 * lcd.h
 *
 *  Created on: Jan 27, 2016
 *      Author: nicolasdubus
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

void initializeLCD(void);
void displayOneMessage(char* message);
void displayTwoMessages(char* topMessage, char* bottomMessage);

#endif /* LCD_LCD_H_ */
