FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    hping3 \
    iproute2 \
    iputils-ping \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
# COPY attack.sh .
# RUN chmod +x attack.sh

# 기본 대기 상태
CMD ["bash"]
