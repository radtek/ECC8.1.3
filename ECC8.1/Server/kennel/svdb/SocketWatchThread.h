#ifndef SVDB_SOCKETWATCHTHREAD_H
#define SVDB_SOCKETWATCHTHREAD_H


#include "svdbtype.h"
#include "ThreadEx.h"
#include "SvdbMain.h"
#include "ThreadContrl.h"


class SocketWatchThread :
	public ThreadEx
{
public:
	SocketWatchThread(void);
	~SocketWatchThread(void);

	bool Init();
	void run(void);

	SvdbMain *m_pMain;
protected:
	ThreadContrl *m_pTC;

};

#endif
