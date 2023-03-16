/**
  ****************************************************************************
  * @file    i2c.c
  * @author  Michel Bovet
  * @date    20.04.2020
  * @brief   Implementation of the Send & Write functions and Initialization of
  *			 I2Cx in master by default. Serial clock frequency with Fosc =
  *          120MHz: 112 kHz < fscl < 2.458 MHz
  *          (For low speed internal pull-up might be used [6...13.2...22] kOhms)
  *          For more details refer to the CiblePS4 Software Documentation
  ****************************************************************************/

/******************************************************************************/
/*                              Files to Include                              */
/******************************************************************************/
#include "i2c.h"

/******************************************************************************/
/*                Callback pointers for interrupt routines                    */
/******************************************************************************/

static Callback_t cbf_i2c1_pointer = 0;
static Callback_t cbf_i2c2_pointer = 0;

/******************************************************************************/
/*                I2Cs INITIALIZATION FUNCTION Implementation                 */
/******************************************************************************/

void var_i2cInit(i2c_args in)
{
    i2c_t eI2Cx = in.eI2Cx;
    uint16_t fscl = in.fscl;
    i2cAddrLength_t slave_addr_length = in.slave_addr_length;
    pullup_on_off_t ePullUp = in.ePullUp ? in.ePullUp : ePullUpOff; // No internal PullUp by default

    switch(eI2Cx)
    {
		case eI2C1:
            break;
            if (ePullUpOn==ePullUp)
            {
                CNPUCbits.CNPUC5 = 1; // 1 = pullup enabled on SCL1
                CNPUCbits.CNPUC4 = 1; // 1 = pullup enabled on SDA1
            }
            /* The following code sequence shows master I2C register configuration */  
            I2C1CONbits.I2CEN = 0;  // Turn OFF the I2Cx module

            IFS1bits.MI2C1IF = 0;   // Clear the Interrupt flag
            IEC1bits.MI2C1IE = 0;   // Disable the interrupt

            /********** I2CxCON Register Settings **********/
            I2C1CONbits.I2CSIDL = 0;    // Continue to run while in Idle

            switch (slave_addr_length)
            {
                case bits7 :
                    I2C1CONbits.A10M = 0;       // Using a 7 bits slave address
                    break;
                case bits10 :
                    I2C1CONbits.A10M = 1;       // Using a 10 bits slave address
                    break;
                default :
                    break;
            }

            if(fscl < 400)
            {
                I2C1CONbits.DISSLW = 1; // Slew rate control is disabled
            }
            else
            {
                I2C1CONbits.DISSLW = 0; // Slew rate control is enabled
            }

            /********* I2CxBRG Register Settings **********/ 
            I2C1BRG = genI2CBaudParam(fscl);

            I2C1CONbits.I2CEN = 1;  // Turn ON the I2Cx module

            // Interrupt Controller Settings
            IPC4bits.MI2C1IP = 2;   // Set IRQ priority level
            IFS1bits.MI2C1IF = 0;   // Clear the Interrupt flag
            IEC1bits.MI2C1IE = 1;   // Enable the interrupt  
            
		case eI2C2:
            if (ePullUpOn==ePullUp)
            {
                CNPUBbits.CNPUB4 = 1; // 1 = pullup enabled on SCL2
                CNPUAbits.CNPUA8 = 1; // 1 = pullup enabled on SDA2
            }
            /* The following code sequence shows master I2C register configuration */  
            I2C2CONbits.I2CEN = 0;  // Turn OFF the I2Cx module

            IFS3bits.MI2C2IF = 0;   // Clear the Interrupt flag
            IEC3bits.MI2C2IE = 0;   // Disable the interrupt

            /********** I2CxCON Register Settings **********/
            I2C2CONbits.I2CSIDL = 0;    // Continue to run while in Idle

            switch (slave_addr_length)
            {
                case bits7 :
                    I2C2CONbits.A10M = 0;       // Using a 7 bits slave address
                    break;
                case bits10 :
                    I2C2CONbits.A10M = 1;       // Using a 10 bits slave address
                    break;
                default :
                    break;
            }

            if(fscl < 400)
            {
                I2C2CONbits.DISSLW = 1; // Slew rate control is disabled
            }
            else
            {
                I2C2CONbits.DISSLW = 0; // Slew rate control is enabled
            }

            /********* I2CxBRG Register Settings **********/ 
            I2C2BRG = genI2CBaudParam(fscl);

            I2C2CONbits.I2CEN = 1;  // Turn ON the I2Cx module

            // Interrupt Controller Settings
            IPC12bits.MI2C2IP = 2;  // Set IRQ priority level
            IFS3bits.MI2C2IF = 0;   // Clear the Interrupt flag
            IEC3bits.MI2C2IE = 1;   // Enable the interrupt  
            break;
            
        default:
            break;
    }   
}

/******************************************************************************/
/*                     I2Cs USER FUNCTIONS Implementation                     */
/******************************************************************************/

/************************************************************************************************
Function Prototype : int8_t MasterWriteI2C(uint8_t eI2Cx, uint8_t data_out)
Description        : This function is used to write out a single data byte to the I2C device
Arguments          : data_out - A single data byte to be written to the I2C bus device
                     eI2Cx - I2C you want to use to send a data byte
Return Value       : This function returns -1 if there was a write collision else it returns a 0
Remarks            : This function writes a single byte to the I2C bus
**************************************************************************************************/
int8_t masterWriteI2C(i2c_t eI2Cx, uint8_t data_out)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1TRN = data_out;
            if(I2C1STATbits.IWCOL)        /* If write collision occurs,return -1 */
                return -1;
            else
            {
                return 0;
            }
		case eI2C2:
            I2C2TRN = data_out;
            if(I2C2STATbits.IWCOL)        /* If write collision occurs,return -1 */
                return -1;
            else
            {
                return 0;
            }
		default:
			break;
    }
}

/******************************************************************************
Function Prototype : uint8_t MasterReadI2C(uint8_t eI2Cx)
Description        : This function is used to read a single byte from I2C bus
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : The return value is the data byte read from the I2C bus
Remarks            : This function reads in a single byte from the I2C bus
********************************************************************************/
uint8_t masterReadI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.RCEN = 1;
            while(I2C1CONbits.RCEN);
            I2C1STATbits.I2COV = 0;
            return(I2C1RCV);
		case eI2C2:
            I2C2CONbits.RCEN = 1;
            while(I2C2CONbits.RCEN);
            I2C2STATbits.I2COV = 0;
            return(I2C2RCV);
		default:
			break;
    }
}

/*********************************************************************
Function Prototype : void StartI2C(uint8_t eI2Cx)
Description        : Generates I2C Bus Start condition.
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : None
Remarks            : This function generates a I2C Bus Start condition
*********************************************************************/
void startI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.SEN = 1;   /* initiate Start on SDA and SCL pins */
		case eI2C2:
            I2C2CONbits.SEN = 1;   /* initiate Start on SDA and SCL pins */
		default:
			break;
    }
}

/*************************************************************************
Function Prototype : void RestartI2C(uint8_t eI2Cx)
Description        : Generates I2C Bus Restart condition
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : None
Remarks            : This function generates an I2C Bus Restart condition
**************************************************************************/
void restartI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.RSEN = 1;   /* initiate restart on SDA and SCL pins */
		case eI2C2:
            I2C2CONbits.RSEN = 1;   /* initiate restart on SDA and SCL pins */
		default:
			break;
    }
}


/*********************************************************************
Function Prototype : void StopI2C(uint8_t eI2Cx)
Description        : Generates I2C Bus Stop condition
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : None
Remarks            : This function generates a I2C Bus Stop condition
*********************************************************************/
void stopI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.PEN = 1;   /* initiate Stop on SDA and SCL pins */
		case eI2C2:
            I2C2CONbits.PEN = 1;   /* initiate Stop on SDA and SCL pins */
		default:
			break;
    }
}

/*********************************************************************
Function Prototype  : void AckI2C(uint8_t eI2Cx)
Description         : Generates I2C bus Acknowledge condition
Arguments           : eI2Cx - I2C you want to use to send a data byte
Return Value        : None
Remarks             : This function generates an I2C bus Acknowledge condition
*********************************************************************/
void ackI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.ACKDT = 0;
            I2C1CONbits.ACKEN = 1;
		case eI2C2:
            I2C2CONbits.ACKDT = 0;
            I2C2CONbits.ACKEN = 1;
		default:
			break;
    }
}


/*********************************************************************************
Function Prototype : void NotAckI2C(uint8_t eI2Cx)
Description        : Generates I2C bus Not Acknowledge condition during Master Receive
Arguments          : I2Cx - I2C you want to use to send a data byte
Return Value       : None
Remarks            : This function generates an I2C bus Not Acknowledge condition
**********************************************************************************/
void notAckI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            I2C1CONbits.ACKDT = 1;
            I2C1CONbits.ACKEN = 1;
		case eI2C2:
            I2C2CONbits.ACKDT = 1;
            I2C2CONbits.ACKEN = 1;
		default:
			break;
    }
}

/************************************************************************************************
Function Prototype : void IdleI2C(uint8_t eI2Cx)
Description        : This function generates Wait condition until I2C bus is Idle
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : None
Remarks            : This function will be in a wait state until Start Condition Enable bit,
                     Stop Condition Enable bit, Receive Enable bit, Acknowledge Sequence
                     Enable bit of I2C Control register and Transmit Status bit I2C Status
                     register are clear. The IdleI2C function is required since the hardware
                     I2C peripheral does not allow for spooling of bus sequence. The I2C
                     peripheral must be in Idle state before an I2C operation can be initiated
                     or write collision will be generated
*****************************************************************************************************/
void idleI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            /* Wait until I2C Bus is Inactive */
            while(I2C1CONbits.SEN || I2C1CONbits.RSEN || I2C1CONbits.PEN || I2C1CONbits.RCEN ||
                  I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
		case eI2C2:
            /* Wait until I2C Bus is Inactive */
            while(I2C2CONbits.SEN || I2C2CONbits.RSEN || I2C2CONbits.PEN || I2C2CONbits.RCEN ||
                  I2C2CONbits.ACKEN || I2C2STATbits.TRSTAT);
		default:
			break;
    }
}

/************************************************************************
Function Prototype : uint8_t DataRdyI2C(uint8_t eI2Cx)
Description        : This function provides status back to user if I2CRCV
                     register contain data
Arguments          : eI2Cx - I2C you want to use to send a data byte
Return Value       : This function returns "1" if there is data in I2CRCV register;
                     else return "0" which indicates no data in I2CRCV register
Remarks            : This function determines if there is any byte to read from
                     I2CRCV register.
*************************************************************************/
uint8_t dataRdyI2C(i2c_t eI2Cx)
{
	switch(eI2Cx)
	{
		case eI2C1:
            return I2C1STATbits.RBF;
		case eI2C2:
            return I2C2STATbits.RBF;
		default:
			break;
    }
}

/******************************************************************************/
/*                        I2C Interrupt Routines (IRQ)                        */
/******************************************************************************/
void i2cInterruptEnable(i2c_t eI2Cx){
    
    switch (eI2Cx)
    {
        case eI2C1:
                IFS1bits.MI2C1IF = 0;   // Clear the Interrupt flag
                IEC1bits.MI2C1IE = 1;   // Enable the interrupt  
            break;
        case eI2C2:
                IFS3bits.MI2C2IF = 0;   // Clear the Interrupt flag
                IEC3bits.MI2C2IE = 1;   // Enable the interrupt  
            break;
        default:
            break;
    }
}

void i2cInterruptDisable(i2c_t eI2Cx){
    
    switch (eI2Cx)
    {
        case eI2C1:
                IEC1bits.MI2C1IE = 0;   // Disable the interrupt  
                IFS1bits.MI2C1IF = 0;   // Clear the Interrupt flag
            break;
        case eI2C2:
                IEC3bits.MI2C2IE = 0;   // Disable the interrupt  
                IFS3bits.MI2C2IF = 0;   // Clear the Interrupt flag
            break;
        default:
            break;
    }    
}

//Callback register function
void registerI2CxCallback(i2c_t eI2Cx, Callback_t cbf_pointer)
{
    switch (eI2Cx)
    {
        case eI2C1:
            cbf_i2c1_pointer = cbf_pointer;
            break;
        case eI2C2:
            cbf_i2c2_pointer = cbf_pointer;
            break;
        default:
            break;
    }
}
//Master I2C1 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _MI2C1Interrupt(void)
{
  IFS1bits.MI2C1IF = 0;   // Clear the master Interrupt flag
  if (0!=cbf_i2c1_pointer)
  {
    cbf_i2c1_pointer();
  }    
}

//Master I2C2 interrupt
/// @private
void __attribute__((__interrupt__, __auto_psv__)) _MI2C2Interrupt(void)
{
  IFS3bits.MI2C2IF = 0;   // Clear the master Interrupt flag
  if (0!=cbf_i2c2_pointer)
  {
    cbf_i2c2_pointer();
  }    
}

/******************************************************************************/
/*                    LIBRARY USED FUNCTION Implementation                    */
/******************************************************************************/
/// @private
uint16_t genI2CBaudParam(uint16_t fscl)
{
    uint16_t BRGVAL;
    
    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    uint32_t M = (uint32_t)(PLLFBD + 2);
    uint32_t N1 = (uint32_t)(2*(CLKDIVbits.PLLPOST + 1));
    uint32_t N2 = (uint32_t)(CLKDIVbits.PLLPRE + 2);
	
    uint32_t Fosc = (uint32_t)(7370000UL*M/(N1*N2));
    uint32_t Fcy = Fosc >> 1;

    // Calculation of I2C serial clock:
    // I2CxBRG = (((1/fscl)-Pulse Gobbler Delay)*fcy)-1
    // I2CxBRG = (((1/fscl)-390ns)*fcy)-1
    float BRGVAL_f = (((1.0/(fscl*1000.0)-390.0E-9)*Fcy)-1);
    
    if (BRGVAL_f <= 0.0)
    {
        BRGVAL = 0x0000;    // Min BRG value
    }
    else if (BRGVAL_f >= 0x01FF)
    {
        BRGVAL = 0x01FF;    // Max BRG value
    }
    else
    {
        BRGVAL = (uint16_t)BRGVAL_f;
    }
    
	return BRGVAL;
}