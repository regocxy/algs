#include "ringqueue.h"

void rq_reset(ringQueue_t *rq)
{
	rq->head=rq->tail=0;
	rq->size=RQ_MAXSIZE;
}

bool rq_push(ringQueue_t *rq,u8 v)
{
	if(rq_is_full(rq))
	{
		return false;
	}
	rq->data[rq->tail]=v;
	rq->tail=(rq->tail+1)&rq->size;
	return true;
}

bool rq_poll(ringQueue_t *rq,u8 *v)
{
	if(rq_is_empty(rq))
	{
		return false;
	}
	*v=rq->data[rq->head];
	rq->head=(rq->head+1)&rq->size;
	return true;
}
