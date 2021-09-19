{ pkgs ? import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/8808f27a6baee4c12478a96bcb087beaaed43972.tar.gz") {}, lib ? pkgs.lib}:
pkgs.stdenv.mkDerivation rec {
  name = "skipper";
  src = ./src;

  nativeBuildInputs = [ pkgs.gcc ];

  buildPhase = ''find .; gcc skipper.c -o skipper'';
  installPhase = ''mkdir -p $out/bin;
    mv skipper $out/bin/;
    '';
}
