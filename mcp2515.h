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


#ifndef MCP2515_H
#define MCP2515_H


#include "mcp2515_registers.h"
#include "avr/io.h"
#include "general.h"





/*

Here we will contain all the functions that help us communicate with MCP2515 
*/

class MCP2515 
{
    private:
        
    public:
    //Write to the SPI bus (MOSI pin) and also receives (MISO pin)
    template<typename value> 
    inline value readwrite(value data);
    //Before using readwrite function this alllows us to gain access to the SPI bus and configure the settings
    

    //write to certain register in the MCP2515 
    template <typename value>
    inline value writeRegister(value addr, value data);

    //read from a certain register in the MCP2515
    template <typename value>
    inline value readRegister(value addr);

    //modify value in the address
    template <typename value>
    inline void bitModify(value addr, value mask, value data);

    template <typename value>
    inline value begin(value speed);
    //allows access to the pins

    //read a status from the MCP2515 to recieve messages
    template <typename value>
    inline value readStatus(value stat);

    

        
};






#endif