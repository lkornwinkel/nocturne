#ifndef NOCTURNE_PLUGIN_HPP
#define NOCTURNE_PLUGIN_HPP

#include <filesystem>

namespace nocturne {

    class Host;

    class Plugin {
    public:
        bool load(Host &host, std::filesystem::path const &file);
    };
}
#endif //NOCTURNE_PLUGIN_HPP
