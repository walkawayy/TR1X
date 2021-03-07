#ifndef T1M_TEST_H
#define T1M_TEST_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

static size_t tests = 0;
static size_t fails = 0;

#define TEST_RESULTS()                                                         \
    do {                                                                       \
        if (fails == 0) {                                                      \
            printf("ALL TESTS PASSED (%d/%d)\n", tests, tests);                \
        } else {                                                               \
            printf("SOME TESTS FAILED (%d/%d)\n", tests - fails, tests);       \
        }                                                                      \
    } while (0)

#define TEST_RUN(test)                                                         \
    do {                                                                       \
        const size_t ts = tests;                                               \
        const size_t fs = fails;                                               \
        const clock_t start = clock();                                         \
        test();                                                                \
        printf(                                                                \
            "pass: %d fail: %d time: %ldms\n", (tests - ts) - (fails - fs),    \
            fails - fs, (long)((clock() - start) * 1000 / CLOCKS_PER_SEC));    \
    } while (0)

#define ASSERT_OK(test)                                                        \
    do {                                                                       \
        tests++;                                                               \
        if (!(test)) {                                                         \
            fails++;                                                           \
            printf("%s:%d error \n", __FILE__, __LINE__);                      \
        }                                                                      \
    } while (0)

#define ASSERT_EQUAL_BASE(equality, a, b, format)                              \
    do {                                                                       \
        tests++;                                                               \
        if (!(equality)) {                                                     \
            fails++;                                                           \
            printf(                                                            \
                "%s:%d (" format " != " format ")\n", __FILE__, __LINE__, (a), \
                (b));                                                          \
        }                                                                      \
    } while (0)

#define ASSERT_INT_EQUAL(a, b) ASSERT_EQUAL_BASE((a) == (b), a, b, "%d")
#define ASSERT_STR_EQUAL(a, b) ASSERT_EQUAL_BASE(!strcmp(a, b), a, b, "%s")

#endif
