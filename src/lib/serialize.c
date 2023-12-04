/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/relay-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <flood/in_stream.h>
#include <flood/out_stream.h>
#include <relay-serialize/serialize.h>

void relaySerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix)
{
    (void) prefix;
    // CLOG_VERBOSE("%s: cmd: %s", prefix, relaySerializeCmdToString(cmd));
    fldOutStreamWriteUInt8(outStream, cmd);
}

void relaySerializeWriteUserSessionId(struct FldOutStream* stream, RelaySerializeUserSessionId userSessionId)
{
    if (userSessionId == 0) {
        CLOG_ERROR("userSessionId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x86);
    fldOutStreamWriteUInt64(stream, userSessionId);
}

int relaySerializeReadUserSessionId(struct FldInStream* stream, RelaySerializeUserSessionId* userSessionId)
{
    fldInStreamCheckMarker(stream, 0x86);
    return fldInStreamReadUInt64(stream, userSessionId);
}

void relaySerializeWriteUserId(struct FldOutStream* stream, RelaySerializeUserId userId)
{
    if (userId == 0) {
        CLOG_ERROR("userId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x89);
    fldOutStreamWriteUInt64(stream, userId);
}

int relaySerializeReadUserId(struct FldInStream* stream, RelaySerializeUserId* userId)
{
    fldInStreamCheckMarker(stream, 0x89);
    return fldInStreamReadUInt64(stream, userId);
}

void relaySerializeWriteConnectionId(struct FldOutStream* stream, RelaySerializeConnectionId connectionId)
{
    if (connectionId == 0) {
        CLOG_ERROR("userId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x90);
    fldOutStreamWriteUInt64(stream, connectionId);
}

int relaySerializeReadConnectionId(struct FldInStream* stream, RelaySerializeConnectionId* connectionId)
{
    fldInStreamCheckMarker(stream, 0x90);
    return fldInStreamReadUInt64(stream, connectionId);
}

void relaySerializeWriteListenerId(struct FldOutStream* stream, RelaySerializeListenerId listenerId)
{
    if (listenerId == 0) {
        CLOG_ERROR("listenerId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x91);
    fldOutStreamWriteUInt64(stream, listenerId);
}

int relaySerializeReadListenerId(struct FldInStream* stream, RelaySerializeListenerId* listenerId)
{
    fldInStreamCheckMarker(stream, 0x91);
    return fldInStreamReadUInt64(stream, listenerId);
}

void relaySerializeWriteApplicationId(struct FldOutStream* stream, RelaySerializeApplicationId applicationId)
{
    if (applicationId == 0) {
        CLOG_ERROR("listenerId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x92);
    fldOutStreamWriteUInt64(stream, applicationId);
}

int relaySerializeReadApplicationId(struct FldInStream* stream, RelaySerializeApplicationId* applicationId)
{
    fldInStreamCheckMarker(stream, 0x92);
    return fldInStreamReadUInt64(stream, applicationId);
}

void relaySerializeWriteChannelId(struct FldOutStream* stream, RelaySerializeChannelId channelId)
{
    if (channelId == 0) {
        CLOG_ERROR("listenerId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x93);
    fldOutStreamWriteUInt16(stream, channelId);
}
int relaySerializeReadChannelId(struct FldInStream* stream, RelaySerializeChannelId* channelId)
{
    fldInStreamCheckMarker(stream, 0x93);
    return fldInStreamReadUInt16(stream, channelId);
}

void relaySerializeWriteRequestId(struct FldOutStream* stream, RelaySerializeRequestId requestId)
{
    if (requestId == 0) {
        CLOG_ERROR("listenerId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x94);
    fldOutStreamWriteUInt8(stream, requestId);
}

int relaySerializeReadRequestId(struct FldInStream* stream, RelaySerializeRequestId* requestId)
{
    fldInStreamCheckMarker(stream, 0x94);
    return fldInStreamReadUInt8(stream, requestId);
}

