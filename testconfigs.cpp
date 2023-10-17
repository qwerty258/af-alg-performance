#include <iostream>
#include <fstream>
#include <cstring>
#include <json/json.h>

#include "testconfigs.h"

bool test_config_get(test_configs_t *p_configs)
{
    bool ret = true;
    Json::Value root;
    std::ifstream file;
    file.open("./testconfigs.json", std::ifstream::binary);
    file >> root;

    p_configs->test_file_count = root["test_files"].size();

    // std::cout << p_configs->test_file_count << std::endl;

    p_configs->test_files = new char *[p_configs->test_file_count];

    // std::cout << "Test files:" << std::endl;

    for (Json::ArrayIndex i = 0; i < p_configs->test_file_count; i++)
    {
        // std::cout <<root["test_files"][i].asString() <<std::endl;
        p_configs->test_files[i] = strdup(root["test_files"][i].asString().c_str());
    }

    p_configs->test_data_multiplier = root["test_data_multiplier"].asUInt();

    p_configs->thread_count = root["thread_count"].asUInt();

    p_configs->cmd_buffer_count_in_kernel = root["cmd_buffer_count_in_kernel"].asUInt();

    p_configs->dump_compressed_data_as_file = root["dump_compressed_data_as_file"].asBool();

    p_configs->print_header = root["print_header"].asBool();

    p_configs->block_size = root["block_size_in_bytes"].asUInt();

    p_configs->deflate_window_size = root["deflate_window_size"].asUInt();

    p_configs->enable_cpu_affinity = root["enable_cpu_affinity"].asBool();

    p_configs->cpu_affinity_size = root["cpu_affinity"].size();

    for (Json::ArrayIndex i = 0; i < p_configs->cpu_affinity_size; i++)
    {
        p_configs->cpu_affinity[i] = root["cpu_affinity"][i].asUInt();
    }

    return ret;
}

void test_config_release(test_configs_t *p_configs)
{
    for (uint16_t i = 0; i < p_configs->test_file_count; i++)
    {
        if (nullptr != p_configs->test_files[i])
        {
            delete p_configs->test_files[i];
        }
    }
    delete p_configs->test_files;
    p_configs->test_files = nullptr;
}

// int main()
// {
//     test_configs_t t;
//     test_config_get(&t);
//     for (size_t i = 0; i < t.test_file_count; i++)
//     {
//         printf("%s\n", t.test_files[i]);
//     }
//     test_config_release(&t);
//     return 0;
// }
