---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp
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
  code: "#ifndef BAKATAN_DSU_HPP\n#define BAKATAN_DSU_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace BAKATAN {\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp\n\
    \nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    explicit dsu(int n) : _n(n),\
    \ parent_or_size(n, -1) {}\n\n    int merge(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        return x;\n    }\n\n    bool same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n    }\n\n\
    \    int size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace BAKATAN\n\
    \n#endif  // BAKATAN_DSU_HPP"
  dependsOn: []
  isVerificationFile: false
  path: BAKATAN-Library/data structure/dsu.hpp
  requiredBy: []
  timestamp: '2023-06-20 13:33:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BAKATAN-Library/data structure/dsu.hpp
layout: document
redirect_from:
- /library/BAKATAN-Library/data structure/dsu.hpp
- /library/BAKATAN-Library/data structure/dsu.hpp.html
title: BAKATAN-Library/data structure/dsu.hpp
---
