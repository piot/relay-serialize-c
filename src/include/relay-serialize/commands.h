/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/relay-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_COMMANDS_H
#define RELAY_SERIALIZE_COMMANDS_H

#include <stdint.h>

// TODO: change to extern.

// Requests
#define relaySerializeCmdPacket (0x05)
#define relaySerializeCmdConnectRequestToServer (0x06)
#define relaySerializeCmdListenRequestToServer (0x07)

// Responses
#define relaySerializeCmdPacketToClient (0x24)
#define relaySerializeCmdConnectionRequestToClient (0x25)
#define relaySerializeCmdListenResponseToClient (0x26)
#define relaySerializeCmdConnectResponseToClient (0x27)

#endif
