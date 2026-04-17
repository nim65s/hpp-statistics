{
  description = "Classes for doing statistics";

  inputs.gepetto.url = "github:gepetto/nix";

  outputs =
    inputs:
    inputs.gepetto.lib.mkFlakoboros inputs (
      { lib, ... }:
      {
        overrideAttrs.hpp-statistics = {
          src = lib.fileset.toSource {
            root = ./.;
            fileset = lib.fileset.unions [
              ./CMakeLists.txt
              ./doc
              ./include
              ./package.xml
              ./src
              ./tests
            ];
          };
        };
      }
    );
}
