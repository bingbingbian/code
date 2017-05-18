/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LTC_CS.c
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
**                       142           |  PP6_KWP6_PWM6_SS2_TIMIOC6
**             ----------------------------------------------------
**
**         Port name                   : P
**
**         Bit number (in port)        : 6
**         Bit mask of the port        : $0040
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : PTP       [$0258]
**         Port control register       : DDRP      [$025A]
**
**         Optimization for            : speed
**     Contents  :
**         PutVal - void LTC_CS_PutVal(bool Val);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE LTC_CS. */

#include "LTC_CS.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG LTC_CS_DATA           /* Select data segment "LTC_CS_DATA" */
#pragma CODE_SEG LTC_CS_CODE
#pragma CONST_SEG LTC_CS_CONST         /* Constant section for this module */
/*
** ===================================================================
**     Method      :  LTC_CS_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void LTC_CS_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTP, 0x40U);           /* PTP6=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTP, 0x40U);           /* PTP6=0x00U */
  } /* !Val */
}


/* END LTC_CS. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
