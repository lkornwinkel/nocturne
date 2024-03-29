
set(LINUX_SRCS linux/linux_module.cpp linux/linux_platform.cpp
        ../include/nocturne/vst3/vst3_host_context.hpp
        vst3/vst3_host_context.cpp)

set(COMMON_SRCS main.cpp plugin.cpp host.cpp)
set(COMMON_INCS ../include/nocturne/host.hpp ../include/nocturne/imodule.hpp ../include/nocturne/iplatform.hpp)

list(APPEND ${SRCS} ${COMMON_SRCS} ${COMMON_INCS})

if (${PLATFORM_LINUX})
    list(APPEND ${SRCS} ${LINUX_SRCS})
endif ()

add_executable(nocturne main.cpp ${SRCS} ${LINUX_SRCS}
        ../include/nocturne/plog_headers.hpp
        ../include/nocturne/nocturne.hpp
        ../include/nocturne/vst3/vst3_headers.hpp
        ../include/nocturne/linux/linux_module.hpp
        ../include/nocturne/linux/linux_platform.hpp)
target_link_libraries(nocturne PUBLIC plog::plog base pluginterfaces sdk sdk_common sdk_hosting)