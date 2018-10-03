
#include "../src/StdAfx.h"
#include <stdlib.h>
#include "../include/hoe_core.h"
#include "../include/hoe_structures.h"

#include <sys/time.h>

////////// Timer /////////////////

float SysFloatTime()
{
	struct timeval ctime;

	gettimeofday(&ctime, NULL);

	return ((ctime.tv_sec % 100000) + ctime.tv_usec * 0.000001f);
}

struct Tile
{
    bool in_open;
    bool in_closed;
    float g;
    float f;
};

struct PTile
{
    Tile * tile;
    inline bool operator < (const PTile & t)
    {
        return tile->f < t.tile->f;
    }
    inline bool operator > (const PTile & t)
    {
        return tile->f > t.tile->f;
    }

};

int main()
{
    HoeCore::Heap<PTile> open;
    PTile t;
    open.Insert(t);
    // pridat prvni
    while (open.Count()>0)
    {
        //
    }
    return 0;
}


