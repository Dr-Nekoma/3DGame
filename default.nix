{ lib, stdenv, clang-tools, llvmPackages_latest,
  vulkan-headers, 
  vulkan-loader,
  glm,
  glslang,
  glfw,
  clang }:

stdenv.mkDerivation rec {
  name = "3d_game";

  src = ./src;

  buildInputs =
    [ clang-tools
      llvmPackages_latest.libstdcxxClang
      llvmPackages_latest.libcxx
      vulkan-headers
      vulkan-loader
      glm
      glslang
      glfw
      clang ];

  dontConfigure = true;

  buildPhase = ''
    ${clang}/bin/clang++ $src/main.cpp $src/lve_window.cpp $src/lve_pipeline.cpp -lglfw -lvulkan -ldl -lpthread -o game
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv game $out/bin/3d_game
  '';
}
