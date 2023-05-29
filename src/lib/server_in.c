/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <relay-serialize/serialize.h>
#include <relay-serialize/server_in.h>

int relaySerializeServerInLogin(FldInStream* inStream, RelaySerializeClientNonce* clientNonce,
                                RelaySerializeServerChallenge* serverChallenge, char* target, size_t maxTarget)
{
    relaySerializeReadClientNonce(inStream, clientNonce);
    relaySerializeReadServerChallenge(inStream, serverChallenge);
    relaySerializeReadString(inStream, target, maxTarget);

    return 0;
}

int relaySerializeServerInChallenge(FldInStream* inStream, RelaySerializeClientNonce* clientNonce)
{
    return relaySerializeReadClientNonce(inStream, clientNonce);
}

int relaySerializeServerInRequestConnect(struct FldInStream* inStream,
                                         RelaySerializeConnectRequestFromClientToServer* request)
{
    relaySerializeReadApplicationId(inStream, &request->appId);
    relaySerializeReadUserId(inStream, &request->userId);
    relaySerializeReadChannelId(inStream, &request->channelId);
    return relaySerializeReadRequestId(inStream, &request->requestId);
}

int relaySerializeServerInRequestListen(struct FldInStream* inStream,
                                        RelaySerializeListenRequestFromClientToServer* request)
{
    relaySerializeReadApplicationId(inStream, &request->appId);
    relaySerializeReadChannelId(inStream, &request->channelId);
    return relaySerializeReadRequestId(inStream, &request->requestId);
}
