#ifndef __RINGQUEUE__H
#define __RINGQUEUE__H
#include "mepconfig.h"

#ifndef bool
#define bool bit
#define true (1==1)
#define false (!true)
#endif

#define rq_is_full(rq) (rq->head==((rq->tail+1)&rq->size))
#define rq_is_empty(rq) (rq->head==rq->tail)

#define RQ_MAXSIZE 0x1F /* must be 2^n-1 to accelerate calcurate, replace % with & */
typedef struct
{
	u8 head;
	u8 tail;
	u8 size;
	u8 data[RQ_MAXSIZE];
}ringQueue_t;

void rq_reset(ringQueue_t *rq);
bool rq_push(ringQueue_t *rq,u8 v);
bool rq_poll(ringQueue_t *rq,u8 *v);

#endif
