/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <guise-serialize/commands.h>
#include <guise-serialize/server_out.h>

#define DEBUG_PREFIX "ServerOut"

int guiseSerializeServerOutChallenge(FldOutStream* outStream, GuiseSerializeClientNonce forClient,
                                    GuiseSerializeServerChallenge challenge)
{
    guiseSerializeWriteCommand(outStream, guiseSerializeCmdChallengeResponse, DEBUG_PREFIX);
    guiseSerializeWriteClientNonce(outStream, forClient);
    guiseSerializeWriteServerChallenge(outStream, challenge);

    return 0;
}

int guiseSerializeServerOutLogin(FldOutStream* outStream, GuiseSerializeClientNonce forClient,
                                GuiseSerializeUserSessionId userSessionId)
{
    guiseSerializeWriteCommand(outStream, guiseSerializeCmdLoginResponse, DEBUG_PREFIX);
    guiseSerializeWriteClientNonce(outStream, forClient);
    guiseSerializeWriteUserSessionId(outStream, userSessionId);

    return 0;
}
