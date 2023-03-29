FROM ubuntu:latest

RUN apt-get update && apt-get install -y genisoimage

RUN mkdir -p /app
COPY variant2.sh /app/

CMD ["/app/variant2.sh"]