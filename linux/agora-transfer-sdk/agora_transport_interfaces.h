/********************************************************************************************************
 * Author    : Lionfore Hao (haolianfu@agora.io)
 * Module    : Agora Transport SDK C API interfaces.
 * Purpose   : For customers those only want to utilize our SD-RTN network capability.
 * Date       : Feb 9th, 2018
 *
 * Copyright (C) Agora IO. All rights reserved.
 ********************************************************************************************************/

#ifndef __AGORA_TRANSPORT_INTERFACES_H__
#define __AGORA_TRANSPORT_INTERFACES_H__

#include <sys/types.h>
#include <stdint.h>


#ifdef  __cplusplus
extern "C" {
#endif


typedef struct {
	unsigned int duration;
	unsigned int txBytes;
	unsigned int rxBytes;
	unsigned short txKBitRate;
	unsigned short rxKBitRate;
	unsigned int lastmileQuality;
	double cpuAppUsage;
	double cpuTotalUsage;
} agora_rtcstats_t;

enum USER_OFFLINE_REASON_TYPE
{
	USER_OFFLINE_QUIT = 0,
	USER_OFFLINE_DROPPED = 1,
};

/**
 * The Agora SDK event handler structure.
 **/
typedef struct {
	void (*onJoinChannelSuccess) (void *data, const char *channel, uint32_t uid, int elapsed);
	void (*onRejoinChannelSuccess) (void *data, const char *channel, uint32_t uid, int elapsed);
	void (*onWarning) (void *data, int warn, const char *msg);
	void (*onError) (void *data, int err, const char *msg);
	void (*onUserJoined) (void *data, uint32_t uid, int elapsed);
	void (*onUserOffline) (void *data, uint32_t uid, int reason);
	void (*onRtcStats) (void *data, const agora_rtcstats_t *stats);
	void (*onConnectionLost) (void *data);
	void (*onUserMuteVideo) (void *data, uint32_t uid, int muted);
	void (*onLogEvent) (void *data, int level, const char *msg, int length);
	int (*onCustomizedSei) (void *data, const void **content, int *length);
} agora_event_handler_t;


/**
 * Create the global Agora RTC Engine instance, only ONE instance allowed for a single process.
 * Parameter:
 *     app_id: The Application ID issued by Agora for the using customer;
 *     event_handler: A set of C callback functions for processing the Agora SDK events.
 *     data: User passed pointer which would be presented as the first arg for each callback function.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_create_rtc_engine (const char *app_id, const agora_event_handler_t *event_handler, void *data);

/**
 * Enable audio stream. The audio stream is enabled by default.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_enable_audio ();

/**
 * Disable audio stream. The audio stream is enabled by default.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_disable_audio ();

/**
 * Enable video stream. The video stream is disabled by default, so
 * you need to enable when needed.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_enable_video ();

/**
 * Disable video stream. The video stream is disabled by default.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_disable_video ();

/**
 * Join a channel for chatting. You must join a channel before you can
 * communicate with anyone.
 * Parameter:
 *     channel_key: Channel key string;
 *     channel_name: Channel name string;
 *     uid: The joining user's ID, a 32bits integer number;
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_join_channel (const char *channel_key, const char *channel_name, uint32_t uid);

/**
 * Leave a channel. You must leave channel when you do not want to
 * communicate with others.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_rtc_leave_channel ();

/**
 * Destroy the single global Agora RTC Engine instance which was
 * created previously by agora_create_rtc_engine.
 * Parameter:
 *      None.
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern int agora_destroy_rtc_engine ();


/**
 * Send transparent video data to the joined channel, then other users
 * in this channel could receive the video stream.
 * Parameter:
 *     data: The video data memory;
 *     len: The video data size in bytes;
 *     is_key_frame: Indicates whether the video frame is a key frame,
 *                         1: key frame
 *                         0: non-key frame
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern void agora_send_video_data (const void *data, size_t len, int is_key_frame);

/**
 * Send transparent audio data to the joined channel, then other users
 * in this channel could receive the audio stream.
 * Parameter:
 *     data: The audio data memory;
 *     len: The audio data size in bytes;
 * Return value:
 *     0 for success, -1 when failed with errno set.
 **/
extern void agora_send_audio_data (const void *data, size_t len);


/**
 * The video data callback function, this callback function would be
 * invoked when received a video frame.
 * Parameter:
 *       uid: The user ID the video stream belongs to;
 *     data: The video data memory;
 *       len: The video data size in bytes;
 *     is_key_frame: Indicates whether the video frame is a key frame,
 *                         1: key frame
 *                         0: non-key frame
 * Return value:
 *     None.
 **/
typedef void (*video_data_cb_t) (const uint32_t uid, const void *data, size_t len, int is_key_frame);

/**
 * The audio data callback function, this callback function would be
 * invoked when received a audio frame.
 * Parameter:
 *       uid: The user ID the audio stream belongs to;
 *     data: The audio data memory;
 *       len: The audio data size in bytes;
 * Return value:
 *     None.
 **/
typedef void (*audio_data_cb_t) (const uint32_t uid, const void *data, size_t len);


/**
 * Set the video data callback function, and this callback function would be
 * invoked when received a video frame.
 * Parameter:
 *       video_cb_f: The video data callback function;
 * Return value:
 *     None.
 **/
extern void agora_set_video_data_callback (video_data_cb_t video_cb_f);

/**
 * Set the audio data callback function, and this callback function would be
 * invoked when received a audio frame.
 * Parameter:
 *       audio_cb_f: The audio data callback function;
 * Return value:
 *     None.
 **/
extern void agora_set_audio_data_callback (audio_data_cb_t audio_cb_f);



#ifdef  __cplusplus
}
#endif


#endif /* __AGORA_TRANSPORT_INTERFACES_H__ */
