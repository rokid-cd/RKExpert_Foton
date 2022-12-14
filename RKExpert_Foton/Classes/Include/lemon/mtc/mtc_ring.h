/************************************************************************

        Copyright (c) 2005-2011 by Juphoon System Software, Inc.
                       All rights reserved.

     This software is confidential and proprietary to Juphoon System,
     Inc. No part of this software may be reproduced, stored, transmitted,
     disclosed or used in any form or by any means other than as expressly
     provided by the written license agreement between Juphoon and its
     licensee.

     THIS SOFTWARE IS PROVIDED BY JUPHOON "AS IS" AND ANY EXPRESS OR
     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
     ARE DISCLAIMED. IN NO EVENT SHALL JUPHOON BE LIABLE FOR ANY DIRECT,
     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
     OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
     POSSIBILITY OF SUCH DAMAGE.

                    Juphoon System Software, Inc.
                    Email: support@juphoon.com
                    Web: http://www.juphoon.com

************************************************************************/
/*************************************************
  File name     : mtc_ring.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2011-01-03
  Description   :
    Macros and structure definitions required by the MTC ring.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_RING_H__
#define _MTC_RING_H__

#include "mtc_def.h"

/**
 * @file mtc_ring.h
 * @brief MTC Ring Interface Functions.
 */
#ifdef __cplusplus
EXPORT_FLAG {
#endif

/** @brief Macro for playing ring forever. */
#define MTC_RING_FOREVER 0

/** @brief Macro for playing DTMF time length in milliseconds. */
#define MTC_RING_DTMF_LEN 200

/** @brief Macro for playing alert event time length in milliseconds. */
#define MTC_RING_ALERT_LEN 500

/** @brief Macro for playing terminated event time length in milliseconds. */
#define MTC_RING_TERM_LEN 2000

/** @brief Mask for use resource in asset for Android. */
#define MTC_RING_ASSET_MASK 0x80000000

/** @brief MTC ring type */
typedef enum EN_MTC_RING_TYPE
{
    EN_MTC_RING_TONE_0,              /**< @brief Tone 0. */
    EN_MTC_RING_TONE_1,              /**< @brief Tone 1. */
    EN_MTC_RING_TONE_2,              /**< @brief Tone 2. */
    EN_MTC_RING_TONE_3,              /**< @brief Tone 3. */
    EN_MTC_RING_TONE_4,              /**< @brief Tone 4. */
    EN_MTC_RING_TONE_5,              /**< @brief Tone 5. */
    EN_MTC_RING_TONE_6,              /**< @brief Tone 6. */
    EN_MTC_RING_TONE_7,              /**< @brief Tone 7. */
    EN_MTC_RING_TONE_8,              /**< @brief Tone 8. */
    EN_MTC_RING_TONE_9,              /**< @brief Tone 9. */
    EN_MTC_RING_TONE_STAR,           /**< @brief Tone *. */
    EN_MTC_RING_TONE_POUND,          /**< @brief Tone #. */

    EN_MTC_RING_RING,                /**< @brief Ring. */
    EN_MTC_RING_RING_BACK,           /**< @brief Ring back. */
    EN_MTC_RING_CALL_FAILED,         /**< @brief Call failed. */
    EN_MTC_RING_BUSY,                /**< @brief Busy. */
    EN_MTC_RING_CALL_WAIT,           /**< @brief Call waiting. */
    EN_MTC_RING_FORWARD,             /**< @brief Forwarding. */
    EN_MTC_RING_TERM,                /**< @brief Call terminated. */
    EN_MTC_RING_HELD,                /**< @brief Call held. */

    EN_MTC_RING_MSG_RECV,            /**< @brief Message received. */
    EN_MTC_RING_SIZE                 /**< @brief Ring size. */
} EN_MTC_RING_TYPE;

/**
 * @defgroup MtcRingKey MTC notification key of media event.
 * @{
 */

/**
 * @brief A key whose value is a number reflecting the ring type
 * @ref EN_MTC_RING_TYPE.
 */
#define MtcRingTypeKey       "MtcRingTypeKey"
/** @} */

/**
 * @defgroup MtcRingNotification MTC notification of media event.
 * @{
 */

/**
 * @brief Posted when the ring play completed.
 *
 * The pcInfo of this notification contains @ref MtcRingTypeKey
 * which reflects the ring type.
 */
#define MtcRingPlayDidFinishNotification  "MtcRingPlayDidFinishNotification"
/** @} */

/**
 * @brief Play ring, and ring type see @ref EN_MTC_RING_TYPE.
 *
 * It will play the custom set file if found. Or it will try to play
 * the default ring file. The default ring file path formed by the directory
 * set by @ref Mtc_RingSetDir, the ring name and ".wav" for extension name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 * @param [in] iMilliSeconds The playing time length in milliseconds,
 *                           0 is for forever.
 *
 * @retval 0 Audio plays ring successfully.
 * @retval 1 Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlayX Mtc_RingStop
 */
MTCFUNC int Mtc_RingPlay(unsigned int iType, unsigned int iMilliSeconds);

/**
 * @brief Play ring with no loop, and ring type see @ref EN_MTC_RING_TYPE.
 *
 * It will play the custom set file if found. Or it will try to play
 * the default ring file. The default ring file path formed by the directory
 * set by @ref Mtc_RingSetDir, the ring name and ".wav" for extension name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @retval 0 Audio plays ring successfully.
 * @retval 1 Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlay
 */
MTCFUNC int Mtc_RingPlayNoLoop(unsigned int iType);

/**
 * @brief Play ring file.
 *
 * The ring name and ".wav" for extension name.
 *
 * @param [in] pcFileName File name of ring file.
 * @param [in] iMilliSeconds The playing time length in milliseconds,
 *                           0 is for forever.
 *
 * @retval 0 Audio plays ring successfully.
 * @retval 1 Audio plays ring failed.
 *
 * @see @ref Mtc_RingPlay Mtc_RingStop
 */
MTCFUNC int Mtc_RingPlayX(const char *pcFileName, unsigned int iMilliSeconds);

/**
 * @brief Play ring file with no loop.
 * @param  pcFileName File name of ring file.
 * @retval 0 Audio plays ring successfully.
 * @retval 1 Audio plays ring failed.
 */
MTCFUNC int Mtc_RingPlayXNoLoop(const char *pcFileName);

/**
 * @brief Audio stop playback.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE. ZMAXUINT to
                     stop every ring play.
 *
 * @see @ref Mtc_RingPlay Mtc_RingPlayX
 */
MTCFUNC void Mtc_RingStop(unsigned int iType);

/**
 * @brief Audio stop playback.
 *
 * @see @ref Mtc_RingPlayX
 */
MTCFUNC void Mtc_RingStopX(void);

/**
 * @brief Audio is playing.
 *
 * @retval true Audio is playing.
 * @retval false Audio is not playing.
 *
 * @see @ref Mtc_RingPlay
 */
MTCFUNC bool Mtc_RingIsPlay(void);

/**
 * @brief Get ring name by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring name if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingGetType
 */
MTCFUNC const char * Mtc_RingGetName(unsigned int iType);

/**
 * @brief Get ring description by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring description if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingGetType
 */
MTCFUNC const char * Mtc_RingGetDesc(unsigned int iType);

/**
 * @brief Get ring type by name.
 *
 * @param [in] pcName The ring name string.
 *
 * @return The ring type if found. Or return -1.
 *
 * @see @ref Mtc_RingGetName
 */
MTCFUNC int Mtc_RingGetType(char *pcName);

/**
 * @brief Get custom ring file name by type.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 *
 * @return The ring custom ring file name if found, otherwise return empty string.
 *
 * @see @ref Mtc_RingSetCtmName
 */
MTCFUNC const char * Mtc_RingGetCtmName(unsigned int iType);

/**
 * @brief Set custom ring file name.
 *
 * @param [in] iType The ring Type, see @ref EN_MTC_RING_TYPE.
 * @param [in] pcName The ring file name.
 *
 * @retval 0 Set custom ring file name successfully.
 * @retval 1 Set custom ring file name failed.
 *
 * @see @ref Mtc_RingGetCtmName
 */
MTCFUNC int Mtc_RingSetCtmName(unsigned int iType, const char *pcName);

/**
 * @brief Get directory for default ring file.
 *
 * @return The directory for default ring file.
 *
 * @see @ref Mtc_RingSetDir
 */
MTCFUNC const char * Mtc_RingGetDir(void);

/**
 * @brief Set directory for default ring file.
 *
 * @param [in] pcName The directory name.
 * @param [in] wLen The string length of directory name.
 *
 * @retval 0 Set directory for default ring file successfully.
 * @retval 1 Set directory for default ring file failed.
 *
 * @see @ref Mtc_RingGetDir
 */
MTCFUNC void Mtc_RingSetDir(const char *pcName, unsigned short wLen);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_RING_H__ */
