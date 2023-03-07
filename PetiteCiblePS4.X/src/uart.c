/**
  ****************************************************************************
  * @file    uart.c
  * @author  Andrea Enrile
  * @date    16.11.2019
  * @brief   Implementation of the Send & Write functions and Initialization of
  *          UART 2 and 3 with 8 bit data, no parity, 1 stop bit by default.
  *          Baud range with Fosc = 120MHz: 57 Bd < baud < 3.75 MBd    
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "uart.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_uart2_rx_pointer = 0;
static Callback_t cbf_uart2_tx_pointer = 0;
static Callback_t cbf_uart3_rx_pointer = 0;
static Callback_t cbf_uart3_tx_pointer = 0;

/******************************************************************************/
/*                UARTs INITIALIZATION FUNCTION Implementation                */
/******************************************************************************/

void uartInit(uart_t eUARTx, uint32_t baud){
    uint8_t BRGH_setting;
    uint16_t BRG_val;

    switch(eUARTx)
    {
		case eUART2:
            TRISEbits.TRISE0 = 1;   // (re)Set U2RX as input

            //Configuration of RPPs
            //*************************************************************
            // Unlock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
            //************************************************************
            // Configure Output Functions RPn Pins
            // (See TABLE 11-3 & TABLE 4-32)
          //*************************************************************
            RPOR9bits.RP81R		= 0b000011;   // Assign U2TX To Pin RP81
            //*************************************************************
            // Configure Input Functions RPIn Pins
            // (See TABLE 11-1 & TABLE 4-33)
            //*************************************************************
            RPINR19bits.U2RXR  = 0b1010000;  // Assign U2RX To Pin RPI80
            //*************************************************************
            // Lock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON | (1 << 6));

            U2MODEbits.UARTEN = 0;	// TX, RX DISABLED, ENABLE at end of func

            U2MODEbits.STSEL = 0;   // 1-Stop bit
            U2MODEbits.PDSEL = 0;   // No Parity, 8-Data bits
            U2MODEbits.ABAUD = 0;   // Auto-Baud disabled

            genUartBaudParam(baud, &BRGH_setting, &BRG_val);
            U2MODEbits.BRGH = BRGH_setting; // High Baud Rate Enable bit

            U2BRG = BRG_val;        // UART Baud Rate setting

            U2STAbits.UTXISEL0 = 0;     // Interrupt after one TX character is transmitted
            U2STAbits.UTXISEL1 = 0;
            U2STAbits.URXISEL = 0b00;   // Interrupt after one RX character is received;

            U2MODEbits.UARTEN = 1;	// Enable UART
            U2STAbits.UTXEN = 1;    // Enable UART TX

            // Interrupt Controller Settings
            IPC7bits.U2TXIP = 1;    // Set IRQ priority level
            IFS1bits.U2TXIF = 0;    // Clear the Transmit Interrupt Flag
            IEC1bits.U2TXIE = 1;    // Enable Transmit Interrupts

            IPC7bits.U2RXIP = 1;    // Set IRQ priority level
            IFS1bits.U2RXIF = 0;    // Clear the RX Interrupt Flag
            IEC1bits.U2RXIE = 1;    // Enable RX Interrupts
            break;
		case eUART3:
            TRISGbits.TRISG0 = 1;   // (re)Set U3RX as input

            //Configuration of RPPs
            //*************************************************************
            // Unlock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON & ~(1 << 6));
            //************************************************************
            // Configure Output Functions RPn Pins
            // (See TABLE 11-3 & TABLE 4-32)
          //*************************************************************
            RPOR10bits.RP113R = 0b011011;   // Assign U3TX To Pin RP113
            //*************************************************************
            // Configure Input Functions RPIn Pins
            // (See TABLE 11-1 & TABLE 4-33)
            //*************************************************************
            RPINR27bits.U3RXR  = 0b1110000;  // Assign U3RX To Pin RPI112
            //*************************************************************
            // Lock Registers
            //*************************************************************
            __builtin_write_OSCCONL(OSCCON | (1 << 6));

            U3MODEbits.UARTEN = 0;	// TX, RX DISABLED, ENABLE at end of func

            U3MODEbits.STSEL = 0;   // 1-Stop bit
            U3MODEbits.PDSEL = 0;   // No Parity, 8-Data bits
            U3MODEbits.ABAUD = 0;   // Auto-Baud disabled

            genUartBaudParam(baud, &BRGH_setting, &BRG_val);
            U3MODEbits.BRGH = BRGH_setting; // High Baud Rate Enable bit

            U3BRG = BRG_val;        // UART Baud Rate setting    

            U3STAbits.UTXISEL0 = 0;     // Interrupt after one TX character is transmitted
            U3STAbits.UTXISEL1 = 0;
            U3STAbits.URXISEL = 0b00;   // Interrupt after one RX character is received;

            U3MODEbits.UARTEN = 1;	// Enable UART
            U3STAbits.UTXEN = 1;    // Enable UART TX

            // Interrupt Controller Settings
            IPC20bits.U3TXIP = 1;   // Set IRQ priority level
            IFS5bits.U3TXIF = 0;    // Clear the Transmit Interrupt Flag
            IEC5bits.U3TXIE = 1;    // Enable Transmit Interrupts

            IPC20bits.U3RXIP = 1;   // Set IRQ priority level
            IFS5bits.U3RXIF = 0;    // Clear the RX Interrupt Flag
            IEC5bits.U3RXIE = 1;    // Enable RX Interrupts
            break;
        default:
            break;
    }
}

/******************************************************************************/
/*                    UARTS USER FUNCTIONS Implementation                     */
/******************************************************************************/

void uartWriteChar(uart_t eUARTx, char c) 
{
	switch(eUARTx)
	{
		case eUART2:
			while(1 == U2STAbits.UTXBF);    // Wait if Transmit buffer is full
            U2TXREG = c;    // Write the data byte to the USART
			break;
		case eUART3:
			while(1 == U3STAbits.UTXBF);    // Wait if Transmit buffer is full
            U3TXREG = c;    // Write the data byte to the USART
			break;
		default:
			break;
	}
}

//---------------------------------------------------------
void uartWriteString(uart_t eUARTx, char *str)
{
    while(*str!='\0')
    {
        uartWriteChar(eUARTx, *str);
        str++;
    }
}
//---------------------------------------------------------	

char uartReadChar(uart_t eUARTx) 
{
	switch(eUARTx)
	{
		case eUART2:
			while (0 == U2STAbits.URXDA);   // Wait for data to be available (when polling)
			return U2RXREG;
			break;
		case eUART3:
			while (0 == U3STAbits.URXDA);   // Wait for data to be available (when polling)
			return U3RXREG;
			break;
		default:
			break;
	}
}

/******************************************************************************/
/*                        UART Interrupt Routines (IRQ)                       */
/******************************************************************************/

void uartInterruptEnable(uart_t eUARTx, rx_tx_t rxtx){
    
	switch(eUARTx)
	{
		case eUART2:
            if (eTX==rxtx)
            {
                IFS1bits.U2TXIF = 0;    // Clear the Transmit Interrupt Flag
                IEC1bits.U2TXIE = 1;    // Enable Transmit Interrupts
            }
            else
            {
                IFS1bits.U2RXIF = 0;    // Clear the RX Interrupt Flag
                IEC1bits.U2RXIE = 1;    // Enable RX Interrupts
            }
            break;
		case eUART3:
            if (eTX==rxtx)
            {
                IFS5bits.U3TXIF = 0;    // Clear the Transmit Interrupt Flag
                IEC5bits.U3TXIE = 1;    // Enable Transmit Interrupts
            }
            else
            {
                IFS5bits.U3RXIF = 0;    // Clear the RX Interrupt Flag
                IEC5bits.U3RXIE = 1;    // Enable RX Interrupts
            }
            break;
		default:
            break;
    }
 }

void uartInterruptDisable(uart_t eUARTx, rx_tx_t rxtx){
    
	switch(eUARTx)
	{
		case eUART2:
            if (eTX==rxtx)
            {
                IEC1bits.U2TXIE = 0;    // Disable Transmit Interrupts
                IFS1bits.U2TXIF = 0;    // Clear the Transmit Interrupt Flag
            }
            else
            {
                IEC1bits.U2RXIE = 0;    // Disable RX Interrupts
                IFS1bits.U2RXIF = 0;    // Clear the RX Interrupt Flag
            }
            break;
		case eUART3:
            if (eTX==rxtx)
            {
                IEC5bits.U3TXIE = 0;    // Disable Transmit Interrupts
                IFS5bits.U3TXIF = 0;    // Clear the Transmit Interrupt Flag
            }
            else
            {
                IEC5bits.U3RXIE = 0;    // Disable RX Interrupts
                IFS5bits.U3RXIF = 0;    // Clear the RX Interrupt Flag
            }
            break;
		default:
            break;
    }    
}

//Callback register function
void registerUARTxCallback(uart_t eUARTx, rx_tx_t rxtx, Callback_t cbf_pointer)
{
    switch (eUARTx)
    {
        case eUART2:
            if (eRX==rxtx)
            {
                cbf_uart2_rx_pointer = cbf_pointer;
            }
            else
            {
                cbf_uart2_tx_pointer = cbf_pointer;
            }
            break;
        case eUART3:
            if (eRX==rxtx)
            {
                cbf_uart3_rx_pointer = cbf_pointer;
            }
            else
            {
                cbf_uart3_tx_pointer = cbf_pointer;
            }
            break;
        default:
            break;
    }
}

//UART2 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U2TXInterrupt(void)
{
  IFS1bits.U2TXIF = 0;    // Clear the Transmit Interrupt Flag
  if (0!=cbf_uart2_tx_pointer)
  {
    cbf_uart2_tx_pointer();
  }
}
// UART2 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U2RXInterrupt(void)
{
  IFS1bits.U2RXIF = 0;    // Clear the Receive Interrupt Flag
  if (0!=cbf_uart2_rx_pointer)
  {
    cbf_uart2_rx_pointer();
  }
}
//UART3 TX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U3TXInterrupt(void)
{
  IFS5bits.U3TXIF = 0;    // Clear the Transmit Interrupt Flag
  if (0!=cbf_uart3_tx_pointer)
  {
    cbf_uart3_tx_pointer();
  }
}
//UART3 RX interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _U3RXInterrupt(void)
{
  IFS5bits.U3RXIF = 0;    // Clear the Receive Interrupt Flag
  if (0!=cbf_uart3_rx_pointer)
  {
    cbf_uart3_rx_pointer();
  }
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
void genUartBaudParam(uint32_t baud, uint8_t *BRGH_bit, uint16_t *BRG_val)
{
    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
    uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
    uint32_t Fcy = Fosc >> 1;
    
//	// Abort the program if baud = 0 or a pointer address is NULL.
//	if(baud == 0 || BRGH_bit == NULL || BRG_val == NULL)
//	{
//		assert(0);
//	}

    if (baud <= Fcy/(16*((uint32_t)0xFFFF+1)))
    {
        *BRGH_bit = 0;
        *BRG_val = UINT16_MAX;  // Min achievable baudrate
    }
    else if (baud <= Fcy/(4*((uint32_t)0xFFFF+1)))
    {
        *BRGH_bit = 0;
        *BRG_val = (uint16_t)(Fcy/(16.0*baud)+0.5)-1;
    }
    else if(baud >= Fcy/4)
    {
        *BRGH_bit = 1;
        *BRG_val = 0x0000;    // Max achievable baudrate
    }
    else
    {
        *BRGH_bit = 1;
        *BRG_val = (uint16_t)(Fcy/(4.0*baud)+0.5)-1;
    }				
}