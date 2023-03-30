/**
 * JavaScript 표준 함수를 잘 활용하자
 */

function solution(s) {
  return JSON.parse(s.replace(/{/g, '[').replace(/}/g, ']'))
    .sort((a, b) => a.length - b.length)
    .reduce((acc, cur) => {
      acc.push(cur.find((el) => !acc.includes(el)));
      return acc;
    }, []);
}
