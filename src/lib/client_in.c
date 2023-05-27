/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <relay-serialize/client_in.h>
#include <relay-serialize/serialize.h>
#include <flood/in_stream.h>
#include <tiny-libc/tiny_libc.h>


int relaySerializeClientInChallenge(FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                                  RelaySerializeServerChallenge* serverChallenge)
{
    relaySerializeReadClientNonce(inStream, clientNonce);

    return relaySerializeReadServerChallenge(inStream, serverChallenge);
}

int relaySerializeClientInLogin(struct FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                              RelaySerializeUserSessionId* userSessionId)
{
    relaySerializeReadClientNonce(inStream, clientNonce);

    return relaySerializeReadUserSessionId(inStream, userSessionId);
}
