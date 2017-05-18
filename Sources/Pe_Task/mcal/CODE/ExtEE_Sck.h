/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ExtEE_Sck.h
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2017/3/23, 21:47
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       128           |  PJ7_KWJ7_TxCAN4_SCL0_TxCAN0
**             ----------------------------------------------------
**
**         Port name                   : J
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTJ       [$0268]
**         Port control register       : DDRJ      [$026A]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool ExtEE_Sck_GetVal(void);
**         ClrVal - void ExtEE_Sck_ClrVal(void);
**         SetVal - void ExtEE_Sck_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef ExtEE_Sck_H_
#define ExtEE_Sck_H_

/* MODULE ExtEE_Sck. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG ExtEE_Sck_CODE
/*
** ===================================================================
**     Method      :  ExtEE_Sck_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define ExtEE_Sck_GetVal() ( \
    (bool)((getReg8(PTJ) & 0x80U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  ExtEE_Sck_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define ExtEE_Sck_ClrVal() ( \
    (void)clrReg8Bits(PTJ, 0x80U)      /* PTJ7=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  ExtEE_Sck_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define ExtEE_Sck_SetVal() ( \
    (void)setReg8Bits(PTJ, 0x80U)      /* PTJ7=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END ExtEE_Sck. */
#endif /* #ifndef __ExtEE_Sck_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
