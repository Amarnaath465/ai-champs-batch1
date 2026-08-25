#ifndef MINITEST_H
#define MINITEST_H

/* Deliberately tiny, zero-dependency host-test harness so the lab builds
 * with nothing but gcc/make — no network access or package manager needed. */

#include <stdio.h>

static int mt_pass_count = 0;
static int mt_fail_count = 0;

#define MT_ASSERT_EQ(actual, expected, msg)                                    \
    do {                                                                       \
        long mt_a = (long)(actual);                                           \
        long mt_e = (long)(expected);                                         \
        if (mt_a != mt_e) {                                                   \
            printf("  FAIL %s:%d: %s (got %ld, expected %ld)\n",              \
                   __FILE__, __LINE__, msg, mt_a, mt_e);                      \
            mt_fail_count++;                                                  \
        } else {                                                              \
            mt_pass_count++;                                                  \
        }                                                                     \
    } while (0)

#define MT_ASSERT_TRUE(cond, msg)                                              \
    do {                                                                       \
        if (!(cond)) {                                                        \
            printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, msg);            \
            mt_fail_count++;                                                  \
        } else {                                                              \
            mt_pass_count++;                                                  \
        }                                                                     \
    } while (0)

#define MT_RUN(test_fn)                                                        \
    do {                                                                       \
        printf("RUN  %s\n", #test_fn);                                        \
        test_fn();                                                            \
    } while (0)

static int mt_summary(void)
{
    printf("\n%d passed, %d failed\n", mt_pass_count, mt_fail_count);
    return mt_fail_count == 0 ? 0 : 1;
}

#endif /* MINITEST_H */
