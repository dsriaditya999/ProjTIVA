
// Libraries

#include<stdint.h>

#include<stdbool.h>

#include "inc/hw_memmap.h"

#include "inc/hw_types.h"

#include "driverlib/gpio.h"

#include "driverlib/pin_map.h"

#include "driverlib/uart.h"

#include "utils/uartstdio.h"

#include "utils/uartstdio.c"


// Function Declarations

// // ISR Declaration

void uartInterrupt(void);

// // Variable Declaration

unsigned char data,tx_data;


int main(void){

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinConfigure(GPIO_PB0_U1RX);
    GPIOPinConfigure(GPIO_PB1_U1TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);
    GPIOPinTypeUART(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1);

    UARTClockSourceSet(UART0_BASE,UART_CLOCK_PIOSC);
    UARTStdioConfig(0,9600,16000000);
    UARTConfigSetExpClk(UART1_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));

    UARTprintf("Bluetooth Demo\n");

    while(1){


        if(UARTCharsAvail(UART1_BASE)){
            data = UARTCharGet(UART1_BASE);
            UARTCharPut(UART0_BASE,data);

            if(data=='r'){

                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_1);
            }

            else if(data=='b'){

             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_2);
        }

            else if(data=='g'){

                            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_3);
    }
            else if(data=='v'){

                            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_1|GPIO_PIN_2);

            }

            else if(data=='c'){

                            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_2|GPIO_PIN_3);

            }

            else if(data=='x'){

                                        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_1|GPIO_PIN_3);

                        }

}

    }

}
