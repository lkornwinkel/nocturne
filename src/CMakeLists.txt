
list(APPEND LINUX_SRCS linux/linux_module.cpp linux/linux_platform.cpp)

list(APPEND COMMON_SRCS main.cpp plugin.cpp host.cpp vst3/vst3_host_context.cpp)
list(APPEND COMMON_INCS ../include/nocturne/host.hpp ../include/nocturne/imodule.hpp ../include/nocturne/iplatform.hpp ../include/nocturne/vst3/vst3_host_context.hpp)

list(APPEND SRCS ${COMMON_SRCS} ${COMMON_INCS})

if (${PLATFORM_LINUX})
    list(APPEND SRCS ${LINUX_SRCS})
endif ()

message(DEBUG ${SRCS})
add_executable(nocturne main.cpp ${SRCS} linux/linux_module.cpp linux/linux_platform.cpp
        ../include/nocturne/plog_headers.hpp
        ../include/nocturne/nocturne.hpp
        ../include/nocturne/vst3/vst3_headers.hpp
        ../include/nocturne/linux/linux_module.hpp
        ../include/nocturne/linux/linux_platform.hpp
        ../include/nocturne/vst3/vst3_plug_view.hpp
        vst3/vst3_plug_view.cpp)
target_link_libraries(nocturne PUBLIC Qt6::Widgets Qt6::Gui plog::plog base pluginterfaces sdk sdk_common sdk_hosting)