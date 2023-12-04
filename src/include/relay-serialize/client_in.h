/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/relay-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_CLIENT_IN_H
#define RELAY_SERIALIZE_CLIENT_IN_H

#include <relay-serialize/commands.h>
#include <relay-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;

int relaySerializeClientInConnectRequestToListener(struct FldInStream* inStream,
                                                   RelaySerializeConnectRequestFromServerToListener* data);
int relaySerializeClientInPacketFromServer(struct FldInStream* inStream,
                                           RelaySerializeServerPacketFromServerToClient* data);
int relaySerializeClientInListenResponse(struct FldInStream* inStream,
                                         RelaySerializeListenResponseFromServerToListener* data);
int relaySerializeClientInConnectResponse(struct FldInStream* inStream,
                                          RelaySerializeConnectResponseFromServerToClient* data);
int relaySerializeClientInPacketHeader(struct FldInStream* inStream, RelaySerializeServerPacketFromServerToClient* data);

#endif
