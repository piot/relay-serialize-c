/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
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

void relaySerializeWriteClientNonce(struct FldOutStream* stream, RelaySerializeClientNonce clientNonce)
{
    fldOutStreamWriteMarker(stream, 0x87);
    fldOutStreamWriteUInt64(stream, clientNonce);
}

int relaySerializeReadClientNonce(struct FldInStream* stream, RelaySerializeClientNonce* clientNonce)
{
    fldInStreamCheckMarker(stream, 0x87);
    return fldInStreamReadUInt64(stream, clientNonce);
}

void relaySerializeWriteServerChallenge(struct FldOutStream* stream, RelaySerializeServerChallenge serverChallenge)
{
    fldOutStreamWriteMarker(stream, 0x88);
    fldOutStreamWriteUInt64(stream, serverChallenge);
}

int relaySerializeReadServerChallenge(struct FldInStream* stream, RelaySerializeServerChallenge* serverChallenge)
{
    fldInStreamCheckMarker(stream, 0x88);
    return fldInStreamReadUInt64(stream, serverChallenge);
}

int relaySerializeWriteString(FldOutStream* stream, const char* s)
{
    size_t len = tc_strlen(s);
    fldOutStreamWriteUInt8(stream, (uint8_t )len);
    return fldOutStreamWriteOctets(stream, (const uint8_t*) s, len);
}

int relaySerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength)
{
    uint8_t stringLength;
    fldInStreamReadUInt8(stream, &stringLength);
    if (stringLength + 1 > maxLength) {
        return -1;
    }
    int errorCode = fldInStreamReadOctets(stream, (uint8_t*) buf, stringLength);
    if (errorCode < 0) {
        return errorCode;
    }
    buf[stringLength] = 0;
    return stringLength;
}
