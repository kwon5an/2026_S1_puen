FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y g++ libboost-all-dev
RUN apt-get update && apt-get install -y \
    hping3 \
    iproute2 \
    iputils-ping \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY src/ ./src/
RUN g++ -O2 -Wall src/attack.cpp -o attack -lpthread -lboost_system 

CMD ["bash"]
