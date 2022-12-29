FROM alpine AS buildstage
RUN apk add --no-cache gcc libc-dev make
COPY fibcalc.c .
COPY BigInt.c .
COPY BigInt.h .
COPY makefile .
RUN make

FROM scratch
COPY --from=buildstage fibcalc /
COPY --from=buildstage /lib/ld-musl* /lib/
COPY --from=buildstage /lib/libc.musl* /lib/
CMD ["/fibcalc"]
