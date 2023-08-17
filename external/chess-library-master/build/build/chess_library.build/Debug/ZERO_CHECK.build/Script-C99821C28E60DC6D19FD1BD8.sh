#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  make -f /Users/bentan/chessEngine/external/chess-library-master/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  make -f /Users/bentan/chessEngine/external/chess-library-master/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  make -f /Users/bentan/chessEngine/external/chess-library-master/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  make -f /Users/bentan/chessEngine/external/chess-library-master/build/CMakeScripts/ReRunCMake.make
fi

