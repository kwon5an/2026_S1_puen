# 빌드
FROM ubuntu:22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y g++ cmake make libboost-system-dev

WORKDIR /app
COPY src/ ./src/

# CMakeLists.txt가 있는 위치에서 빌드 진행
RUN cd src && mkdir build && cd build && cmake .. && make

# 실행 (최종 실행 파일만 관리)
FROM ubuntu:22.04
RUN apt-get update && apt-get install -y iptables iproute2 htop sysstat && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /app/src/build/fortress_server .

EXPOSE 9000/udp
CMD ["./fortress_server"]
