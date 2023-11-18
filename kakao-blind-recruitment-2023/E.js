class Cell {
  value;
  merge;
}

const table = Array.from({ length: 51 }, () => Array.from({ length: 51 }).map(() => new Cell()));

function solution(commands) {
  const answer = [];

  for (const command of commands) {
    const [cmd, arg1, arg2, arg3, arg4] = command.split(' ');

    switch (cmd) {
      case 'UPDATE': {
        if (arg3) {
          const { r, c } = getRef(arg1, arg2);
          const value = arg3;
          table[r][c].value = value;
        } else {
          const [value1, value2] = [arg1, arg2];
          for (const row of table) {
            for (const cell of row) {
              if (cell.value === value1) cell.value = value2;
            }
          }
        }

        break;
      }

      case 'MERGE': {
        const { r: r1, c: c1 } = getRef(arg1, arg2);
        const { r: r2, c: c2 } = getRef(arg3, arg4);

        if (r1 == r2 && c1 == c2) break;

        table[r1][c1].value ??= table[r2][c2].value;
        table[r2][c2].merge = { r: r1, c: c1 };

        break;
      }

      case 'UNMERGE': {
        const [pureR, pureC] = [arg1, arg2].map(Number);
        const { r, c } = getRef(arg1, arg2);

        const value = table[r][c].value;

        const targets = [];

        for (let i = 0; i < table.length; i++) {
          const row = table[i];
          for (let j = 0; j < row.length; j++) {
            const cell = row[j];
            const { r: _r, c: _c } = cell.merge ? getRef(cell.merge.r, cell.merge.c) : {};
            if ((i === r && j === c) || (_r === r && _c === c)) {
              targets.push({ r: i, c: j });
            }
          }
        }

        targets.forEach(({ r, c }) => {
          delete table[r][c].value;
          delete table[r][c].merge;
        });

        table[pureR][pureC].value = value;

        break;
      }

      case 'PRINT': {
        const { r, c } = getRef(arg1, arg2);
        answer.push(table[r][c].value ?? 'EMPTY');

        break;
      }
    }

    // console.log(command.split(' '));
    // for (let i = 0; i < table.length; i++) {
    //     const row = table[i];
    //     for (let j = 0; j < row.length; j++) {
    //         const cell = row[j];
    //         if (cell.value || cell.merge) {
    //             console.log(i, j, cell);
    //         }
    //     }
    // }
    // console.log();
  }

  return answer;
}

function getRef(r, c) {
  if (!table[r][c].merge) return { r: Number(r), c: Number(c) };
  return getRef(table[r][c].merge.r, table[r][c].merge.c);
}
