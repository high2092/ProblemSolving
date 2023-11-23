function solution(str1, str2) {
  const A = {};
  const B = {};
  const union = {};
  const inter = {};

  for (const sub of cut(str1)) {
    A[sub] ??= 0;
    A[sub]++;
    union[sub] = A[sub];
  }

  for (const sub of cut(str2)) {
    B[sub] ??= 0;
    B[sub]++;
    if (A[sub]) inter[sub] = Math.min(A[sub], B[sub]);
    union[sub] = Math.max(A[sub] ?? 0, B[sub]);
  }

  const interCount = sum(inter);
  const unionCount = sum(union);

  return Math.floor(65536 * (unionCount === 0 ? 1 : interCount / unionCount));
}

const sum = (obj) => Object.values(obj).reduce((acc, cur) => acc + cur, 0);

const regex = /^[a-zA-Z]+$/;

function cut(str) {
  const result = [];
  for (let i = 0; i < str.length - 1; i++) {
    const substr = str.substr(i, 2);
    if (regex.test(substr)) {
      result.push(substr.toLowerCase());
    }
  }

  return result;
}
