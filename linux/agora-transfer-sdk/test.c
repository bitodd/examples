/**************************************************************************************************
 * Author    : Lionfore Hao (haolianfu@agora.io)
 * Module    : Agora SDK transport C API Demo program.
 * Purpose   : This is introduced for external transparent audio and video data
 * Date       : Feb 10th, 2018
 *
 * Copyright (C) Agora IO. All rights reserved.
 **************************************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>

#include <agora_transport_interfaces.h>

static void onJoinChannelSuccess (void *data, const char *channel, uint32_t uid, int elapsed)
{
	fprintf (stderr, "%u logined successfully in %s, elapsed: %d ms, data=%p\n", uid, channel, elapsed, data);
}

static void onRejoinChannelSuccess (void *data, const char *channel, uint32_t uid, int elapsed) 
{
	fprintf (stderr, "%u rejoin to channel: %s, time offset %d ms, data=%p\n", uid, channel, elapsed, data);
}

static void onWarning (void *data, int warn, const char *msg) 
{
	fprintf(stderr, "onWarning code: %d, %s, data=%p\n", warn, msg, data);
}

static void onError (void *data, int rescode, const char *msg) 
{
	switch (rescode) {
	default:
		fprintf (stderr, "Error in mediasdk: %d, %s, data=%p\n", rescode, msg, data);
		break;
	}
}

static void onUserJoined (void *data, uint32_t uid, int elapsed) 
{
	fprintf(stderr, "offset %d ms: %u joined the channel, data=%p\n", elapsed, uid, data);
}

static void onUserOffline (void *data, uint32_t uid, int reason) 
{
	const char *detail = reason == USER_OFFLINE_QUIT ? "quit" : "dropped";
	fprintf (stderr, "User %u %s, data=%p\n", uid, detail, data);
}

static void onConnectionLost (void *data) 
{
	fprintf (stderr, "onConnectionLost, aborting, data=%p\n", data);
}

static int onCustomizedSei (void *data, const void **content, int *length)
{
	return 0;
}

static agora_event_handler_t event_handler = {
	.onJoinChannelSuccess = onJoinChannelSuccess,
	.onRejoinChannelSuccess = onRejoinChannelSuccess,
	.onWarning = onWarning,
	.onError = onError,
	.onUserJoined = onUserJoined,
	.onUserOffline = onUserOffline,
	.onConnectionLost = onConnectionLost,
	.onCustomizedSei = onCustomizedSei,
};


static char audio_data [128];
static char video_data [1024];

static void on_video_data (const uint32_t uid, const void *data, size_t len, int is_key_frame)
{
	printf ("on_video_data: user %u, %ld, cmp=%d\n", uid, len, memcmp (data, video_data, sizeof video_data));
}

static void on_audio_data (const uint32_t uid, const void *data, size_t len)
{
	printf ("on_audio_data: user %u, %ld, cmp=%d\n", uid, len, memcmp (data, audio_data, sizeof audio_data));
}

int main(int argc, char *argv[])
{
	const char *app_id =  "";
	const char *channel_name = "xiaomi-test1";
	int i;

	agora_set_video_data_callback (on_video_data);
	agora_set_audio_data_callback (on_audio_data);
	
	if (argc > 1)
		channel_name = argv [1];

	agora_create_rtc_engine (app_id, &event_handler, (void *)100ul);
	agora_rtc_enable_video ();
	agora_rtc_join_channel (NULL, channel_name, 0);

	printf ("Start sending non-Key video frame...\n");

	for (i = 0; i < 8; i++) {
 		agora_send_video_data (video_data, sizeof video_data, 0);
		agora_send_audio_data (audio_data, sizeof audio_data);
		sleep (1);
	}

//	agora_rtc_disable_video ();
	printf ("Start sending non-Key video frame...\n");
	
	for (i = 0; i < 8; i++) {
 		agora_send_video_data (video_data, sizeof video_data, 0);
		agora_send_audio_data (audio_data, sizeof audio_data);
		sleep (1);
	}

//	agora_rtc_disable_audio ();
//	agora_rtc_enable_video ();
	
	printf ("Start sending non-Key video frame...\n");

	for (i = 0; i < 8; i++) {
 		agora_send_video_data (video_data, sizeof video_data, 0);
		agora_send_audio_data (audio_data, sizeof audio_data);
		sleep (1);
	}

//	agora_rtc_enable_audio ();
	
	printf ("Start sending Key video frame...\n");

	for (i = 0; i < 5; i++) {
		agora_send_video_data (video_data, sizeof video_data, 1);
		agora_send_audio_data (audio_data, sizeof audio_data);
		sleep (1);
	}

	agora_rtc_leave_channel ();
        printf("before sleep 2 secs\n");
	sleep (2);
        printf("agora_rtc_leave_channel end\n");
	return 0;
}
