# Pull base image
FROM gcc:latest

# Set working directory
WORKDIR /app

# Add source files
ADD . /app

# Compile
RUN g++ -o connectfour connectfour.cpp board.cpp

# Run the application
CMD ["./connectfour"]
