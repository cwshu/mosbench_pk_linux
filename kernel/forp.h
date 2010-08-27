#include <linux/forp-patch.h>

#define FORP_REC_SIZE		256
#define FORP_ENTRY_REC_SIZE 	512

#define FORP_FLAG_SLEEP_TIME	0x01
#define FORP_FLAG_ALL		(FORP_FLAG_SLEEP_TIME)

DECLARE_PER_CPU_ALIGNED(struct forp_rec[FORP_REC_SIZE], forp_recs);
DECLARE_PER_CPU_ALIGNED(struct forp_rec[FORP_ENTRY_REC_SIZE], 
			forp_entry_recs);
extern struct forp_label *forp_labels __read_mostly;
extern struct mutex forp_mu;
extern int forp_rec_num __read_mostly;
extern int forp_enable __read_mostly;
extern unsigned long forp_flags __read_mostly;

static inline void forp_reset_rec(struct forp_rec *rec)
{
	rec->time = 0;
	rec->count = 0;
	rec->sched = 0;
}

extern void forp_register(struct forp_label *labels, int n);
extern int forp_init(int enable);
extern void forp_deinit(void);
