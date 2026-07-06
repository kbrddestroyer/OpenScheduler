#include "g_registry.hpp"

#include "database/table/QueryProcessor.hpp"

namespace OpenScheduler {
    std::vector<Dao::WorkerDao> g_workers;

    void sync_global_registry() {
        g_workers = Database::QueryProcessor<Dao::WorkerDao>::select("worker");
    }
}