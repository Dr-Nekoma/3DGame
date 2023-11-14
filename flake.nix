{
  description = "3D Game";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    flake-utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs = { flake-utils, nixpkgs, self, ... }:
    # Add the system/architecture you would like to support here.
    flake-utils.lib.eachSystem [
      "x86_64-linux"
      "i686-linux"
      "aarch64-linux"
      # "x86_64-darwin"
      "aarch64-darwin"
    ] (system: 
      let
        pkgs = import nixpkgs { inherit config overlays system; };
        packageName = "3d_game";
        config = {};
        overlays = [];
      in {

        devShell = pkgs.mkShell {
          buildInputs = with pkgs; [
            # gcc
            # Headers not found
            clang-tools
            # LSP std
            llvmPackages_latest.libstdcxxClang
            # stdlib for cpp
            llvmPackages_latest.libcxx
            vulkan-headers
            vulkan-loader
            glm
            glslang
            glfw
            clang
          ];
        };
        defaultPackage = pkgs.callPackage ./default.nix {};
      });
}
