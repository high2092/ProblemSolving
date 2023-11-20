function isPrime(n) {
  if (n < 2) return false;

  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (n % i == 0) return false;
  }

  return true;
}

function convert(n, k) {
  const stack = [];

  while (n) {
    stack.push(n % k);
    n = Math.floor(n / k);
  }

  let result = '';

  while (stack.length) {
    result += stack.pop();
  }

  return result;
}

function solution(n, k) {
  const splited = convert(n, k).split('0').map(Number);
  const filtered = splited.filter(isPrime);
  return filtered.length;
}
