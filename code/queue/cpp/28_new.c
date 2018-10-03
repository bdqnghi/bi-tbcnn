#include "h2unit.h"

extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
}


H2UNIT(ngx_queue)
{
	ngx_pool_t * pool;
	void setup()
	{
		pool = ngx_create_pool(128, NULL);
	}

	void teardown()
	{
		ngx_destroy_pool(pool);
	}
};

H2CASE(ngx_queue,"queue init")
{
   ngx_queue_t queue;
   ngx_queue_init(&queue);
   H2EQ_TRUE(&queue == queue.prev);
   H2EQ_TRUE(&queue == queue.next);
}

H2CASE(ngx_queue,"queue empty")
{
   ngx_queue_t queue;
   ngx_queue_init(&queue);
   H2EQ_TRUE(ngx_queue_empty(&queue));
}

