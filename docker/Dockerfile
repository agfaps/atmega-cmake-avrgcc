# Use alpine image so it will be lightweight
FROM alpine:latest

# Install required packages
RUN apk add --no-cache \
    avr-libc \
    avrdude \
    gcc-avr \
    build-base \
    make \
    cmake \
    git \
    bash

# Set the working directory inside the containter
WORKDIR /project

# Copy project files into the container (useful if building the image in pipeline with the latest sources so no need to mount)
# COPY . .

# Copy entrypoint.sh correctly from the docker folder
COPY docker/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Set entrypoint script
ENTRYPOINT ["/entrypoint.sh"]