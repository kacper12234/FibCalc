FROM alpine AS buildstage
RUN apk add --no-cache gcc libc-dev make
COPY fibcalc.c .
COPY BigInt.c .
COPY BigInt.h .
COPY makefile .
RUN make

FROM alpine
COPY --from=buildstage fibcalc .
CMD ["./fibcalc"]
