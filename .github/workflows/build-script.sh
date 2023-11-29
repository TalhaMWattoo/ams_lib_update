#!/bin/bash

# Full path to the Xcode project
PROJECT_PATH="${GITHUB_WORKSPACE}/C++Extension/Projects/xCode/ams_lib.xcodeproj"

# Specify the architecture for M1 Mac (arm64)
ARCH="arm64"

# Set the macOS deployment target
DEPLOYMENT_TARGET="12.0"

# Disable code signing
CODE_SIGN_IDENTITY="-"
CODE_SIGN_STYLE="Manual"
CODE_SIGN_REQUIRED=NO
CODE_SIGNING_ALLOWED=NO

# Disable manual target order build warning
DISABLE_MANUAL_TARGET_ORDER_BUILD_WARNING=YES

# Building the project
xcodebuild \
  -project "$PROJECT_PATH" \
  -configuration Release \
  -sdk macosx \
  ARCHS="$ARCH" \
  MACOSX_DEPLOYMENT_TARGET="$DEPLOYMENT_TARGET" \
  CODE_SIGN_IDENTITY="$CODE_SIGN_IDENTITY" \
  CODE_SIGN_STYLE="$CODE_SIGN_STYLE" \
  CODE_SIGN_REQUIRED="$CODE_SIGN_REQUIRED" \
  CODE_SIGNING_ALLOWED="$CODE_SIGNING_ALLOWED" \
  DISABLE_MANUAL_TARGET_ORDER_BUILD_WARNING="$DISABLE_MANUAL_TARGET_ORDER_BUILD_WARNING"
