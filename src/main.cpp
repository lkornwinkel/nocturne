#include <nocturne/host.hpp>
#include <nocturne/plugin.hpp>
#include <nocturne/plog_headers.hpp>
#include <nocturne/iplatform.hpp>
#include <nocturne/imodule.hpp>
#include <nocturne/linux/linux_module.hpp>
#include <iostream>


int main(int argc, char **argv) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);

    PLOG(plog::debug) << "nocturne starting";

    nocturne::Plugin plugin{};
    auto module = nocturne::LinuxModule{};
//    nocturne::Host host;
//    bool loaded = plugin.load(host, "/home/lars/.vst3/u-he/Podolski.vst3");
    bool loaded = module.load("/home/lars/.vst3/u-he/Podolski.vst3");
    std::cout << loaded << std::endl;
    module.list_classes();

}
