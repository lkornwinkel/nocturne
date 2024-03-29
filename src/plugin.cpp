#include <nocturne/plugin.hpp>
#include <nocturne/host.hpp>

namespace nocturne {
    bool Plugin::load(Host &host, std::filesystem::path const &file) {
        return false;
    }
}
