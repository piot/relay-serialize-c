/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <relay-serialize/client_out.h>
#include <relay-serialize/serialize.h>
#include <flood/out_stream.h>
#include <tiny-libc/tiny_libc.h>

#define COMMAND_DEBUG "ClientOut"

int relaySerializeClientOutLogin(FldOutStream* stream, RelaySerializeClientNonce clientNonce,
                               RelaySerializeServerChallenge challenge, const char* name)
{
    relaySerializeWriteCommand(stream, relaySerializeCmdLogin, COMMAND_DEBUG);
    relaySerializeWriteClientNonce(stream, clientNonce);
    relaySerializeWriteServerChallenge(stream, challenge);
    relaySerializeWriteString(stream, name);

    return 0;
}

int relaySerializeClientOutChallenge(FldOutStream* stream, RelaySerializeClientNonce clientNonce)
{
    relaySerializeWriteCommand(stream, relaySerializeCmdChallenge, COMMAND_DEBUG);
    relaySerializeWriteClientNonce(stream, clientNonce);

    return 0;
}
