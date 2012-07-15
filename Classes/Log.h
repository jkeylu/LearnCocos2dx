#ifndef __LOG_H__
#define __LOG_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <android/log.h>

#define  LOG_TAG    "LearnCocos2dx"
#define  LOGD(format, ...) \
do \
{ \
	char buf[256]; \
	sprintf(buf, (format), __VA_ARGS__); \
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, buf); \
} while (0)

#else

#define  LOGD(format, ...) do {} while (0)

#endif

#endif // __LOG_H__

