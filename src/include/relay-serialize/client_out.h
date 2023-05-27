/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_H
#define RELAY_SERIALIZE_H

#include <relay-serialize/commands.h>
#include <relay-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int relaySerializeClientOutChallenge(struct FldOutStream* stream, RelaySerializeClientNonce clientNonce);
int relaySerializeClientOutLogin(struct FldOutStream* stream, RelaySerializeClientNonce clientNonce,
                               RelaySerializeServerChallenge challenge, const char* name);

#endif
