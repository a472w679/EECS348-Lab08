# Set the base image to use
FROM gcc:latest

# Copy the C program into the container
COPY problem02/problem02.c .

# Compile the C program
RUN gcc -o problem02 problem02.c

# Set the command to run when the container starts
CMD ["./problem02"]
