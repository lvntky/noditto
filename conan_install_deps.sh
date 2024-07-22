#!/bin/bash

# Install Conan dependencies
conan install . --output-folder=build --build=missing
