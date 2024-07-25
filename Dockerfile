# Use an official C++ image as a base
FROM gcc:8.3.0

# Set the working directory in the container
WORKDIR /app

# Copy the source code into the container
COPY . /app

# Compile the C++ program
RUN g++ -o biArray biArray.cpp ./include/arrayUtils.cpp

# Run the program when the container starts
CMD ["./biArray"]