FROM alpine
COPY fibcalc.c .
COPY BigInt.c .
COPY BigInt.h .
COPY makefile .
RUN apk add --no-cache gcc libc-dev make
RUN make
CMD ["/fibCalc"]
