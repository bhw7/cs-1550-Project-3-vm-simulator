//
// Created by Betsalel Williamson on 6/30/16.
//

#include <lib/include/controller.h>
#include "gtest/gtest.h"

// ./vmsim –n <numframes> -a <opt|clock|aging|lru> [-r <refresh>] <tracefile>

// test num frames

// test opt

// test clock

// test aging

// test lru

// test refresh

// test read tracefile

TEST(Control_tests, Read_file_Test) {

    // open file
    trace_tail_queue *result = read_trace_file(
            "/Users/school/Box Sync/Courses/- CS 1550/projects/3/cs-1550-Project-3-vm-simulator/downloads/gcc.trace");

    int i = 0;
    TAILQ_FOREACH(trace_tail_queue_entry, result, entries) {
        i++;
    }

    int TRACE_TAIL_QUEUE_ENTRY_COUNT = 1000000;

    ASSERT_EQ(TRACE_TAIL_QUEUE_ENTRY_COUNT, i);

    print_debug(("Hello from inside read file test %d\n", i));
}

TEST(Control_tests, Get_status_recently_used_and_modified) {

    Page_table_entry *p = (Page_table_entry *) malloc(sizeof(Page_table_entry));
    p->reference_bit = 1;
    p->modify_bit = 1;

    ASSERT_EQ(RECENTLY_USED_AND_MODIFIED, get_usage_status(p));
}

TEST(Control_tests, Get_status_recently_used_and_not_modified) {

    Page_table_entry *p = (Page_table_entry *) malloc(sizeof(Page_table_entry));
    p->reference_bit = 1;
    p->modify_bit = 0;

    ASSERT_EQ(RECENTLY_USED_AND_NOT_MODIFIED, get_usage_status(p));
}

TEST(Control_tests, Get_status_not_recently_used_and_modified) {

    Page_table_entry *p = (Page_table_entry *) malloc(sizeof(Page_table_entry));
    p->reference_bit = 0;
    p->modify_bit = 1;

    ASSERT_EQ(NOT_RECENTLY_USED_AND_MODIFIED, get_usage_status(p));
}

TEST(Control_tests, Get_status_not_recently_used_and_not_modified) {

    Page_table_entry *p = (Page_table_entry *) malloc(sizeof(Page_table_entry));
    p->reference_bit = 0;
    p->modify_bit = 0;

    ASSERT_EQ(NOT_RECENTLY_USED_AND_NOT_MODIFIED, get_usage_status(p));
}