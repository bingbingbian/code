/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CAN1.h
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : FreescaleCAN
**     Version   : Component 02.356, Driver 01.30, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2017/3/23, 21:47
**     Abstract  :
**         This component "FreescaleCAN" implements a CAN serial channel.
**     Comment   :
**         For Charge CAN
**     Settings  :
**         CAN channel                 : MSCAN1
**
**         Protocol
**             Interrupt priority      : 4
**             Time segment 1          : 11
**             Time segment 2          : 2
**             RSJ                     : 0
**
**             Recieve accept. code    : 0x00
**             Recieve accept. mask    : 0xFFFFFFFF
**
**         Input interrupt
**             Vector name             : Vcan1rx
**             Priority                : 4
**
**         Output interrupt
**             Vector name             : Vcan1tx
**             Priority                : 4
**
**     Contents  :
**         Enable            - byte CAN1_Enable(void);
**         Disable           - byte CAN1_Disable(void);
**         EnableEvent       - byte CAN1_EnableEvent(void);
**         DisableEvent      - byte CAN1_DisableEvent(void);
**         SetAcceptanceCode - byte CAN1_SetAcceptanceCode(dword AccCode1, dword AccCode2);
**         SetAcceptanceMask - byte CAN1_SetAcceptanceMask(dword AccMask1, dword AccMask2);
**         SetAcceptanceMode - byte CAN1_SetAcceptanceMode(byte Mode);
**         SendFrame         - byte CAN1_SendFrame(byte BufferNum, dword MessageID, byte FrameType, byte...
**         ReadFrame         - byte CAN1_ReadFrame(dword *MessageID, byte *FrameType, byte *FrameFormat,...
**         GetStateTX        - byte CAN1_GetStateTX(void);
**         GetStateRX        - bool CAN1_GetStateRX(void);
**         GetError          - byte CAN1_GetError(CAN1_TError *Err);
**         SendFrameExt      - byte CAN1_SendFrameExt(dword MessageID, byte FrameType, byte Length, byte...
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __CAN1
#define __CAN1

#include "Cpu.h"

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE CAN1. */

#ifndef __BWUserType_CAN1_TError
#define __BWUserType_CAN1_TError
/*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
  typedef union {
    word err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      bool OverRun : 1;                /* Overrun error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Idle : 1;                   /* Idle character detect */
      bool BusOff : 1;                 /* Bus-off state */
      bool TxPassive : 1;              /* Transmitter error passive */
      bool RxPassive : 1;              /* Reciver error passive */
      bool TxWarning : 1;              /* Transmitter warning */
      bool RxWarning : 1;              /* Receiver warning */
      bool Ack : 1;                    /* Acknowledge error */
      bool Crc : 1;                    /* CRC error */
      bool Form : 1;                   /* Form error */
      bool Stuff : 1;                  /* Stuff bit error */
      bool Bit0 : 1;                   /* Bit 0 error */
      bool Bit1 : 1;                   /* Bit 1 error */
      bool : 1;                        /* Unused, just pad */
      bool : 1;                        /* Unused, just pad */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    }errName;
  } CAN1_TError;                       /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
/*lint -restore  +esym(961,18.4) Enable MISRA rule (18.4) checking. */
#endif

#pragma DATA_SEG CAN1_DATA             /* Select data segment "CAN1_DATA" */
#pragma CODE_SEG CAN1_CODE

/* User constants */

/* Message filterring */
#define TWO_32_FILTERS                  0x00U
#define FOUR_16_FILTERS                 0x01U
#define EIGHT_8_FILTERS                 0x02U
#define FILTER_CLOSED                   0x03U

/* Frame formats */
#define STANDARD_FORMAT                 0x00U
#define EXTENDED_FORMAT                 0x01U

/* Frame types   */
#define DATA_FRAME                      0x00U
#define REMOTE_FRAME                    0x01U

/* Extended message ID identifier.  This constant can be used to specify an extended message ID
 * anywhere the message ID is required.
 */
#define CAN_EXTENDED_FRAME_ID           0x80000000UL       /* Extended message ID identifier */

/* Global variables */
extern volatile bool CAN1_EnEvent;     /* Enable/Disable events */

byte CAN1_SendFrameExt(dword MessageID,byte FrameType,byte Length,const byte *Data);
/*
** ===================================================================
**     Method      :  CAN1_SendFrameExt (component FreescaleCAN)
**
**     Description :
**         Sends a frame. This method automatically selects a free
**         transmit buffer for data transmission. The user cannot
**         specify a transmit buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         MessageID       - Identification of the
**                           message - ID. Message ID can be
**                           specified in the STANDARD format
**                           (default) or the EXTENDED format. The
**                           most significant bit in the ID is set to
**                           specify EXTENDED format. Predefined
**                           macro CAN_EXTENDED_FRAME_ID can be used
**                           (ID "bitwise or" CAN_EXTENDED_FRAME_ID)
**                           to mark ID as extended. If the most
**                           significant bit of ID is clear, STANDARD
**                           format is used.
**         FrameType       - Type of frame
**                           DATA_FRAME - data frame
**                           REMOTE_FRAME - remote frame
**         Length          - The length of the frame in bytes
**                           (0..8)
**       * Data            - Pointer to data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
**                           ERR_VALUE - Some parameter is out of
**                           possible range
** ===================================================================
*/

#define CAN1_DisableEvent() (CAN1_EnEvent = FALSE , ERR_OK)
/*
** ===================================================================
**     Method      :  CAN1_DisableEvent (component FreescaleCAN)
**
**     Description :
**         Disables the events. This method is available if the
**         interrupt service/event property is enabled and at least
**         one event is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define CAN1_EnableEvent()\
                              (CAN1_EnEvent = TRUE , ERR_OK)
/*
** ===================================================================
**     Method      :  CAN1_EnableEvent (component FreescaleCAN)
**
**     Description :
**         Enables the events. This method is available if the
**         interrupt service/event property is enabled and at least
**         one event is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte CAN1_SetAcceptanceMode(byte Mode);
/*
** ===================================================================
**     Method      :  CAN1_SetAcceptanceMode (component FreescaleCAN)
**
**     Description :
**         Sets the acceptance mode register.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Mode            - Acceptance mode.
**                           Supported modes: 
**                           TWO_32_FILTERS - Two 32-bit acceptance
**                           filters
**                           FOUR_16_FILTERS - Four 16-bit acceptance
**                           filters
**                           EIGHT_8_FILTERS - Eight 8-bit acceptance
**                           filters
**                           FILTER_CLOSED - Filter closed
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
**                           ERR_VALUE - Parameter has incorrect value
** ===================================================================
*/

byte CAN1_GetStateRX(void);
/*
** ===================================================================
**     Method      :  CAN1_GetStateRX (component FreescaleCAN)
**
**     Description :
**         Returns a value of the reception complete flag.
**     Parameters  : None
**     Returns     :
**         ---             - The value of the receiver complete flag
**                           of the given buffer. 
**                           Possible values:
**                           FALSE - message buffer is empty
**                           TRUE - message buffer isn't empty
** ===================================================================
*/

byte CAN1_SetAcceptanceCode(dword AccCode1, dword AccCode2);
/*
** ===================================================================
**     Method      :  CAN1_SetAcceptanceCode (component FreescaleCAN)
**
**     Description :
**         Sets the acceptance code registers. This method writes a
**         code mask directly to the acceptance code registers.
**     Parameters  :
**         NAME            - DESCRIPTION
**         AccCode1        - Acceptance code for the
**                           message filtering. This acceptance code
**                           will be written to the acceptance code
**                           registers IDAR0-IDAR3. The most
**                           significant byte of the acceptance code
**                           will be written to the IDAR0 register
**                           and the least significant byte of the
**                           acceptance code will be written to the
**                           IDAR3 register.
**         AccCode2        - Acceptance code for the
**                           message filtering. This acceptance code
**                           will be written to the acceptance code
**                           registers IDAR4-IDAR7. The most
**                           significant byte of the acceptance code
**                           will be written to the IDAR4 register
**                           and the least significant byte of the
**                           acceptance code will be written to the
**                           IDAR7 register.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
** ===================================================================
*/

byte CAN1_GetError(CAN1_TError *Err);
/*
** ===================================================================
**     Method      :  CAN1_GetError (component FreescaleCAN)
**
**     Description :
**         Returns the content of the receiver flag register.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Err             - Pointer to the returned set of errors
**     Returns     :
**         ---             - Error code (if GetError did not succeed),
**                           possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte CAN1_SendFrame(byte BufferNum,dword MessageID,byte FrameType,byte Length,const byte *Data);
/*
** ===================================================================
**     Method      :  CAN1_SendFrame (component FreescaleCAN)
**
**     Description :
**         Sends the frame via the CAN device. Using this method the
**         user can send own message to the CAN bus. This method
**         allows to specify CAN buffer number, message ID, data to
**         be sent and frame type (DATA_FRAME/REMOTE_FRAME).
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferNum       - Number of the buffer.
**         MessageID       - Identification of the
**                           message - ID. Message ID can be
**                           specified in the STANDARD format
**                           (default) or the EXTENDED format. The
**                           most significant bit in the ID is set to
**                           specify EXTENDED format. Predefined
**                           macro CAN_EXTENDED_FRAME_ID can be used
**                           (ID "bitwise or" CAN_EXTENDED_FRAME_ID)
**                           to mark ID as extended. If the most
**                           significant bit of ID is clear, STANDARD
**                           format is used.
**         FrameType       - Type of frame
**                           DATA_FRAME - data frame
**                           REMOTE_FRAME - remote frame
**         Length          - The length of the frame in bytes
**                           (0..8)
**       * Data            - Pointer to data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
**                           ERR_VALUE - Some parameter is out of
**                           possible range
**                           ERR_TXFULL - Transmition buffer is full.
** ===================================================================
*/

byte CAN1_ReadFrame(dword *MessageID, byte *FrameType, byte *FrameFormat, byte *Length, byte *Data);
/*
** ===================================================================
**     Method      :  CAN1_ReadFrame (component FreescaleCAN)
**
**     Description :
**         Reads a frame from the CAN device. The user is informed
**         about CAN reception through OnFullRxBuffer event or
**         GetStateRX method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * MessageID       - Pointer to a message
**                           indentification
**       * FrameType       - Pointer to a frame type
**                           DATA_FRAME - data frame
**                           REMOTE_FRAME - remote frame
**       * FrameFormat     - Pointer to a frame
**                           format
**                           STANDARD_FORMAT - standard frame 11-bits
**                           EXTENDED_FORMAT - extended frame 29-bits.
**                           Note: This parameter is obsolete and
**                           will be removed in future releases.
**       * Length          - Pointer to a length of the frame
**       * Data            - The buffer for received data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
**                           ERR_RXEMPTY - The receive buffer is
**                           empty
**                           ERR_OVERRUN - The previous (unread)
**                           message in the receive buffer was
**                           overwriten by a new message. Returns
**                           only if Interrupt service is enabled.
** ===================================================================
*/

void CAN1_Init(void);
/*
** ===================================================================
**     Method      :  CAN1_Init (component FreescaleCAN)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#define CAN1_GetStateTX()  (CAN1TFLG & 0x07U)
/*
** ===================================================================
**     Method      :  CAN1_GetStateTX (component FreescaleCAN)
**
**     Description :
**         Returns a value of the transmission complete flags.
**     Parameters  : None
**     Returns     :
**         ---             - Content of the transmitter complete
**                           flag register.
** ===================================================================
*/

byte CAN1_Enable(void);
/*
** ===================================================================
**     Method      :  CAN1_Enable (component FreescaleCAN)
**
**     Description :
**         Enables the component - it turns on the send and receive
**         functions. Events may be generated
**         ("DisableEvent"/"EnableEvent").
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte CAN1_Disable(void);
/*
** ===================================================================
**     Method      :  CAN1_Disable (component FreescaleCAN)
**
**     Description :
**         Disables the component - it stops the send and receive
**         functions. No events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte CAN1_SetAcceptanceMask(dword AccMask1, dword AccMask2);
/*
** ===================================================================
**     Method      :  CAN1_SetAcceptanceMask (component FreescaleCAN)
**
**     Description :
**         Sets the acceptance mask registers. This method writes an
**         acceptance mask directly to the acceptance mask registers.
**     Parameters  :
**         NAME            - DESCRIPTION
**         AccMask1        - Acceptance mask for the
**                           message filtering. This acceptance mask
**                           will be written to the acceptance mask
**                           registers IDMR0-IDMR3. The most
**                           significant byte of the acceptance mask
**                           will be written to the IDMR0 register
**                           and the least significant byte of the
**                           acceptance mask will be written to the
**                           IDMR3 register.
**         AccMask2        - Acceptance mask for the
**                           message filtering. This acceptance mask
**                           will be written to the acceptance mask
**                           registers IDMR4-IDMR7. The most
**                           significant byte of the acceptance mask
**                           will be written to the IDMR4 register
**                           and the least significant byte of the
**                           acceptance mask will be written to the
**                           IDMR7 register.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled by
**                           user
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void CAN1_InterruptTx(void);
#pragma CODE_SEG CAN1_CODE
/*
** ===================================================================
**     Method      :  CAN1_InterruptTx (component FreescaleCAN)
**
**     Description :
**         The method services the transmit interrupt of the selected 
**         peripheral(s) and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void CAN1_InterruptRx(void);
#pragma CODE_SEG CAN1_CODE
/*
** ===================================================================
**     Method      :  CAN1_InterruptRx (component FreescaleCAN)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void CAN1_InterruptError(void);
#pragma CODE_SEG CAN1_CODE
/*
** ===================================================================
**     Method      :  CAN1_InterruptError (component FreescaleCAN)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/



#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */
#pragma CODE_SEG DEFAULT

/* END CAN1. */

#endif /* ifndef __CAN1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
