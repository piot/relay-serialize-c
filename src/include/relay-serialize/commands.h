/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_COMMANDS_H
#define RELAY_SERIALIZE_COMMANDS_H

#include <stdint.h>

// TODO: change to extern.

// Requests
#define relaySerializeCmdNop (0x00)

#define relaySerializeCmdLogin (0x02)
#define relaySerializeCmdPacket (0x05)
#define relaySerializeCmdConnectRequestToServer (0x06)
#define relaySerializeCmdListenRequestToServer (0x07)
#define relaySerializeCmdChallenge (0x0A)

// Responses
#define relaySerializeCmdLoginResponse (0x22)
#define relaySerializeCmdPacketToClient (0x24)
#define relaySerializeCmdConnectionRequestToClient (0x25)
#define relaySerializeCmdListenResponseToClient (0x26)
#define relaySerializeCmdConnectResponseToClient (0x27)
#define relaySerializeCmdChallengeResponse (0x2A)

#endif
