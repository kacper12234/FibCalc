FROM gcc AS buildstage
COPY fibcalc.c .
COPY BigInt.c .
COPY BigInt.h .
COPY makefile .
RUN make

FROM alpine
COPY --from=buildstage fibcalc .
CMD ["./fibcalc"]
