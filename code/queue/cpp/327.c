// Oueue.cpp :
//
//#include "stdafx.h"
#include "..\..\sources\Data\Queue.h"


SQueue *InitSQueue( void )
{
	SQueue *sq = (SQueue *)new SQueue;
	sq->front = 0;
	sq->rear  = 0;
	sq->num   = 0;
	return sq;
}

int INSQueue( SQueue *sq, QUDA nSrcData )
{
// 	if ( MAX_SAMP_RECORD == sq->num )
// 	{
// 		TRACE( "\r\nQueue is Full" );
// 		return -1;
// 	} 
// 	else
// 	{
		sq->rear = ( sq->rear + 1 ) % MAX_SAMP_RECORD;
		sq->nData[ sq->rear ] = nSrcData;
		sq->num++;
		if ( sq->num > MAX_SAMP_RECORD )
		{
			sq->num = MAX_SAMP_RECORD;
		}
		return 1;
//	}
}

// int OutSQueue( SQueue *sq, QUDA *x )
// {
// 	if ( 0 == sq->num )
// 	{
// 		TRACE( "Queue is Empty" );
// 		return -1;
// 	} 
// 	else
// 	{
// 		sq->front = ( sq->front + 1 ) % MAX_SAMP_RECORD;
// 		*x = sq->nData[ sq->front ];
// 		sq->num--;
// 		return 1;
// 	}
// }

