#ifndef NOCTURNE_LINUX_PLATFORM_HPP
#define NOCTURNE_LINUX_PLATFORM_HPP

#include <nocturne/iplatform.hpp>

#include <memory>

namespace nocturne {

    class LinuxPlatform : public IPlatform {
    private:
    public:
        LinuxPlatform();
    
        [[nodiscard]] std::optional<std::string> get_machine_name() override;

        [[nodiscard]] std::shared_ptr<IModule> get_module() override;
    };
}

#endif //NOCTURNE_LINUX_PLATFORM_HPP
