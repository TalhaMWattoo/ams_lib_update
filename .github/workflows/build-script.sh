#!/bin/bash

# Full path to the Xcode project
PROJECT_PATH="${GITHUB_WORKSPACE}/C++Extension/Projects/xCode/ams_lib.xcodeproj"

# Scheme name - replace 'YourScheme' with your actual scheme name if you know it
SCHEME="YourScheme"

# Specify the architecture for M1 Mac (arm64)
ARCH="arm64"

# Set the macOS deployment target
DEPLOYMENT_TARGET="12.0"

# Disable code signing
CODE_SIGN_IDENTITY=""
CODE_SIGN_REQUIRED=NO

# Building the project
xcodebuild \
  -project "$PROJECT_PATH" \
  -scheme "$SCHEME" \
  -configuration Release \
  -sdk macosx \
  ARCHS="$ARCH" \
  MACOSX_DEPLOYMENT_TARGET="$DEPLOYMENT_TARGET" \
  CODE_SIGN_IDENTITY="$CODE_SIGN_IDENTITY" \
  CODE_SIGN_REQUIRED="$CODE_SIGN_REQUIRED"
