/*
 * RovePermaMem.h
 *
 *  Created on: Oct 20, 2017
 *      Author: drue
 */

#ifndef ROVEBOARD_STANDARDIZED_API_ROVEPERMAMEM_H_
#define ROVEBOARD_STANDARDIZED_API_ROVEPERMAMEM_H_

#include <stdint.h>

typedef enum
{
  RovePermaMem_Success,
  RovePermaMem_InputOutOfBounds,
  RovePermaMem_ImproperPassword,
  RovePermaMem_AlreadyUsed,
  RovePermaMem_BlockNotAllocated
} RovePermaMem_Error;

typedef struct
{
  uint16_t blockReference;
  uint16_t password;
} RovePermaMem_Block;

extern RovePermaMem_Error rovePermaMem_WriteBlockByte(RovePermaMem_Block blockHandle, uint8_t byteReference, uint8_t valueToWrite);
extern RovePermaMem_Error rovePermaMem_WriteBlock(RovePermaMem_Block blockHandle, uint8_t bytes[]);
extern RovePermaMem_Error rovePermaMem_ReadBlockByte(RovePermaMem_Block blockHandle, uint8_t byteReference, uint8_t *readBuffer);
extern RovePermaMem_Error rovePermaMem_ReadBlock(RovePermaMem_Block blockHandle, uint8_t byteBuffer[]);

extern RovePermaMem_Block rovePermaMem_useBlock(uint16_t blockReference, uint16_t passwordToUse);
extern bool rovePermaMem_getFirstAvailableBlock(bool onlyGetFreshBlocks, uint16_t startingBlock, uint16_t* ret_blockReference);

extern uint16_t rovePermaMem_getTotalUsedBlocks();
extern uint16_t rovePermaMem_getTotalUnusedBlocks();
extern uint16_t rovePermaMem_getTotalFreshBlocks();

extern uint16_t rovePermaMem_getBytesPerBlock();
extern uint16_t rovePermaMem_getTotalBlocks();

extern RovePermaMem_Error rovePermaMem_isBlockUsed(uint16_t blockReference, bool *retVal);
extern RovePermaMem_Error rovePermaMem_isBlockFresh(uint16_t blockReference, bool *retVal);

#endif /* ROVEBOARD_STANDARDIZED_API_ROVEPERMAMEM_H_ */