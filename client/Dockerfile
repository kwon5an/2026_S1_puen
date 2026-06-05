# 빌드 환경
FROM ubuntu:22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y g++ libboost-all-dev

WORKDIR /app
COPY src/ ./src/

# client/src/main.cpp 컴파일
RUN g++ -O2 -Wall src/main.cpp -o game_client -lpthread

# 실행 환경
FROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/game_client .
CMD ["./game_client"]
