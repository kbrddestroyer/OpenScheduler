#ifndef OPENSCHEDULER_G_REGISTRY_HPP
#define OPENSCHEDULER_G_REGISTRY_HPP

#include <vector>
#include <vector>
#include "dao/worker_dao.hpp"

namespace OpenScheduler {
    extern std::vector<Dao::WorkerDao> g_workers;

    void sync_global_registry();
}

#endif //OPENSCHEDULER_G_REGISTRY_HPP
