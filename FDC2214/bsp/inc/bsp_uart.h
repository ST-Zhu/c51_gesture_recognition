#ifndef __BSP_UART_H_
#define __BSP_UART_H_


extern void U1SendString(uint8 *s);
extern void U1SendData(uint8 ch);
extern void UartInit(void);

#endif
