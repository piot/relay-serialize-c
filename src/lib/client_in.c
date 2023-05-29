/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <relay-serialize/client_in.h>
#include <relay-serialize/serialize.h>

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

int relaySerializeClientInConnectRequestToListener(struct FldInStream* inStream,
                                                   RelaySerializeConnectRequestFromServerToListener* data)
{
    relaySerializeReadConnectionId(inStream, &data->assignedConnectionId);
    relaySerializeReadApplicationId(inStream, &data->appId);
    relaySerializeReadChannelId(inStream, &data->channelId);
    relaySerializeReadUserId(inStream, &data->fromUserId);
    return relaySerializeReadRequestId(inStream, &data->debugRequestId);
}

int relaySerializeClientInPacketFromServer(struct FldInStream* inStream,
                                           RelaySerializeServerPacketFromServerToClient* data)
{
    relaySerializeReadConnectionId(inStream, &data->connectionId);
    return fldInStreamReadUInt16(inStream, &data->packetOctetCount);
}
