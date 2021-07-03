# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.183.0/containers/alpine/.devcontainer/base.Dockerfile

# [Choice] Alpine version: 3.13, 3.12, 3.11, 3.10
ARG VARIANT="3.13"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-alpine-${VARIANT}

# Install cross compiler
RUN wget -O /tmp/musl.tgz https://musl.cc/armv7l-linux-musleabihf-cross.tgz \
  && tar xzf /tmp/musl.tgz armv7l-linux-musleabihf-cross -C /

# ** [Optional] Uncomment this section to install additional packages. **
RUN apk update \
    && apk add alpine-sdk build-base cmake
