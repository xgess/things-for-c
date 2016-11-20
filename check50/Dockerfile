FROM gliderlabs/alpine:3.2
MAINTAINER Alex Gessner <alex.gessner@gmail.com>
# shamelessly composed from https://github.com/nowk/cs50
# seriously big thanks to Yung Hwa Kwon <yung.kwon@damncarousel.com>

ENV ALPINE_VERSION 3.2
ENV GCC_VERSION 4.9.2

RUN apk --update add \
    openresolv \
    && rm -rf /var/cache/apk/*

RUN apk --update add \
	gcc=${GCC_VERSION}-r6 \
	libc-dev \
	make \
	&& rm -rf /var/cache/apk/*

LABEL \
	os="linux" \
	arch="amd64"

# install dependencies for the cs50 tools check50 and style50
RUN apk --update add \
	git \
	nodejs \
	openjdk7-jre-base \
	&& rm -rf /var/cache/apk/*

# install 50s
COPY install-50s /opt/
RUN /opt/install-50s && rm /opt/install-50s

# create a user so we are not root
RUN adduser -D -u 1001 -g '' cs50 \
	&& mkdir -p /src \
	&& chown -R cs50:cs50 /src

COPY docker-entrypoint /
ENTRYPOINT [ "/docker-entrypoint" ]

USER cs50
WORKDIR /src

# /src is the source code volume mountpoint
VOLUME /src

