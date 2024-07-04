{
  lib,
  stdenv,
  cmake,
  hpp-util,
}:

stdenv.mkDerivation {
  pname = "hpp-statistics";
  version = "5.0.0";

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

  strictDeps = true;

  nativeBuildInputs = [ cmake ];
  propagatedBuildInputs = [ hpp-util ];

  doCheck = true;

  meta = {
    description = "Classes for doing statistics";
    homepage = "https://github.com/humanoid-path-planner/hpp-statistics";
    license = lib.licenses.bsd2;
    maintainers = [ lib.maintainers.nim65s ];
  };
}
