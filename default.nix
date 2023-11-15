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

  root = ./.;

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
    ${glslang}/bin/glslangValidator -V $root/shaders/simple_shader.vert -o simple_shader.vert.spv
    ${glslang}/bin/glslangValidator -V $root/shaders/simple_shader.frag -o simple_shader.frag.spv
    ${clang}/bin/clang++ $src/main.cpp $src/protocol_window.cpp $src/device.cpp $src/protocol_pipeline.cpp -lglfw -lvulkan -ldl -lpthread -o game
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv game $out/bin/3d_game
  '';
}
