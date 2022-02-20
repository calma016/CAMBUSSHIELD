
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

#include "mcp2515.h"

/*
*/
template <typename value>
inline value MCP2515::readwrite(value data)
{

    /*
        The SPDR is short for SPI Data Register this where data transfers happen
    */
    SPDR = data; 
    //SPSR is short for SPI status register this is the status register. This register is used to read the status
    //SPIF is short for SPI interrup flag The SPI interrupt flag is set whenever a serial transfer is complete
    while (!(SPSR & (1 << SPIF))) //wating for the register to be true = 1 meanig data has been transfered
        ;
    return SPDR;
}

/*
Write Instruction
------------------------------------------------------
The WRITE instruction is started by lowering the CS
pin. The WRITE instruction is then sent to the
MCP2515, followed by the address and at least one
byte of data.


*/
template <typename value>
inline value MCP2515::writeRegister(value addr, value data)
{
#ifdef MCP2515_CS

    RESET(MCP2515_CS) //Set the chip select LOW

    readwrite(SPI_WRITE); //Enable the SPI instruction write 
    readwrite(addr); //The addr location for where that instruction wants to be written
    readwrite(data); //The byte of data that wants to be written to the register

    SET(MCP2515_CS); //Set the chip select HIGH
#endif
}
/*

Read Instruction
------------------------------------------------------
The READ instruction is started by lowering the CS pin.
The READ instruction is then sent to the MCP2515,
followed by the 8-bit address (A7 through A0). Next, the
data stored in the register at the selected address will
be shifted out on the SO pin.

*/
template <typename value>
inline value readRegister(value addr)
{
#ifdef MCP2515_CS
    value data; //set the data variable to read from it
    REST(MCP2515_CS); //Set the chip select LOW

    readWrite(SPI_READ); //Enable the SPI instruction read from the registers
    readWrite(addr); // Select the register we want to read from
    data = readWrite(0xff); //This is a dummy bit
    SET(MCP2515_CS); //se the the chip select HIGH
    return data; // return the data we wanted to read
#endif
}

/*
Read Status Instruction
------------------------------------------------------
The READ STATUS instruction allows single instruction
access to some of the often used status bits for
message reception and transmission.
The MCP2515 is selected by lowering the CS pin and the
READ STATUS command byte, shown in Figure 12-8, is
sent to the MCP2515. Once the command byte is sent,
the MCP2515 will return eight bits of data that contain the
status.
*/
template <typename value>
inline value readStatus(value stat)
{
#ifdef MCP2515_CS
    RESET(MCP2515_CS); //Set the chip select LOW
    readWrite(SPI_STATUS); //Enable the SPI instruction to read the status 
    readWrite(stat); // send the status that we want to retrieve from the MCP2515
    data = readWrite(0xff); // return the status we wanted
    SET(MCP2515_CS); //Set the chip select HIGH
    return data; // return the data
#endif
}
