/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_SERVER_IN_H
#define RELAY_SERIALIZE_SERVER_IN_H

#include <relay-serialize/commands.h>
#include <relay-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;

int relaySerializeServerInLogin(struct FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                                RelaySerializeServerChallenge* serverChallenge, char* target, size_t maxTarget);

int relaySerializeServerInChallenge(struct FldInStream* inStream, RelaySerializeClientNonce* clientNonce);

int relaySerializeServerInRequestConnect(struct FldInStream* inStream,
                                         RelaySerializeConnectRequestFromClientToServer* request);

int relaySerializeServerInRequestListen(struct FldInStream* inStream,
                                         RelaySerializeListenRequestFromClientToServer* request);

int relaySerializeServerInRequestAccept(struct FldInStream* inStream,
                                        RelaySerializeListenRequestFromClientToServer* request);

#endif
