{ lib, stdenv, clang-tools, llvmPackages_latest, libGL, libGLU, glew, freeglut }:

stdenv.mkDerivation rec {
  name = "3d_game";

  src = ./src;

  buildInputs = [ clang-tools llvmPackages_latest.libstdcxxClang llvmPackages_latest.libcxx libGL libGLU glew freeglut ];

  dontConfigure = true;

  buildPhase = ''
    $CC -L${libGL}/lib -L${libGLU}/lib -L/nix/store/88z6jp04l9pnhcyvvppai4ll9svvs0nj-glew-2.2.0/lib -L${freeglut}/lib main.cpp -lGL -lGLU -lglut -lGLEW -o game
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv game $out/bin/3d_game
  '';
}
