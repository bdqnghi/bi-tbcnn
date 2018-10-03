/* 
	CAnimationQueue.cpp

	Author:			Tom Naughton
	Description:	<describe the CAnimationQueue class here>
*/

#include "CAnimationQueue.h"



CAnimationQueue::CAnimationQueue()
{
	currentFrame = 0;
	nextFrame = 0;
	interpolation = 0.0;
	queueLength = 0;
	queueCursor = 0;
}


CAnimationQueue::~CAnimationQueue()
{
}

void CAnimationQueue::PushSequence(int start, int count)
{
	// move current frame to top of queue
	for (int i = 0; queueLength < ANIMATION_QUEUE_SIZE && i < count; i++) {
		int index = (queueCursor + queueLength) % ANIMATION_QUEUE_SIZE;
		queue[index] = i + start;
		queueLength++;
	}
}

void CAnimationQueue::PopFrames(int count)
{
	queueCursor = (queueCursor + count) % ANIMATION_QUEUE_SIZE;
	queueLength -= count;
}

SInt16 CAnimationQueue::PeekFrame(int index)
{
	index = (queueCursor + index) % ANIMATION_QUEUE_SIZE;
	return queue[index];
}


