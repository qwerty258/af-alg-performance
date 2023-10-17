#pragma once

#ifdef __cplusplus
#include <cstdint>
#include <cstdbool>
extern "C"
{
#else
#include <stdint.h>
#include <stdbool.h>
#endif

#define MAX_CPU_COUNT 128

    typedef struct
    {
        char **test_files;
        bool dump_compressed_data_as_file;
        bool print_header;
        size_t test_data_multiplier;
        size_t thread_count;
        size_t cmd_buffer_count_in_kernel;
        size_t test_file_count;
        size_t block_size;
        size_t deflate_window_size;
        int cpu_affinity[MAX_CPU_COUNT];
        size_t cpu_affinity_size;
        bool enable_cpu_affinity;
    } test_configs_t;

    bool test_config_get(test_configs_t *p_configs);

    void test_config_release(test_configs_t *p_configs);

#ifdef __cplusplus
}
#endif