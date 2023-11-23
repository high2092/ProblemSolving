function solution(dartResult) {
  const rounds = split(dartResult);
  const scores = rounds.map(() => 0);

  for (let i = 0; i < rounds.length; i++) {
    calculate({ roundIndex: i, scoreString: rounds[i], scores });
  }

  return scores.reduce((acc, cur) => acc + cur, 0);
}

const regex = /([0-9]|10)[SDT][*#]?/g;

function split(dartResult) {
  let match;
  const result = [];

  while ((match = regex.exec(dartResult)) !== null) {
    result.push(match[0]);
  }

  return result;
}

function calculate({ roundIndex, scoreString, scores }) {
  let score = parseInt(scoreString);

  const bonusIndex = score === 10 ? 2 : 1;
  const bonus = scoreString[bonusIndex];

  switch (bonus) {
    case 'D': {
      score *= score;
      break;
    }
    case 'T': {
      score *= score * score;
      break;
    }
  }

  const option = scoreString[bonusIndex + 1];

  switch (option) {
    case '*': {
      score *= 2;
      if (roundIndex >= 1) scores[roundIndex - 1] *= 2;
      break;
    }
    case '#': {
      score *= -1;
      break;
    }
  }

  scores[roundIndex] = score;
}
