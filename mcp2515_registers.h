
/*
                                                     
 ______   ______   ________   ______       ______   ________  __  __      
/_____/\ /_____/\ /_______/\ /_____/\     /_____/\ /_______/\/_/\/_/\     
\::::_\/_\::::_\/_\::: _  \ \\::::_\/_    \::::_\/_\__.::._\/\:\ \:\ \    
 \:\/___/\\:\/___/\\::(_)  \ \\:\/___/\    \:\/___/\  \::\ \  \:\ \:\ \   
  \:::._\/ \_::._\:\\:: __  \ \\::___\/_    \:::._\/  _\::\ \__\:\ \:\ \  
   \:\ \     /____\:\\:.\ \  \ \\:\____/\    \:\ \   /__\::\__/\\:\_\:\ \ 
    \_\/     \_____\/ \__\/\__\/ \_____\/     \_\/   \________\/ \_____\/ 
      
                             CODE By Carlos Almagro             

*/

#ifndef MCP2515_REGISTERS_H
#define MCP2515_REGISTERS_H 


//CAN CONTROLLER SPEEDS

#define CANSPEED_125 7 // 125 kbps
#define CANSPEED_250 3 // 250 kbps
#define CANSPEED_500 1 // 500 kbps


//CAN CONTROLER REGISTER MAP
/*


*/


//can be found in the data sheet under section 11.0 Register map and table 11-1
//https://ww1.microchip.com/downloads/en/DeviceDoc/MCP2515-Stand-Alone-CAN-Controller-with-SPI-20001801J.pdf
//-------------------------
#define RXF0SIDH 0x00
#define RXFOSIDL 0x01
#define RXF0EID8 0x02
#define RXF0EID0 0x03
#define RXF1SIDH 0x04
#define RXF1SIDL 0x05
#define RXF1EID8 0x06
#define RXF1EID0 0x07
#define RXF2SIDH 0x08
#define RXF2SIDL 0x09
#define RXF2EID8 0x0A
#define RXF2EID0 0x0B   
#define BFPCTRL  0x0C
#define TXRTSCTRL 0x0D
//-------------------------
#define RXF3SIDH 0x10
#define RXF3SIDL 0x11
#define RXF3EID8 0x12
#define RXF3EID0 0x13
#define RXF4SIDH 0x14
#define RXF4SIDL 0x15
#define RXF4EID8 0x16
#define RXF4EID0 0x17
#define RXF5SIDH 0x18
#define RXF5SIDL 0x19
#define RXF5EID8 0x1A
#define RXF5EID0 0x1B
#define TEC 0x1C
#define REC 0x1D
//-------------------------
#define RXM0SIDH 0x20
#define RXMOSIDL 0x21
#define RXM0EID8 0x22
#define RXM0EID0 0x23
#define RXM1SIDH 0x24
#define RXM1SIDL 0x25
#define RXM1EID8 0x26
#define RXM1EID0 0x27
#define CNF3 0x28
#define CNF2 0x29
#define CNF1 0x2A
#define CANINTER 0x2B
#define CANINTF 0x2C
#define EFLG 0x2D
//----------------------------
#define TXB0CTRl 0x30
#define TXB0SIDH 0x31
#define TXB0SIDL 0x32
#define TXB0EID8 0x33
#define TXB0EID0 0x34
#define TXB0DLC 0x35
#define TXB0D1 0x36
#define TXB0D2 0x37
#define TXB0D3  0x38
#define TXB0D4 0x39
#define TXB0D5 0x3A
#define TXB0D6 0x3B
#define TXB0D7 0x3C
//--------------------------------
#define TXB1CTRl 0x30
#define TXB1SIDH 0x31
#define TXB1SIDL 0x32
#define TXB1EID8 0x33
#define TXB1EID0 0x34
#define TXB1DLC 0x35
#define TXB1D1 0x36
#define TXB1D2 0x37
#define TXB1D3  0x38
#define TXB1D4 0x39
#define TXB1D5 0x3A
#define TXB1D6 0x3B
#define TXB1D7 0x3C
//--------------------------------------
#define TXB2CTRl 0x30
#define TXB2SIDH 0x31
#define TXB2SIDL 0x32
#define TXB2EID8 0x33
#define TXB2EID0 0x34
#define TXB2DLC 0x35
#define TXB2D1 0x36
#define TXB2D2 0x37
#define TXB2D3  0x38
#define TXB2D4 0x39
#define TXB2D5 0x3A
#define TXB2D6 0x3B
#define TXB2D7 0x3C

//-------------------------------
#define RXB0CTRl 0x30
#define RXB0SIDH 0x31
#define RXB0SIDL 0x32
#define RXB0EID8 0x33
#define RXB0EID0 0x34
#define RXB0DLC 0x35
#define RXB0D1 0x36
#define RXB0D2 0x37
#define RXB0D3  0x38
#define RXB0D4 0x39
#define RXB0D5 0x3A
#define RXB0D6 0x3B
#define RXB0D7 0x3C
//-------------------------------------
#define RXB1CTRl 0x30
#define RXB1SIDH 0x31
#define RXB1SIDL 0x32
#define RXB1EID8 0x33
#define RXB1EID0 0x34
#define RXB1DLC 0x35
#define RXB1D1 0x36
#define RXB1D2 0x37
#define RXB1D3  0x38
#define RXB1D4 0x39
#define RXB1D5 0x3A
#define RXB1D6 0x3B
#define RXB1D7 0x3C
//------------------------------------------
#define CANSTAT 0x0E
#define CANCTRL 0x0F




// SPI INSTRUCTION SET
/*
    Instruction Name        Instruction Format          Description     
    ----------------------------------------------------------------
    RESET                   1100 000 = 0XC0             Reset internal registers to the default state, sets configuration mode
    READ                    0000 0011 = 0x03            Reads data from the register beginning at selected address
    READ RX BUFFER          1001 0nm0 = 0x90            When reading a receive buffer, reduces the overhead of a normmal R#EAD command
    WRITE                   0000 0010 = 0x02            Writes data to the register beginning at the selected address
    LOAD TX BUFFER          0100 0abc

*/
#endif