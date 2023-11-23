function solution(n, t, m, timetable) {
  const sorted = timetable.map(convert).sort((a, b) => a - b);

  const extra = [];
  let k = 0;
  let curr = NINE_O_CLOCK;

  for (let i = 0; i < n; i++) {
    let _k = k;
    while (sorted[k] <= curr && k - _k < m) {
      k++;
    }
    if (k - _k < m) extra.push(curr);

    curr += t;
  }

  const lastChance = getLastChance({ extra, sorted, k, firstBus: NINE_O_CLOCK, lastBus: curr - t });
  return convertToString(lastChance);
}

function getLastChance({ extra, sorted, k, lastBus }) {
  if (extra.length === 0) return sorted[k - 1] - 1;
  if (k === 0) return lastBus;
  return Math.max(extra[extra.length - 1], Math.min(lastBus, sorted[k - 1] - 1)); // 중간에 빈 자리 낭비하고 마지막으로 탐..
}

function convert(timeString) {
  const [h, m] = timeString.split(':').map(Number);
  return 60 * h + m;
}

function convertToString(time) {
  const h = Math.floor(time / 60).toString();
  const m = Math.floor(time % 60).toString();
  return `${h.padStart(2, '0')}:${m.padStart(2, '0')}`;
}

const NINE_O_CLOCK = convert('09:00');
