FROM alpine
RUN apk add --no-cache git openssh-client gcc libc-dev
RUN mkdir -p -m 0600 ~/.ssh && ssh-keyscan github.com >> ~/.ssh/known_hosts
RUN --mount=type=ssh git clone git@github.com:kacper12234/FibCalc.git
RUN gcc -o fibCalc FibCalc/fibcalc.c
CMD ["/fibCalc"]