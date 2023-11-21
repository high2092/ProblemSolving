let diff = 0;
let result = [-1];
const _info = Array.from({ length: 11 }, () => 0);

function solution(n, info) {
  const dfs = createDfs(info);
  dfs(n, 0);
  return result;
}

function createDfs(info) {
  return function dfs(n, k) {
    if (n === 0) {
      judgeRyanWin({ apeach: info, ryan: _info });
      return;
    }

    if (k === 10) {
      _info[k] = n;
      dfs(0, k + 1);
    } else {
      for (let i = 0; i <= n; i++) {
        _info[k] = i;
        dfs(n - i, k + 1);
      }
    }
    _info[k] = 0;
  };
}

function judgeRyanWin({ apeach, ryan }) {
  let apeachScore = 0;
  let ryanScore = 0;
  for (let i = 0; i <= 10; i++) {
    const score = 10 - i;
    if (apeach[i] >= ryan[i]) {
      if (apeach[i] === 0) continue;
      apeachScore += score;
    } else {
      ryanScore += score;
    }
  }

  const _diff = ryanScore - apeachScore;

  if (_diff > diff || (_diff && _diff === diff && sort(ryan, result) > 0)) {
    diff = _diff;
    result = [...ryan];
  }
}

function sort(info1, info2) {
  for (let i = 10; i >= 0; i--) {
    if (info1[i] > info2[i]) {
      return 1;
    } else if (info2[i] > info1[i]) {
      return -1;
    }
  }

  return 0;
}
