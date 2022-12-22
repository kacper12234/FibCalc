FROM alpine
COPY fibcalc.c .
RUN apk add --no-cache gcc libc-dev
RUN gcc -o fibCalc fibcalc.c
CMD ["/fibCalc"]
