#include <linux/unistd.h>

#define __NR_get_slob_amt_claimed 344
#define __NR_get_slob_amt_free 343

extern long int syscall(long int_sysno,...)__THROW;
