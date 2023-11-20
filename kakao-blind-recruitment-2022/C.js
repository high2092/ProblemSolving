function solution(fees, records) {
  var answer = [];

  const [baseTime, baseCost, unitTime, unitCost] = fees;

  const parkingCars = {};
  const durations = {};

  for (const record of records) {
    const [timeStr, carNum, type] = record.split(' ');
    const time = convertTime(timeStr);

    switch (type) {
      case 'IN': {
        parkingCars[carNum] = time;
        break;
      }
      case 'OUT': {
        const duration = time - parkingCars[carNum];
        durations[carNum] ??= 0;
        durations[carNum] += duration;
        delete parkingCars[carNum];
        break;
      }
    }
  }

  Object.entries(parkingCars).forEach(([carNum, parkingStartTime]) => {
    const duration = convertTime('23:59') - parkingStartTime;
    durations[carNum] ??= 0;
    durations[carNum] += duration;
  });

  answer = Object.entries(durations)
    .sort((a, b) => (a > b ? 1 : -1))
    .map(([carNum, duration]) => calculateCost({ baseTime, baseCost, unitTime, unitCost, duration }));

  return answer;
}

function convertTime(timeStr) {
  const [h, m] = timeStr.split(':').map(Number);
  return h * 60 + m;
}

function calculateCost({ baseTime, baseCost, unitTime, unitCost, duration }) {
  return baseCost + (duration <= baseTime ? 0 : Math.ceil((duration - baseTime) / unitTime) * unitCost);
}
