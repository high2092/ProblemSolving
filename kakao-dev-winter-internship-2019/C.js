function solution(stones, k) {
  const check = (n) => {
    let 불안정_길이 = 0;
    for (const stone of stones) {
      if (stone < n) {
        불안정_길이++;
      } else {
        불안정_길이 = 0;
      }

      if (불안정_길이 === k) return 1;
    }

    return 0; // 결정 문제: n명이 건너는 것을 감당하지 못하는 구간이 존재하는가? -> T/F
  };

  let [lo, hi] = [0, 2e8];
  while (lo + 1 < hi) {
    let mid = Math.floor((lo + hi) / 2);

    if (check(mid)) hi = mid;
    else lo = mid;
  }

  return lo; // 마지막 F를 찾자
}
