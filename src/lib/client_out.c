/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <relay-serialize/client_out.h>
#include <relay-serialize/serialize.h>

int relaySerializeClientOutRequestConnect(struct FldOutStream* outStream,
                                          const RelaySerializeConnectRequestFromClientToServer* request)
{
    relaySerializeWriteApplicationId(outStream, request->appId);
    relaySerializeWriteUserSessionId(outStream, request->userSessionId);
    relaySerializeWriteChannelId(outStream, request->channelId);
    relaySerializeWriteRequestId(outStream, request->requestId);

    return 0;
}

int relaySerializeClientOutRequestListen(struct FldOutStream* outStream,
                                         const RelaySerializeListenRequestFromClientToServer* request)
{
    relaySerializeWriteApplicationId(outStream, request->appId);
    relaySerializeWriteChannelId(outStream, request->channelId);
    relaySerializeWriteUserSessionId(outStream, request->userSessionId);
    relaySerializeWriteRequestId(outStream, request->requestId);

    return 0;
}
