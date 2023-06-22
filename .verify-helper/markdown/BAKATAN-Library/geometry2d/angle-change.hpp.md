---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/Users/kabatan/Library/Python/3.9/lib/python/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/Users/kabatan/Library/Python/3.9/lib/python/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/Users/kabatan/Library/Python/3.9/lib/python/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/Users/kabatan/Library/Python/3.9/lib/python/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/Users/kabatan/Library/Python/3.9/lib/python/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 185, in _get_uncommented_code\n    raise BundleError(f'A fake g++ is detected.\
    \ Please install the GNU C++ compiler.: {compiler}')\nonlinejudge_verify.languages.cplusplus_bundle.BundleError:\
    \ A fake g++ is detected. Please install the GNU C++ compiler.: g++\n"
  code: "#pragma once\n\n#define _USE_MATH_DEFINES \n#include <cmath>\n\nnamespace\
    \ BAKATAN {\n\ntemplate<typename T>\nT deg_to_rad(const T& degree) {return T(degree\
    \ * M_PI / 180.0);}\ntemplate<typename T> \nT rad_to_deg(const T& radian) {return\
    \ T(radian * 180.0 / M_PI);}\n\n} //namespace BAKATAN\n"
  dependsOn: []
  isVerificationFile: false
  path: BAKATAN-Library/geometry2d/angle-change.hpp
  requiredBy: []
  timestamp: '2023-06-20 13:02:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BAKATAN-Library/geometry2d/angle-change.hpp
layout: document
redirect_from:
- /library/BAKATAN-Library/geometry2d/angle-change.hpp
- /library/BAKATAN-Library/geometry2d/angle-change.hpp.html
title: BAKATAN-Library/geometry2d/angle-change.hpp
---
