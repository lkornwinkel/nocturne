#ifndef NOCTURNE_IMODULE_HPP
#define NOCTURNE_IMODULE_HPP

#include <QWidget>

#include <string>

namespace nocturne {
    class IModule {
    public:
        virtual ~IModule() = default;

        virtual bool load(std::string const &path, WId parent) = 0;
    };
}
#endif //NOCTURNE_IMODULE_HPP
