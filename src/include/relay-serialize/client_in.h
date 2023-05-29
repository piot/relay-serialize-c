/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_CLIENT_IN_H
#define RELAY_SERIALIZE_CLIENT_IN_H

#include <relay-serialize/commands.h>
#include <relay-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;

int relaySerializeClientInChallenge(struct FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                                  RelaySerializeServerChallenge* serverChallenge);
int relaySerializeClientInLogin(struct FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                              RelaySerializeUserSessionId* userSessionId);


int relaySerializeClientInConnectRequestToListener(struct FldInStream* inStream,
                                                      RelaySerializeConnectRequestFromServerToListener* data);

int relaySerializeClientInPacketFromServer(struct FldInStream* inStream,
                                                      RelaySerializeServerPacketFromServerToClient* data);

#endif
