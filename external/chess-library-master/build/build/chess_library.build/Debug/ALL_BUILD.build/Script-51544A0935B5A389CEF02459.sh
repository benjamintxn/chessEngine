#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bentan/chessEngine/external/chess-library-master/build
  echo Build\ all\ projects
fi

