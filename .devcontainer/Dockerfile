FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"


RUN apt update && apt install -y build-essential cmake git pkg-config mesa-utils x11-apps

COPY InstallDeps.sh /usr/local/bin/InstallDeps.sh
RUN chmod +x /usr/local/bin/InstallDeps.sh
RUN bash /usr/local/bin/InstallDeps.sh
# 
# COPY Boost.sh /usr/local/bin/Boost.sh
# RUN chmod +x /usr/local/bin/Boost.sh
# RUN bash /usr/local/bin/Boost.sh
# 
# COPY PortAudio.sh /usr/local/bin/PortAudio.sh
# RUN chmod +x /usr/local/bin/PortAudio.sh
# RUN bash /usr/local/bin/PortAudio.sh
# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
