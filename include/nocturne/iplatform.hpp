#ifndef NOCTURNE_IPLATFORM_HPP
#define NOCTURNE_IPLATFORM_HPP

#include <nocturne/imodule.hpp>

#include <string>
#include <optional>
#include <memory>


#define PLUGIN_API __stdcall

namespace nocturne {
    class IModule;

    class IPlatform {
    public:
        virtual ~IPlatform() = default;

        [[nodiscard]] virtual std::optional<std::string> get_machine_name() = 0;

        [[nodiscard]] virtual std::shared_ptr<IModule> get_module() = 0;
    };

    extern std::unique_ptr<IPlatform> g_platform;

}
#endif //NOCTURNE_IPLATFORM_HPP
