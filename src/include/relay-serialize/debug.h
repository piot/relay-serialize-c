/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_DEBUG_H
#define RELAY_SERIALIZE_DEBUG_H

#include <stdint.h>
#include <stdlib.h>

// void relaySerializeDebugHex(const char* debug, const uint8_t* data, size_t length);
const char* relaySerializeCmdToString(uint8_t t);

#endif
