#include <nocturne/iplatform.hpp>
#include <nocturne/linux/linux_platform.hpp>
#include <nocturne/linux/linux_module.hpp>

#include <memory>
#include <sys/utsname.h>

namespace nocturne {
    std::unique_ptr<IPlatform> g_platform = std::make_unique<LinuxPlatform>();

    LinuxPlatform::LinuxPlatform() {

    }

    std::shared_ptr<IModule> LinuxPlatform::get_module() {
        return std::make_shared<LinuxModule>();
    }

    std::optional<std::string> LinuxPlatform::get_machine_name() {
        struct utsname uname_data;
        auto result = uname(&uname_data);
        if (result != 0) {
            return {};
        } else {
            return std::move(std::string{uname_data.machine});
        }
    }
}
