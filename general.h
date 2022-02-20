#ifndef GENERAL_H
#define GENERAL_H

//bit manipulation with the SPI pins and ports
#define RESET(x) bitClear(x)
#define SET(x) bitSet(x)
#define TOGGLE(x) toggle(x)

#define bitClear(x,y) PORT(x) &= ~(1 << y)
#define bitSet(x, y) PORT(x) |= (1 << y);
#define toggle(x,y) PORT(x) ^= (1 << y)


#define PORT(x) _port(x)


#define _port(x) PORT ## x


//pins for the Arduino mega 2560

#define P_MOSI B,2 // pin 51
#define P_MISO B,3 // pin 50
#define P_SCK B,1 // pin 52
#define MCP2515_CS B,0 // pin 2
#define MCP2515_INT E,4 // pin 8


#endif