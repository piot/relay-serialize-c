/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef RELAY_SERIALIZE_SERIALIZE_H
#define RELAY_SERIALIZE_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>

#include <relay-serialize/types.h>

struct FldOutStream;
struct FldInStream;

void relaySerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix);

void relaySerializeWriteUserSessionId(struct FldOutStream* outStream, RelaySerializeUserSessionId userSessionId);
int relaySerializeReadUserSessionId(struct FldInStream* stream, RelaySerializeUserSessionId* userSessionId);

void relaySerializeWriteClientNonce(struct FldOutStream* outStream, RelaySerializeClientNonce clientNonce);
int relaySerializeReadClientNonce(struct FldInStream* stream, RelaySerializeClientNonce* clientNonce);

void relaySerializeWriteServerChallenge(struct FldOutStream* outStream, RelaySerializeServerChallenge serverChallenge);
int relaySerializeReadServerChallenge(struct FldInStream* stream, RelaySerializeServerChallenge* serverChallenge);

int relaySerializeWriteString(struct FldOutStream* stream, const char* s);
int relaySerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength);

#endif
