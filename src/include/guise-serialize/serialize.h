/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_SERIALIZE_H
#define GUISE_SERIALIZE_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>

#include <guise-serialize/types.h>

struct FldOutStream;
struct FldInStream;

void guiseSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix);

void guiseSerializeWriteUserSessionId(struct FldOutStream* outStream, GuiseSerializeUserSessionId userSessionId);
int guiseSerializeReadUserSessionId(struct FldInStream* stream, GuiseSerializeUserSessionId* userSessionId);

void guiseSerializeWriteUserId(struct FldOutStream* outStream, GuiseSerializeUserId userId);
int guiseSerializeReadUserId(struct FldInStream* stream, GuiseSerializeUserId* userId);

void guiseSerializeWritePasswordHashWithChallenge(struct FldOutStream* outStream,
                                                  GuiseSerializePasswordHashWithChallenge password);
int guiseSerializeReadPasswordHashWithChallenge(struct FldInStream* stream,
                                                GuiseSerializePasswordHashWithChallenge* password);

void guiseSerializeWriteClientNonce(struct FldOutStream* outStream, GuiseSerializeClientNonce clientNonce);
int guiseSerializeReadClientNonce(struct FldInStream* stream, GuiseSerializeClientNonce* clientNonce);

void guiseSerializeWriteServerChallenge(struct FldOutStream* outStream, GuiseSerializeServerChallenge serverChallenge);
int guiseSerializeReadServerChallenge(struct FldInStream* stream, GuiseSerializeServerChallenge* serverChallenge);

void guiseSerializeWriteUserName(struct FldOutStream* stream, const GuiseSerializeUserName* userName);
int guiseSerializeReadUserName(struct FldInStream* stream, GuiseSerializeUserName* userName);

int guiseSerializeWriteString(struct FldOutStream* stream, const char* s);
int guiseSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength);

int guiseSerializeWriteNetworkAddress(struct FldOutStream* stream, const GuiseSerializeAddress* address);
int guiseSerializeReadNetworkAddress(struct FldInStream* stream, GuiseSerializeAddress* address);

#endif
